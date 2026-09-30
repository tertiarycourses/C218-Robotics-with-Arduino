const uint8_t BUTTON_PIN = 2;
const uint8_t LED_PIN = 7;
const unsigned long DEBOUNCE_MS = 30;
bool ledOn = false;
bool stableState = HIGH;
bool lastRaw = HIGH;
unsigned long changedAt = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool raw = digitalRead(BUTTON_PIN);
  if (raw != lastRaw) { changedAt = millis(); lastRaw = raw; }
  if (millis() - changedAt >= DEBOUNCE_MS && raw != stableState) {
    stableState = raw;
    if (stableState == LOW) {
      ledOn = !ledOn;
      digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
    }
  }
}
