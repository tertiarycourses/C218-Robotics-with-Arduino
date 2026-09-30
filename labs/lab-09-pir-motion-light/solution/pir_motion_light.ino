const uint8_t PIR_PIN = 2;
const uint8_t LIGHT_PIN = 7;
const unsigned long HOLD_MS = 5000;
unsigned long lastMotionMs = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) lastMotionMs = millis();
  bool active = lastMotionMs != 0 && millis() - lastMotionMs < HOLD_MS;
  digitalWrite(LIGHT_PIN, active ? HIGH : LOW);
}
