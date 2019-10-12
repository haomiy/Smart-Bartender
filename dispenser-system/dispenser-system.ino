
/**
 * Dispenses liquid based on the slot and volume received
 * See https://github.com/Haomin-Yu/Smart-Bartender/blob/master/dispenser-system/README.md
 * for specifics
 */

#include "SystemConstants.h"

/* Global variables - Ignoring security concerns */
static byte receivedSlot;
static byte receivedVolumeHighByte;
static byte receivedVolumeLowByte;

void setup() {
  Serial.begin(DISPENSER_BAUD_RATE);
  pinMode(VALVE_1, OUTPUT);
  pinMode(VALVE_2, OUTPUT);
  pinMode(VALVE_3, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    static const unsigned int WAIT_TIME = 50;
    unsigned long startTime = millis();
    while(millis() - startTime < WAIT_TIME && Serial.available() < PACKET_SIZE) {}
    if(Serial.available() < PACKET_SIZE) { // Missing bytes
      while(Serial.available() > 0) Serial.read(); /* Consume all */
      receivedSlot = 0xFF;
      receivedVolumeHighByte = 0xFF;
      receivedVolumeLowByte = 0xFF;
      sendExternalNAK();
    }
    else {
      Serial.read(); // Throw away START_BYTE
      receivedSlot = Serial.read();
      receivedVolumeHighByte = Serial.read();
      receivedVolumeLowByte  = Serial.read();
      Serial.read(); // Throw away END_BYTE
      sendExternalACK();
      /* Everything is OK. Start pouring */
      unsigned long volume = receivedVolumeHighByte << 8 | receivedVolumeLowByte;
      digitalWrite(VALVES[receivedSlot], HIGH);
      delay(MILLISECONDS_PER_MILLILITTER * volume);
      digitalWrite(VALVES[receivedSlot], LOW);
    }
  }
}
