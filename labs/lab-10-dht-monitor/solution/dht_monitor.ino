#include <DHT.h>
const uint8_t DHT_PIN = 2;
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) Serial.println("READ_ERROR");
  else {
    Serial.print("T_C="); Serial.print(t, 1);
    Serial.print(",RH="); Serial.println(h, 1);
  }
  delay(2000);
}
