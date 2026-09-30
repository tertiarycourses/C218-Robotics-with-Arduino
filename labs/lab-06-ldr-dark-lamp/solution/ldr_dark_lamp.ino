const uint8_t LDR_PIN = A0;
const uint8_t LAMP_PIN = 7;
const int ON_THRESHOLD = 350;
const int OFF_THRESHOLD = 450;
bool lampOn = false;

void setup() {
  pinMode(LAMP_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);
  if (!lampOn && light < ON_THRESHOLD) lampOn = true;
  if (lampOn && light > OFF_THRESHOLD) lampOn = false;
  digitalWrite(LAMP_PIN, lampOn ? HIGH : LOW);
  Serial.println(light);
  delay(100);
}
