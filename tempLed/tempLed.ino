/************************ configuracion de io.adafruit *******************************/

/************************ configuracion de adafruit *******************************/
//para esto necesitamos una cuenta de adafruit
// visita io.adafruit.com si necesitas crear una cuenta,
// or if you need your Adafruit IO key.

#define IO_USERNAME  "PabloBarroso"  ///introduimos nuestro nombre de ususario
#define IO_KEY       "***************" //la llave de nuestro usuario (por custiones de seguridad no se puede poner la clave)
                                       //ya que cada ususario tiene una diferente ademas se vincula a tu e-mail
//el nombre de ususario y la llave te las proporcionan una vez creas tu cuenta

/******************************* Configuration del WIFI **************************************/
//
#define WIFI_SSID       "INFINITUMycq8" // nombre de la red a la cual la placa estara conectada
#define WIFI_PASS       "B3rn4rd0N0H4C3" // contraseña de la red a la cual la placa estara conectada

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/************************ Main Programa Inicia aqui *******************************/
#include <ESP8266WiFi.h> //libreria de la placa ESP8266
#include <AdafruitIO.h> //libreria para poder conectarnos con adafruit
#include <Adafruit_MQTT.h>
#include <ArduinoHttpClient.h> //cliente de http
#include <DHT11.h> // libreria del sensor de temperatura
#define LED_PIN 0  // led

// button state
int current = 0;
int last = 0;

// especificamos el 'command' feed "el feed es el nombre del proyecto que creamos en adafruit"
AdafruitIO_Feed *command = io.feed("test1");


float temp, hum; //declaramos las varables y el pin para el DHT11
int sensor = 2;
DHT11 dht11(sensor);

void setup() {

  pinMode(LED_PIN, OUTPUT);

  // iniciamos la conexion serial
  Serial.begin(115200);


  // conectamos con io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'command' feed.
  // la funcion handleMessage (defininida mas abajo)
  // will be called whenever a message is
  // received from adafruit io.
  command->onMessage(handleMessage);

  // esperamos la conexion con adafruit
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  //se imprime este mensaje si nos concectamos correctamente
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run();es requerido en todos los sketches.
  // simepre debe estar presente en la parte superior de el la funcion loop()
  //mantiene el cliente conectado con i0.adafruit.com, y procesa cualquier dato de entrada
  io.run();


}
//esta funcion es llamada siempre que un mensaje 'command'
// es recivido desde Adafruit IO. que fue definida
// en el command feed en la funcion setup().
void handleMessage(AdafruitIO_Data *data) {

  int command = data->toInt();

  dht11.read(hum, temp); // leemos los datos del sensor tanto la temperatura como la humedad

// se resive la instruccion por el asistente de google y nos retorna un 0
  if (command == 0) { // apaga el LED
    Serial.print("received <- ");
    Serial.println(command);
    digitalWrite(LED_PIN, LOW);
  }
  // se resive la instruccion por el asistente de google y nos retorna un 1
  if (command == 1) { /// enciende el led
    Serial.print("received <- ");
    Serial.println(command);
    digitalWrite(LED_PIN, HIGH);
  }
  // se resive la instruccion por el asistente de google y nos retorna un 2
  if (command == 2) { // nos muestra la temperatura en pantalla
    Serial.print("received <- ");
    Serial.println(command);
    Serial.println("Temperatura");
    Serial.println(temp);
  }
  // se resive la instruccion por el asistente de google y nos retorna un 3
  if(command ==3) { // nos muestra la humadad en pantalla
    Serial.print("received <- ");
    Serial.println(command);
    Serial.println("Humedad");
    Serial.println(hum);
   // delay(1000);
  }
  
}
