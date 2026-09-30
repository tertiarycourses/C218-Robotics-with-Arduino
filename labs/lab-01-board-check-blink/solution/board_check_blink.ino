const uint8_t LED_PIN = LED_BUILTIN;
const unsigned long INTERVAL_MS = 250;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(INTERVAL_MS);
  digitalWrite(LED_PIN, LOW);
  delay(INTERVAL_MS);
}
