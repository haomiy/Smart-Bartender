
/**
 * Functions involing external communicatiob
 */

/**
 * Sends the result in the form of a high byte
 * followed by a low byte
 * (Result = High << 8 | Low)
 */
void sentToExternal(unsigned int result) {
  byte toSend[] = {(result >> 8) & 0xFF, result & 0xFF};
  Serial.write(toSend, sizeof(toSend));
}
