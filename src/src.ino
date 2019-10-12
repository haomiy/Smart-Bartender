
#include <Sipeed_ST7789.h>
#include <Sipeed_OV2640.h>
#include "SystemConstants.h"

/**
 * Sets up TFT display screen
 * (Must be SPI0 for Maix series on board LCD)
 */
SPIClass spi_(SPI0);
Sipeed_ST7789 tft(320, 240, spi_);

/* Sets up the camera */
Sipeed_OV2640 camera(FRAMESIZE_QVGA, PIXFORMAT_RGB565);

void setup() {
  Serial1.begin(DISPENSER_BAUD_RATE);
  Serial2.begin(BREATHALYZER_BAUD_RATE);
  camera.begin();
  camera.run(true);
  tft.begin(TFT_RATE, COLOR_BLACK);
  tft.setRotation(HORIZONTAL_1);
  tft.setTextColor(COLOR_WHITE);
}

void loop() {
  
}
