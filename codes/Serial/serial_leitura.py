# -*- coding: iso-8859-1 -*-
import serial

# Abre porta Serial com seus devidos parâmetros
ser = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)  

# Lê repetidamente e imprime qualquer mensagem que vem do arduino
while True:
    msg = ser.readline().decode('ascii')
    print(msg)

