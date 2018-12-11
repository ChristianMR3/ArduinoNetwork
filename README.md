# ArduinoNetwork


Instituto tecnológico de león
Sistemas programables

Practica Final

Arduino Networking

Realizado por:
Christian Moreno Ramirez

Juan Pablo Barroso Hernández

-Materiales: 🔧
 -1 Protoboard.
 -1 Arduino UNO (o cualquier otro).
 -2 DTH11.
 -2 resistencias (330 ohms).
 -1 LED
 -1 ESP8266 
 -1 regulador de voltaje(ya que el ESP8266 trabaja solo con 3.66v).

Requisitos
Programas necesarios📋
 -El Arduino IDE el cual se puede descargar de la pagina oficial: Pagina de Arduino
 -Los materiales descritos prebiamente
 -una cuenta en https://ifttt.com
 -una cuenta en https://io.adafruit.com

Descripcion del Proyecto

Primero debemos crear una cuenta en [Adafruit](https://io.adafruit.com/)
![adafruit1](https://user-images.githubusercontent.com/44387203/49811398-d0e52f00-fd28-11e8-9b86-68a348bd5055.png)

Enseguida le damos link en la parte de Feeds>Actions>Create A New Feeds
En nuestro caso creamos test1
![adafruit2](https://user-images.githubusercontent.com/44387203/49811542-1e619c00-fd29-11e8-84d5-3e9f642811ba.png)

Debemos crear una cuenta en [IFTTT](https://ifttt.com/discover)
![ifttt](https://user-images.githubusercontent.com/44387203/49811732-7ac4bb80-fd29-11e8-84d3-63956b7d6193.png)

Creamos una nueva aplicación, en este caso vamos a mostrar de ejemplo para encender las luces
![ifttt3](https://user-images.githubusercontent.com/44387203/49811781-94fe9980-fd29-11e8-881d-d1523937b7f1.png)

Buscamos Google assistant y lo seleccionamos
![ifttt4](https://user-images.githubusercontent.com/44387203/49811805-a051c500-fd29-11e8-98cb-126f5b16cb89.png)

Le decimos los datos que solicita
![ifttt5](https://user-images.githubusercontent.com/44387203/49811827-acd61d80-fd29-11e8-99e4-b97919356cdb.png)

Buscamos Adafruit y la seleccinamos
![afttt6](https://user-images.githubusercontent.com/44387203/49811885-c8412880-fd29-11e8-92e6-7d0f567f253a.png)

Vamos a seleccionar nuestro Feeds creado con anterioridad y le damos un valor de 1, con el cuál se identificara la instrucción en Arduino.
![ifttt7](https://user-images.githubusercontent.com/44387203/49811855-bc556680-fd29-11e8-9bdf-54d7c8cc766c.png)


Repetimos los pasos para crear los diferentes casos que vamos a usar.
Serian 4 casos:
  -Encender luces
  -Apagar luces
  -Temperatura
  -Humedad
  
![ifttt2](https://user-images.githubusercontent.com/44387203/49811756-887a4100-fd29-11e8-95da-58408df02339.png)


En esta parte podemos visualizar la fecha, hora y lo que ha recibido nuestro Feeds test1.
![adafruit3](https://user-images.githubusercontent.com/44387203/49811598-3802e380-fd29-11e8-9475-d6eb04dcff5f.png)

