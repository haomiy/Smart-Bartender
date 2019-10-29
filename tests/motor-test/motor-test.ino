
/**
 * Tests the air pump motor
 */

/* System Constants */
static const unsigned int MILLISECONDS = 500;
static const unsigned int MOTOR_PIN = 2;
void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);
  delay(MILLISECONDS);
  digitalWrite(MOTOR_PIN, HIGH);
}

void loop() {}
