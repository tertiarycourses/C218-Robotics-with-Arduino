const uint8_t LDR_PIN = A0;
const uint8_t LAMP_PIN = 7;

void setup() {
  pinMode(LAMP_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);
  // TODO: apply calibrated ON/OFF thresholds with hysteresis.
}
