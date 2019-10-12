
/**
 * Contains methods for external communication
 */

/* Sends an external acknowledge packet as described in documentation */
void sendExternalACK() {
  byte toSend[] = {START_BYTE,
                   ACK, receivedSlot,receivedVolumeHighByte, receivedVolumeLowByte,
                   END_BYTE};
  Serial.write(toSend, sizeof(toSend));
}

/* Sends an external not acknowledged packet as described in documentation */
void sendExternalNAK() {
  byte toSend[] = {START_BYTE,
                   NAK, receivedSlot,receivedVolumeHighByte, receivedVolumeLowByte,
                   END_BYTE};
  Serial.write(toSend, sizeof(toSend));
}
