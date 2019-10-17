
/**
 * Constants for the breathalyzer
 */

/* UART baud rates */
static const unsigned int BREATHALYZER_BAUD_RATE = 9600;

/* Size of incoming packet */
static const unsigned int PACKET_SIZE = 4;

/* Predefined packet bytes */
static const byte START_BYTE = 0x55;
static const byte   END_BYTE = 0xAA;

/* Predefined responses */
static const byte NAK = 0x00;
static const byte ACK = 0x01;
