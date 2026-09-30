#include <Servo.h>
Servo actuator;
const uint8_t POT_PIN = A0;
const uint8_t SERVO_PIN = 9;

void setup() {
  actuator.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(POT_PIN);
  int angle = constrain(map(raw, 0, 1023, 0, 180), 0, 180);
  actuator.write(angle);
  Serial.println(angle);
  delay(15);
}
