/**
 * +--------------------------------------------------------------+
 * |                                                              |
 * |     Caos Reading device                                      |
 * |                                                              |
 * |     Program created to read vibrations, make the analisys    |
 * |     and send to the server                                   |
 * |                                                              |
 * |                                                              |
 * +--------------------------------------------------------------+
 */

float threshold = 1.10;

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "mpuHelp.h"

// O IP da máquina pode ser obtido utilizando o comando 'ifconfig' no linux ou 'ipconfig' no Windows na própria máquina
// A porta é determinada no servidor Flask
// A rota é determinada no servidor Flask
const char* link = "http://10.42.0.1:5000/pibic";

mpuHelp mpu;
HTTPClient http;

#define WIFI_SSID "mateustoin_plus"
#define WIFI_PASSWORD "viOw7NZO"

//+--------------> Defines <--------------+

#define pinLed LED_BUILTIN
#define sampleSize 500

//+--------------> Variables <--------------+

long lastMsg = 0, loopTimer = 0;
int value = 0, readings = 0, peaks_x = 0, peaks_y = 0, peaks_z = 0;
s32 signals_x[3] = {0, 0, 0};
s32 signals_y[3] = {0, 0, 0};
s32 signals_z[3] = {0, 0, 0};
double rho_x, rho_y, rho_z;
s32 acc_x, acc_y, acc_z, temperature, gyro_x, gyro_y, gyro_z;
 
void setup () {
 
  Serial.begin(115200);
  while (!Serial);
  Serial.setDebugOutput(true);

  Wire.begin();  // Start I2C as master
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, HIGH);

  mpu.setup_mpu_6050_registers();

  delay(1000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Wifi connected: ");
  Serial.println(WiFi.localIP());
  
  digitalWrite(LED_BUILTIN, HIGH);
  loopTimer = micros();
}
 
void loop() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    //Serial.println("Entrando na função quando wifi esta conectado");
    http.begin(link);
    http.addHeader("Content-Type", "text/plain");
    
    //read_mpu_6050_data();
    mpu.read_mpu_6050_data();

    signals_x[0] = signals_x[1];
    signals_x[1] = signals_x[2];
    //signals_x[2] = acc_x;
    signals_x[2] = mpu.getACC_X();

    signals_y[0] = signals_y[1];
    signals_y[1] = signals_y[2];
    signals_y[2] = mpu.getACC_Y();

    signals_z[0] = signals_z[1];
    signals_z[1] = signals_z[2];
    signals_z[2] = mpu.getACC_Z();

    readings++;
    
    if (readings > 2) {
        if (signals_x[1] > signals_x[0]*threshold && signals_x[1] > signals_x[2]*threshold) peaks_x++;
        if (signals_y[1] > signals_y[0]*threshold && signals_y[1] > signals_y[2]*threshold) peaks_y++;
        if (signals_z[1] > signals_z[0]*threshold && signals_z[1] > signals_z[2]*threshold) peaks_z++;
    }
    if (readings == sampleSize) {
        rho_x = (float)peaks_x / (float)sampleSize;
        rho_y = (float)peaks_y / (float)sampleSize;
        rho_z = (float)peaks_z / (float)sampleSize;
         
        // Concatena os resultados do SAC-DM para enviar no método POST para o servidor Flask
        // Valores separados por '&', pois no python será dado um split
        String data = String(rho_x);
                data += "&";
                data += String(rho_y);
                data += "&";
                data += String(rho_z);
        
        // Realiza uma requisição POST no IP, Porta e Rota indicada no http.begin()
        int httpCode = http.POST(data);

        // Se a resposta for 201, o POST foi feito com sucesso
        Serial.println(httpCode);
        http.end();
      
        readings = 1;
        peaks_x = 0;
        peaks_y = 0;
        peaks_z = 0;
    }
    while (micros() - loopTimer < 1000) digitalWrite(LED_BUILTIN, LOW);
    loopTimer = micros();
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
