const uint8_t LED_PIN = 9;
const unsigned long UPDATE_MS = 20;
const int STEP = 5;
int brightness = 0;
int direction = STEP;
unsigned long lastUpdate = 0;

void setup() { pinMode(LED_PIN, OUTPUT); }

void loop() {
  if (millis() - lastUpdate < UPDATE_MS) return;
  lastUpdate = millis();
  brightness += direction;
  if (brightness >= 255) { brightness = 255; direction = -STEP; }
  if (brightness <= 0) { brightness = 0; direction = STEP; }
  analogWrite(LED_PIN, brightness);
}
