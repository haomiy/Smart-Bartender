#include <Sipeed_ST7789.h>
#include "SystemConstants.h"

/**
 * Sets up TFT display screen
 * (Must be SPI0 for Maix series on board LCD)
 */
SPIClass spi_(SPI0);
Sipeed_ST7789 tft(320, 240, spi_);

void setup() {
   tft.begin(TFT_RATE, COLOR_BLACK);
   tft.setRotation(HORIZONTAL_1);
   tft.setTextColor(COLOR_WHITE);
   // pinMode(27, INPUT_PULLUP);
   Serial.begin(9600);
}

// each iteration is one user
void loop() {
   loadIDScanPromptScreen();
   
   // send an enable signal to the ID scanner
   byte enableScanner[] = {SYSTEM_ID_READER, 0xAA};
   Serial.write(enableScanner, sizeof(enableScanner));
   while (Serial.available() == 0) {} // May get stuck when ID is not detected
   Serial.read(); // consume byte

   delay(50);
   tft.fillScreen(COLOR_BLACK);
   loadBreathalyzerPromptScreen();
   byte enableBreathalyzer[] = {SYSTEM_BREATHALYZER, 0xAA};
   Serial.write(enableBreathalyzer, sizeof(enableBreathalyzer));
   while (Serial.available() == 0) {}
   delay(50);
   byte high_byte = Serial.read();
   byte low_byte = Serial.read();
   if (high_byte == 0xFF) {
      high_byte = 0x00; 
   }
   tft.setCursor(0, 100);
   // tft.println(high_byte);
   // tft.println(low_byte);
   unsigned int returnedMeasurement = (high_byte << 8) | low_byte; // PPM 0~500(but in normal air it's 20~40)
   tft.fillScreen(COLOR_BLACK);
   displayBACLevel(returnedMeasurement);
   // while (true) {}
   
   delay(50);
   // TO DO: calculate the amount of liquid to pour (in mL), based on the BAC level (mg/mL) 
   unsigned int amountToPour = 200;
   byte intHigh = (amountToPour >> 8) & 0xFF;
   intHigh = (intHigh == 0)? 0xFF: intHigh;
   byte intLow = amountToPour & 0xFF;
   intLow = (intLow == 0)? 0x01: intLow;
   byte dispenserValues[] = {0x03, 0xFF, intHigh, intLow};
   Serial.write(dispenserValues, sizeof(dispenserValues));
   delay(3000);
   byte dispenserValues2[] = {0x03, 0x01, intHigh, intLow};
   Serial.write(dispenserValues2, sizeof(dispenserValues2));
   tft.fillScreen(COLOR_BLACK);
   // while (true) {}
   
   // garbage code (above and below)
   /* byte valve   = Serial.read();
   byte intHigh = Serial.read();
   byte intLow  = Serial.read();
   if (intHigh == 0xFF) intHigh = 0x00;
   if (valve == 0xFF) valve = 0x00; */
   
   /* logic to determine whether to pour
      - have a function that takes in the BAC level (in mg/mL)
        and outputs how much alcohol the dispenser should 
        pour (in mL) */
  
   /*if (digitalRead(27) == LOW) {
     tft.fillScreen(COLOR_BLACK);
     // loadInformationScreen();
     loadBreathalyzerPromptScreen();
   }*/
   
   /*byte toSend[] = {byte1, byte2};
   Serial.write(toSend, sizeof(toSend));*/
}
