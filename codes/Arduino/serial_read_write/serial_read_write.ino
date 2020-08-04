#define led 13 // Porta onde o led está conectado

void setup(){
  Serial.begin(9600);   // Velocidade padrão para comunicação
  pinMode(led, OUTPUT); // Porta onde o led será acionado, configurado como saida
}

void loop(){
  if (Serial.available() > 0){
    char leitura = Serial.read();       // Variavel que receberá os valores enviados pelo programa em python
    
    if(leitura == 'a'){
      digitalWrite(led, HIGH);          // Liga a porta 13 se o valor recebido for 1
      Serial.println("Acionou led!");   // Envia mensagem para a porta Serial
    }
    
    if(leitura == 'b'){
      digitalWrite(led, LOW);           // Desliga a porta 13 se o valor recebido for 2
      Serial.println("Desligou led!");  // Envia mensagem para a porta Serial
    }
  }
}
