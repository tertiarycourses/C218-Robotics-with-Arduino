const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;
const unsigned long ECHO_TIMEOUT_US = 30000;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);
  if (duration == 0) Serial.println("NO_ECHO");
  else {
    float distanceCm = duration * 0.0343f / 2.0f;
    Serial.println(distanceCm, 1);
  }
  delay(100);
}
