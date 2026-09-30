#include <Stepper.h>
const int STEPS_PER_REV = 2048;
Stepper motor(STEPS_PER_REV, 8, 10, 9, 11);

void setup() {
  motor.setSpeed(10);
}

void loop() {
  motor.step(STEPS_PER_REV);
  delay(500);
  motor.step(-STEPS_PER_REV);
  delay(500);
}
