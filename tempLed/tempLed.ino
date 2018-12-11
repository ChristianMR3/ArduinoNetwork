
/************************ Adafruit IO Configuration *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "PabloBarroso"
#define IO_KEY       "2bd2f2b95c0e49b5b4f0789bdf18e993"

/******************************* WIFI Configuration **************************************/
//
#define WIFI_SSID       "INFINITUMycq8"
#define WIFI_PASS       "B3rn4rd0N0H4C3"

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/************************ Main Program Starts Here *******************************/
#include <ESP8266WiFi.h>
#include <AdafruitIO.h>
#include <Adafruit_MQTT.h>
#include <ArduinoHttpClient.h>
#include <DHT11.h>
#define LED_PIN 0

// button state
int current = 0;
int last = 0;

// set up the 'command' feed
AdafruitIO_Feed *command = io.feed("test1");


float temp, hum;
int sensor = 2;
DHT11 dht11(sensor);

String readString;
String m;


void setup() {

  pinMode(LED_PIN, OUTPUT);

  // start the serial connection
  Serial.begin(115200);


  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'command' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  command->onMessage(handleMessage);

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();


}

// this function is called whenever a 'command' message
// is received from Adafruit IO. it was attached to
// the command feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  int command = data->toInt();

  dht11.read(hum, temp);


  while (Serial.available()) {
    delay(50);
    char c = Serial.read();
    readString += c;
  }


  if (command == 0) { //light up the LED
    Serial.print("received <- ");
    Serial.println(command);
    digitalWrite(LED_PIN, LOW);
  }
  if (command == 1) {
    Serial.print("received <- ");
    Serial.println(command);
    digitalWrite(LED_PIN, HIGH);
  }
  if (command == 2) {
    Serial.print("received <- ");
    Serial.println(command);
    Serial.println("Temperatura");
    Serial.println(temp);
  }
  if(command ==3) {
    Serial.print("received <- ");
    Serial.println(command);
    Serial.println("Humedad");
    Serial.println(hum);
    delay(1000);
  }
  
}
