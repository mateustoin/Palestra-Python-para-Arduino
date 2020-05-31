import serial

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)

while True:
    msg = input('Envie um comando: ')

    arduino.write(bytes(msg, encoding='utf-8'))

    retorno = arduino.readline().decode('ascii')
    print('Retorno: ' + retorno)