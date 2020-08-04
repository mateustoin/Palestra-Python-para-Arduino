# -*- coding: iso-8859-1 -*-
import serial

# Abre porta Serial com seus devidos parâmetros
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)

# escreve uma string na porta serial
arduino.write(b'a')
#arduino.write(bytes('a', encoding='utf-8'))
#          
arduino.close() # Fecha porta de comunicação

