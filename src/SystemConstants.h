
/**
 * Constants for the master system
 */

/* Communication speed for the TFT display */
static const unsigned long TFT_RATE = 15000000;

/* Display rotations */
static const unsigned int HORIZONTAL_1 = 0;
static const unsigned int   VERTICAL_1 = 1;
static const unsigned int HORIZONTAL_2 = 2;
static const unsigned int   VERTICAL_2 = 3;

/* Predefined fonts */
static const unsigned int TITLE_FONT = 3;
static const unsigned int LABEL_FONT = 2;

/* Identifiers */
const byte SYSTEM_ID_READER    = 0x01;
const byte SYSTEM_BREATHALYZER = 0x02;
const byte SYSTEM_DISPENSER    = 0x03;
