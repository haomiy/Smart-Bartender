
/**
 * Test for HW and SW Serial for the "Sipeed MAIX Bit" microcontroller
 * *******************************************************************
 * 
 */

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  if(Serial.read() == 0xAA) {
    Serial.println("Received byte from Serial0");
  }
  if(Serial1.read() == 0xAA) {
    Serial.println("Received byte from Serial0");
  }
  if(Serial2.read() == 0xAA) {
    Serial.println("Received byte from Serial0");
  }
  if(Serial3.read() == 0xAA) {
    Serial.println("Received byte from Serial0");
  }
}
