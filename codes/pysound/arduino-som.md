<p align="center">
<a href="https://github.com/mateustoin/Palestra-Python-para-Arduino/blob/master/codes/pysound/arduino-som.md">
  <img src="../../img/imagens-palestra/25.png" style="height:300px, "/>
</a>
</p>

`pip install pygame`

```python
import pygame
import time

file = 'aimless-old habits.mp3'
pygame.init()
pygame.mixer.init()
pygame.mixer.music.load(file)
pygame.mixer.music.play()

time.sleep(10)

pygame.mixer.music.stop()
```