
/**
 * Loads different panes onto the TFT screen
 */

/* Global variables - Ignoring security concerns */
static String clientName = "";
static unsigned int clientAge    = -1;
static unsigned int clientWeight = -1;
static bool isMale = true;

/**
 * Loads the screen prior to ID scan
 */
void loadIDScanPromptScreen() {
  tft.fillScreen(COLOR_BLACK);
  tft.setTextSize(TITLE_FONT);
  tft.setCursor(100, 0);
  tft.println("Welcome");
  tft.setTextSize(LABEL_FONT);
  tft.setCursor(0, 35);
  tft.println("* You will need to scan");
  tft.println("  your ID card\n");
  tft.println("* Hold your ID card in");
  tft.println("  front of the camera\n");
  tft.println("* Then, press the button");
  tft.println("--------------------------\n");
  tft.println("* Press the button to");
  tft.println("  continue -->");
}

/**
 * Displays the view of the camera onto the screen
 */
void loadIDScanWaitScreen() {
  uint8_t* img = camera.snapshot();
  if(img != nullptr && img != 0)
    tft.drawImage(0, 16, camera.width(), camera.height() - 17, (uint16_t*)img);
  tft.setTextSize(LABEL_FONT);
  tft.setCursor(15, 0);
  tft.println("Press button to confirm");
  tft.drawRect(0, 16, camera.width(), camera.height() - 17, COLOR_YELLOW);
}

/**
 * 
 */
void loadInformationScreen() {
  
}

/**
 * 
 */
void loadBreathalyzerPromptScreen() {
  
}
