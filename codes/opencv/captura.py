import cv2                    # Importa biblioteca do opencv

cap = cv2.VideoCapture(1)     # Identifica a câmera do dispositivo 
ret,frame = cap.read()        # Retorna um único frame capturado da câmera

cv2.imwrite('test.png',frame) # Salva o frame capturado no arquivo test.png