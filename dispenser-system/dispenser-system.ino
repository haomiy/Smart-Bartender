
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
  pinMode(VALVES[0], OUTPUT);
  pinMode(VALVES[1], OUTPUT);
  digitalWrite(VALVES[0], HIGH);
  digitalWrite(VALVES[1], HIGH);
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
      receivedVolumeLowByte  = 0xFF;
      sendExternalNAK();
    }
    else {
      receivedSlot = Serial.read();
      receivedVolumeHighByte = Serial.read();
      receivedVolumeLowByte  = Serial.read();
      sendExternalACK();
      /* Everything is OK. Start pouring */
      unsigned long volume = receivedVolumeHighByte << 8 | receivedVolumeLowByte;
      digitalWrite(VALVES[receivedSlot], LOW);
      delay(millilitersToMilliseconds(volume));
      digitalWrite(VALVES[receivedSlot], HIGH);
    }
  }
}

/* Converts milliliters to pour to milliseconds the motor needs to maintain ON */
int millilitersToMilliseconds(int milliliters) {
  return ceil(40.7*milliliters - 267);
}
