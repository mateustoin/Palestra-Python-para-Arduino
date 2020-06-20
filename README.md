<img src="img/imagens-palestra/1.png" style="height:300px, ">

# Python para Arduino ou Arduino para Python?

A ideia da apresentação é mostrar como é possível integrar Arduino e Python e o que dá pra fazer com isso! Com a diversidade de trabalhos que podem ser feitos com Arduino e a facilidade da linguagem de programação python, é possível desenvolver uma infinidade de projetos e protótipos com inúmeras funcionalidades interessantes. O objetivo é que com isso, seu leque de possibilidades aumente e seja acionado um gatilho, que dirá que muitas coisas que parecem complexas são possíveis e mais fáceis do que parece.

# Sumário
1. [Whoami](#whoami) 
1. [Introdução](#introd)
    - [Expectativas](#expectativa)
    - [Expectativas](#realidade)
    - [Porquê python?](#porque-python)
        - [Facilidades do Python](#facilidade-python1)
2. [Objetivo](#objetivo)
3. [O que preciso saber sobre Arduino para conectar no Python?](#sobre-arduino)
4. [O que preciso saber sobre Python para conectar no Arduino?](#sobre-python)
5. [Códigos, Aplicações e Utilitários](#aplicacao)

<a href="https://www.instagram.com/matteus_antonio/">
    <img id="whoami" src="img/imagens-palestra/2.png" style="height:300px, ">
</a>

<p>
    Minha jornada se iniciou depois que entrei na Universidade, no curso de Engenharia da Computação. Já tinha um background técnico, com um pouco de prática em robótica e programação, porém nada extraordinário e diferente do que se encontra nos tutoriais básicos da web. Com uma ideia de que iria trabalhar bastante com robótica, programação, participar de competições e desenvolver projetos, cheguei muito empolgado e com vontade de aprender. O problema é que não existiam grupos de estudo, laboratórios abertos para ensinar e muitas pessoas interessadas em ensinar. Além disso, as disciplinas exigiam esse conhecimento, para criação de projetos e pôr em prática diversos conteúdos do curso que estão envolvidos com essas práticas.
</p>

<p>
    Por isso depois que surgiu uma oportunidade de iniciar um Grupo de estudos em Robótica junto ao IEEE, entrei para o time junto com alguns amigos e passamos a ser os responsáveis por criar essa cultura ali dentro. Os anos se passaram e hoje temos diversas pessoas trabalhando no projeto juntos, como uma comunidade, que colabora com todos espalhando conhecimento e aprendendo muito no processo.
</p>

<p>
    Além desse projeto, também sou responsável por uma loja de componentes eletrônicos, o <a href="becodaeletronica.com">Beco da Eletrônica</a>, que funciona localmente no Centro de Informática da UFPB, oferecendo materiais para que todos tenham acesso e possam realizar diversos projetos. 
</p>

> ## Contato
> - Email: mateus.antonio@eng.ci.ufpb.br
> - Instagram: <a href="instagram.com/matteus_antonio">@matteus_antonio</a>

<img id="introd" src="img/imagens-palestra/4.png" style="height:300px, ">

<p>
    Esse documento é baseado em uma palestra que foi realizada pela primeira vez no evento online <b>RAS WEEK</b>, com foco em temas de robótica, saúde e tecnologia no geral. Nele serão apresentados duas tecnologias bastante utilizadas no ambiente educacional: Arduino e Python. O Arduino é uma plataforma de criação de protótipos bastante conhecida, utilizada com sensores e atuadores para realizar projetos com potencial para virarem produto no mercado. Comumente utilizado para validação de ideias, é aplicado em projetos de pesquisa, extensão, pesquisas e principalmente para ensino de robótica e automação nas escolas e universidades.
</p>

<p>
    Já o python é uma linguagem de programação considerada ideal para interessados por programação, em qualquer área de atuação ou idade, pois é simples e versátil. Não é necessário muito tempo para aprender o básico e possui diversas bibliotecas que fazem bastante trabalho por você, por isso se torna uma ferramenta poderosa e mostraremos como isso pode ser utilizado a nosso favor para a criação dos projetos com Arduino.
</p>

<img id="expectativa" src="img/imagens-palestra/5.png" style="height:300px, ">
<p>
    Muitos imaginam que já vão começar aprendendo desenvolvimento avançado, realizar funções complexas e desenvolver sistemas robustos, como um Jarvis da vida. Pra chegar nesse nível precisamos entender diversas coisas, o início do conhecimento, para que seja construída uma base sólida e só depois construir aplicações cada vez mais legais e cheias de funcionalidades.
</p> 

<img id="realidade" src="img/imagens-palestra/6.png" style="height:300px, ">

<p>
    Sem querer criar muitas expectativas, essa apresentação não vai preparar ninguém pra fazer o próximo homem de ferro. A abordagem aqui será um pouco superficial, mas será o suficiente pra despertar muita curiosidade. Veremos algumas implementações e aplicações que podem ser um ponta pé inicial para esse projeto (Jarvis)!
</p>

## Porquê Python? <a id="porque-python"></a>

<img id="facilidade-python1" src="img/imagens-palestra/7.png" style="height:300px, ">
<p>
    A facilidade para se aprender python é um fator muito importante para a escolha da linguagem, mas acima de tudo, a acessibilidade de informações e quantidade de materiais é indispensável. Hoje é possível encontrar ótimos cursos de python, do básico ao avançado, em algumas plataformas como o <i>Coursera</i>, <i>Youtube</i>, <i>Udemy</i>, entre muitos outros.
</p>

<p>
    Na figura acima podemos observar o curso de Python do renomado Gustavo Guanabara, que foi criado com o objetivo de iniciar as pessoas na programação a partir do 0. Além disso temos algumas opções na plataforma da Udemy, que se filtrar por cursos de python grátis, gera mais de 100 resultados. Ou seja, opções não faltam, basta procurar e começar!
</p>

<img id="facilidade-python2" src="img/imagens-palestra/8.png" style="height:300px, ">

<p>
    Para mostrar um exemplo prático, o código em python exibido acima é responsável por controlar um Dron! Alguns drones no mercado funcionam com aplicativos de celular ou controles mais simples, pois são de baixo custo e feito para iniciantes. Em alguns casos, como o dro drone mostrado (DJI Tello), a empresa disponibiliza um <i>SDK</i> (Software Development Kit, do inglês Kit de Desenvolvimento de Software). Com esse SDK podemos utilizar uma linguagem de programação para desenvolver o nosso próprio sistema de controle do dispositivo, nesse caso, o drone. 
</p>

```python
1: from djitellopy import Tello
```
<p>
    Na primeira linha do código podemos observar a importação da biblioteca Tello, responsável por controlar o drone. Nela contém o SDK, mencionado anteriormente, que possui tudo que é necessário para acionar as funcionalidades do quadricoptero.
</p>

```python
2: tello = Tello()
```
<p>
    Na segunda linha do código criamos uma variável que "armazenará" todas as funções que utilizaremos. Isso é comum e ocorre com a maioria das bibliotecas que utilizamos para fazer coisas no python. Com isso o <i>tello</i> ficará responsável por chamar o que chamamos de métodos (funções dentro da biblioteca que adiconamos).
</p>

```python
3: tello.connect()
```
<p>
    Na linha 3 o primeiro método é chamado, para conectar o computador que está executando o código ao drone. Depois que a conexão é estabelecida, já é possível enviar comandos, pois o drone irá "escutar".
</p>

```python
4: tello.takeoff()
```
<p>
    Depois de conectado, o primeiro comando é enviado, para levantar voo.
</p>

```python
5: tello.move_left(100)
```
<p>
    Depois de ter o voo levantado, agora o drone é movido 100 centímetros para a esquerda.
</p>

```python
6: tello.rotate_counter_clockwise(45)
```
<p>
    Depois de mover os 100 centímetros, ele gira no sentido anti-horário 45°.
</p>

```python
7: tello.land()
```
<p>
    Depois de ter finalizado o giro, pousa no chão.
</p>

```python
8: tello.end()
```
<p>
    Depois de ter pousado, encerra a conexão do programa com o drone.
</p>

<p>
    Os códigos foram exibidos e explicados para mostrar como é simples a cadeia de comandos que você pode fazer no python para realizar uma tarefa. Se com drones é possível ter um controle tão simples, quem dirá funcionalidades que podemos implementar no python, como reconhecimento de voz, entre outros. Como dito anteriormente, algumas coisas são mais simples do que parece e é isso que iremos explorar!
</p>

<img id="objetivo" src="img/imagens-palestra/9.png" style="height:300px, ">

# Sobre Arduino <a id="sobre-arduino"></a>

# Sobre Python <a id="sobre-python"></a>

# Códigos, Aplicações e Utilitários <a id="aplicacao"></a>