
/**
 * Communicates with the breathalyzer and holds the
 * data until requested
 * (Sensor MAXIMUM 0.05 - 500 ppm)
 */
#include "SystemConstants.h"

void setup() {
  Serial.begin(BREATHALYZER_BAUD_RATE);

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  for(int i = 0; i < 20; i++) {
    int val = analogRead(A0);
    Serial.println(val);
    delay(100);
  }
}

void loop() {
  
}
