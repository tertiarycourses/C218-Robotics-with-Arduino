#include <DHT.h>
const uint8_t DHT_PIN = 2;
const uint8_t FAN_PWM_PIN = 5;
DHT dht(DHT_PIN, DHT11);

void setup() {
  // TODO: initialise the sensor and protected actuator output.
}

void loop() {
  // TODO: reject invalid readings and apply ON/OFF hysteresis.
}
