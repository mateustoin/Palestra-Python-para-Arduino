# -*- coding: iso-8859-1 -*-
import serial

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)  # open serial port
arduino.write(b'a')                                  # escreve uma string
#arduino.write(bytes('a', encoding='utf-8'))         # escreve uma string
arduino.close()                                      # Fecha porta de comunicação