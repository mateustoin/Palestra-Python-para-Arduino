<p align="center">
<a href="https://github.com/mateustoin/Palestra-Python-para-Arduino/blob/master/codes/Serial/arduino-python.md">
  <img src="../../img/imagens-palestra/22.png" style="height:300px, "/>
</a>
</p>

`pip install pyserial`

```python
import serial

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)

while True:
    msg = input('Envie um comando: ')

    arduino.write(bytes(msg, encoding='utf-8'))

    retorno = arduino.readline().decode('ascii')
    print('Retorno: ' + retorno)
```