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
