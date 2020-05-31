# -*- coding: iso-8859-1 -*-
import serial

ser = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)  # open serial port

while True:
    msg = ser.readline().decode('ascii')
    print(msg)