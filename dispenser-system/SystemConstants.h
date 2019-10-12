
/**
 * Constants for the dispenser system
 */

/* UART baud rates */
static const unsigned int DISPENSER_BAUD_RATE = 9600;

/* Ports for motors controlling valves */
static const int VALVES[] = {D2, D3, D4};

/* Size of incoming packet */
static const unsigned int PACKET_SIZE = 5;

/* Predefined packet bytes */
static const byte START_BYTE = 0x55;
static const byte   END_BYTE = 0xAA;

/* Predefined responses */
static const byte NAK = 0x00;
static const byte ACK = 0x01;

/* milliseconds for one milliliters to flow */
static const unsigned int MILLISECONDS_PER_MILLILITTER = 1;
