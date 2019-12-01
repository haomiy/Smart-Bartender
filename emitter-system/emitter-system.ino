
/**
 * System responsible for transmitting and receiving data
 * (Part of the main computer)
 */

#include "NeoSWSerial.h"
#include "SystemConstants.h"

NeoSWSerial Dispenser(rxDispenserPin, txDispenserPin);
NeoSWSerial Breathalyzer(rxBreathalyzerPin, txBreathalyzerPin);
NeoSWSerial IDReader(rxIDReaderPin, txIDReaderPin);

void setup() {
  Serial.begin(9600);
  Dispenser.begin(9600);
  Breathalyzer.begin(9600);
  IDReader.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    delay(5);
    if(Serial.available() == 1) consumeAllBytes();
    else {
      byte targetSystem = Serial.read();
      transmitToSystem(targetSystem);
    }
  }
}

void consumeAllBytes() {while(Serial.available() > 0) Serial.read();}
