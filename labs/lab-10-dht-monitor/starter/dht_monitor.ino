#include <DHT.h>
const uint8_t DHT_PIN = 2;
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  // TODO: initialise the sensor.
}

void loop() {
  // TODO: read temperature/humidity, reject NaN, and report evidence.
}
