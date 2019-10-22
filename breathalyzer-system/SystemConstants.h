
/**
 * Constants for the breathalyzer system
 */

/* UART baud rates */
static const unsigned int BREATHALYZER_BAUD_RATE = 9600;

/* Pin assignments */
static const int BREATHALYZER_ENABLE_PIN = 2;
static const int BREATHALYZER_DATA_PIN = A0;

/* Predefined packet bytes */
static const byte SYSTEM_ENABLE_BYTE = 0xAA;

/* Hardware constants */
static const unsigned int MAX_ANALOG_VALUE = 1023;
static const unsigned int MAX_BREATHALYZER_VALUE = 500;

/* Measurement thresholds */
static const unsigned int MEASUREMENT_SECONDS = 10;
static const unsigned int MEASUREMENT_COUNT = MEASUREMENT_SECONDS * 10;
static unsigned int measurements[MEASUREMENT_COUNT];
