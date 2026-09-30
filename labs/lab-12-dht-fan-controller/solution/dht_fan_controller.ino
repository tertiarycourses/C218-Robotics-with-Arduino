#include <DHT.h>
const uint8_t DHT_PIN = 2;
const uint8_t FAN_PWM_PIN = 5;
const float FAN_ON_C = 30.0;
const float FAN_OFF_C = 28.0;
DHT dht(DHT_PIN, DHT11);
bool fanOn = false;

void setup() {
  pinMode(FAN_PWM_PIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  if (isnan(t)) { Serial.println("READ_ERROR"); delay(2000); return; }
  if (!fanOn && t >= FAN_ON_C) fanOn = true;
  if (fanOn && t <= FAN_OFF_C) fanOn = false;
  analogWrite(FAN_PWM_PIN, fanOn ? 255 : 0);
  Serial.print("T_C="); Serial.print(t, 1);
  Serial.print(",FAN="); Serial.println(fanOn ? "ON" : "OFF");
  delay(2000);
}
