
/**
 * Constants for the dispenser system
 */

/* UART baud rates */
static const unsigned int DISPENSER_BAUD_RATE = 9600;

/* Ports for motors controlling valves */
static const int VALVES[] = {2, 3};

/* Size of incoming packet */
static const unsigned int PACKET_SIZE = 3;

/* Predefined responses */
static const byte NAK = 0x00;
static const byte ACK = 0x01;
