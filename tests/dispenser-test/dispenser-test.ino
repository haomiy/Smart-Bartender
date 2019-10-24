
/**
 * Test for the dispenser system
 */

/* System Constants */
static const byte ACK = 0x01;
static const unsigned int WAIT_TIME = 50;
static const byte VALVE_0 = 0x00;
static const byte VALVE_1 = 0x01;

/* Modify this: Don't fuck with the code. Thanks */
static byte VALVE = VALVE_0;
static int AMOUNT_IN_MILLILITERS = 50;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  byte amountHighByte = (AMOUNT_IN_MILLILITERS >> 8) & 0xFF;
  byte amountLowByte  = AMOUNT_IN_MILLILITERS & 0xFF;
  byte toSend[] = {VALVE, amountHighByte, amountLowByte};
  Serial.write(toSend, sizeof(toSend));

  if(Serial.read() != ACK) digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {}
