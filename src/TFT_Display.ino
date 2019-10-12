
/**
 * Loads different panes onto the TFT screen
 */

/* Global variables - Ignoring security concerns */
static String clientName = "";
static unsigned int clientAge    = -1;
static unsigned int clientWeight = -1;
static unsigned int isMale = -1;
static double BAC = -1;

/**
 * Loads the screen prior to ID scan
 */
void loadIDScanPromptScreen() {
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
}

/**
 * Displays the information the system currently has
 */
void loadInformationScreen() {
  tft.setTextSize(LABEL_FONT);
  tft.setCursor(70, 0);
  tft.println("Your information");
  tft.setCursor(0, 35);
  tft.print("* Name: "); if(clientName == "") tft.println("[Unknown]");
                         else tft.println(clientName);
  tft.println();
  tft.print("* Age : "); if(clientAge == -1) tft.println("[Unknown]");
                         else tft.println(clientAge);
  tft.println();
  tft.print("* Weight: "); if(clientWeight == -1) tft.println("[Unknown]");
                         else tft.println(clientWeight);
  tft.println();
  tft.print("* Gender: "); if(isMale == -1) tft.println("[Unknown]");
                           else if(isMale == 0) tft.println("Female");
                           else tft.println("Male");
  tft.println("--------------------------\n");
  tft.print("* BAC: "); if(BAC == -1) tft.println("[Unknown]");
                        else tft.println(BAC);
}

/**
 * Loads a prompt to breathe into the breathalyzer
 */
void loadBreathalyzerPromptScreen() {
  // TODO - Undecided
}
