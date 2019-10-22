
/**
 * Methods for external communication
 */

/* Sends an external acknowledge packet as described in documentation */
void sendExternalACK() {
  byte toSend[] = {ACK};
  Serial.write(toSend, sizeof(toSend));
}

/* Sends an external not acknowledged packet as described in documentation */
void sendExternalNAK() {
  byte toSend[] = {NAK};
  Serial.write(toSend, sizeof(toSend));
}
