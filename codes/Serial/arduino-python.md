<p align="center">
<a href="https://github.com/mateustoin/Palestra-Python-para-Arduino/blob/master/codes/Serial/arduino-python.md">
  <img src="../../img/imagens-palestra/22.png" style="height:300px, "/>
</a>
</p>

## Configuração

<p>
  Para o funcionamento dos códigos de comunicação serial no python, a instalação do pacote a seguir é necessária. Basta digitar no terminal com <i>python</i> e <i>pip</i> instalados:
</p>

`pip install pyserial`

## Prática Python

```python
# Importa biblioteca para acessar as portas Seriais
from serial import Serial

# Inicia conexão na porta em que o Arduino está plugado
arduino = Serial(port='COM4', baudrate=9600, timeout=1)

while True:
    # Espera mensagem do usuário
    msg = input('Envie um comando: ')

    # Envia mensagem do usuário
    arduino.write(bytes(msg, encoding='utf-8'))

    # Lê mensagem de retorno do Arduino e imprime na tela
    retorno = arduino.readline().decode('ascii')
    print('Retorno: ' + retorno)
```

## Prática Arduino

```cpp
#define led 13 // Porta onde o led está conectado

void setup(){
  Serial.begin(9600);   // Velocidade padrão para comunicação
  pinMode(led, OUTPUT); // Porta onde o led será acionado, configurado como saida
}

void loop(){
  if (Serial.available() > 0){
    char leitura = Serial.read();       // Variavel que receberá os valores enviados pelo programa em python
    
    if(leitura == 'l'){
      digitalWrite(led, HIGH);          // Liga a porta 13 se o valor recebido for 1
      Serial.println("Acionou led!");   // Envia mensagem para a porta Serial
    }
    
    if(leitura == 'd'){
      digitalWrite(led, LOW);           // Desliga a porta 13 se o valor recebido for 2
      Serial.println("Desligou led!");  // Envia mensagem para a porta Serial
    }
  }
}
```
