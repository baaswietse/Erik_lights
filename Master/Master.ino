//NodemCu master: D1=SCL D2=SDA
//ArduinUno slaves: A5=SCL A4=SDA (arduino Uno)
//ArduinUno slaves: D21=SCL D20=SDA (arduino Mega)

//working pins on NodeMcu: rx(3), D2(4), D1(5), D5(14), D6(12), D7(13)

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <AdafruitIO.h>
#include <Adafruit_MQTT.h>
#include <ArduinoHttpClient.h>

#define IO_USERNAME    "baaswietse"
#define IO_KEY         "d0567df0d8ea4a6cbc9f6627f2f331c0"
#define WIFI_SSID      "Ownage" //"Erik-Home"
#define WIFI_PASS      "fearless" //"12345678"

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *command = io.feed("Erik");

void setup() {
  Wire.begin();

  Serial.begin(115200);
  Serial.print("Connecting to Adafruit IO");
  io.connect();
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
  io.run();
}

void handleMessage(AdafruitIO_Data *data) {
  String msg = data->value();

  //--------------MET DIMMER--------------------
  if (msg.indexOf(';') != -1){//-1 als er geen ';' is
    Serial.println("DIMMER");
    int index = msg.indexOf(';');
    String lamp = msg.substring(0, index);
    String dim = msg.substring(index+1);
    Serial.println("lamp: " + lamp + " " + "dimmer: " + dim);
    Serial.println();
    
  }
  //--------------GEWOON, ZONDER DIMMER----------------
  else{
    String temp = msg;
    char sendChar[temp.length() + 1];
    temp.toCharArray(sendChar, temp.length() + 1);
    
    if(msg.toInt() <= 68 && msg != "DONE"){
      Serial.println("GEEN DIMMER");
      Serial.println("Sending '" + msg + "' to slave 1...");
      Serial.println();
      Wire.beginTransmission(8); // transmit to device #8
      Wire.write(sendChar);
      Wire.endTransmission();    // stop transmitting
      command->save("DONE");
    }else if(msg.toInt() > 68 && msg != "DONE"){
      Serial.println("GEEN DIMMER");
      Serial.println("Sending '" + msg + "' to slave 2...");
      Serial.println();
      Wire.beginTransmission(9); // transmit to device #9
      Wire.write(sendChar);
      Wire.endTransmission();    // stop transmitting
      command->save("DONE");
    }
  }
   
  /*
  int input = data->toInt();
  //char* sendChar = data->toChar();
  Serial.println("input: " + String(data->value())); 
  
  String temp = String(input);
  char sendChar[temp.length() + 1];
  temp.toCharArray(sendChar, temp.length() + 1);
  */


  

}
