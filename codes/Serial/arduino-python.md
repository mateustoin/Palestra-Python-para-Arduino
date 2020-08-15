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

## Prática

```python
import serial

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)

while True:
    msg = input('Envie um comando: ')

    arduino.write(bytes(msg, encoding='utf-8'))

    retorno = arduino.readline().decode('ascii')
    print('Retorno: ' + retorno)
```