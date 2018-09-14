#include "HashMap.h"
#include <Wire.h>
#include "config.h"

int delayTime = 100;
String data;

void setup() {
  Serial.begin(115200);
  Serial.println("starting up...");
  setHashMap();
  declarePins();
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
}

void loop() {
  relayChange();
  delay(50);

}

void receiveEvent(int howMany) {
  data = "";
  while (Wire.available()) {
    data += (char)Wire.read();
  }
  Serial.println("incoming data: " + data);
}


