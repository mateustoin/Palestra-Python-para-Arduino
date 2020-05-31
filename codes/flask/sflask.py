#!/usr/bin/env python

# Importa pacotes para criação do servidor e manipulação dos dados
from flask import Flask, request, Response
import time
import pandas as pd

# Importa pacotes responsáveis por cuidar da interrupção quando o programa for fechado com 'Ctrl + C'
import signal
import sys
import threading

# Nome do arquivo que armazenará a coleta do SAC-DM
nomeArquivo = 'voo3'

# Cria thread que monitora o fechamento do programa com 'Ctrl + C'
# Quando programa for fechado, executa essa função:
def signal_handler(signal, frame):
    print('\n\nSalvando coleta de dados em {}.csv'.format(nomeArquivo))
    df.to_csv('{}.csv'.format(nomeArquivo))
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
forever = threading.Event()

# Cria DataFrame com as colunas referentes aos dados da coleta
df = pd.DataFrame(columns=['timestamp', 'Eixo X', 'Eixo Y', 'Eixo Z'])

app = Flask(__name__)

# Cria rota que a ESP8266 realizará o http.POST com os resultados do SAC-DM
@app.route('/pibic', methods=['POST',])
def pibic():
    #print(request.data)                                         # Printa os dados contidos no pacote enviado
    eixos = request.data.decode("utf-8")
    eixos = eixos.split('&') 
    print(eixos)
    timestamp = int(round(time.time() * 1000))         # Cria timestamp no momento que recebe os dados
    
    df.loc[len(df)] = [timestamp, eixos[0], eixos[1], eixos[2]] # Adiciona os novos valores em uma nova linha do DataFrame
    
    return Response(status=201)                                 # Se recebeu uma requisição POST do client, responde com status de sucesso

app.run(host='0.0.0.0', port= 5000, debug=False)                # Roda o servidor, verificar o IP da máquina (ifconfig/ipconfig) 
                                                                # para passar o IP para a ESP8266 acessar 
