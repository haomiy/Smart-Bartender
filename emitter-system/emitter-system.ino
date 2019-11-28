
/**
 * System responsible for transmitting and receiving data
 * (Part of the main computer)
 */
#include "SystemConstants.h"
#include <SoftwareSerial.h>

SoftwareSerial Dispenser(rxDispenserPin, txDispenserPin);
SoftwareSerial Breathalyzer(rxBreathalyzerPin, txBreathalyzerPin);
SoftwareSerial IDReader(rxIDReaderPin, txIDReaderPin);

void setup() {
  Serial.begin(9600);
  Dispenser.begin(9600);
  Breathalyzer.begin(9600);
  IDReader.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    delay(50);
    if(Serial.available() == 1) consumeAllBytes();
    else {
      byte targetSystem = Serial.read();
      transmitToSystem(targetSystem);
    }
  }
}

void consumeAllBytes() {while(Serial.available() > 0) Serial.read();}
