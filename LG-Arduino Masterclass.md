# Arduino Masterclass - Learner Guide

**Course Code:** C218<br>
**Version:** 1.0<br>
**Date:** 30 September 2026<br>

## Course Overview

This guide develops one continuous embedded-control stack: sense, condition, acquire, decide, actuate, and verify.

## Learning Outcomes

- **LO1** - Analyse real-life applications using Arduino microcontroller
- **LO2** - Implement basic electrical circuits using Arduino microcontroller
- **LO3** - Apply Arduino microcontroller to analogue sensors and transducers
- **LO4** - Apply Arduino microcontroller to digital sensors and transducers
- **LO5** - Implement actuators with Arduino microcontroller

## Safety and Toolchain

- Disconnect power before rewiring.
- Never power a motor or servo from an Arduino I/O pin.
- Use a driver and flyback protection for inductive loads.
- Establish common ground between control and external supply.

## Topic 1: Introduction to Embedded Systems

An embedded system is a bounded control system. Its architecture, memory, timing, I/O and evidence must support a dedicated physical function. On reset, the bootloader and sketch initialise hardware before loop() executes repeatedly. Serial communication provides both a command path and a diagnostic trace.

### Lab 1: Board Check and Deterministic Blink

**Alignment:** LO1<br>
**Objective:** Validate the Arduino Uno/Maker UNO toolchain and prove deterministic digital output timing.<br>
**Deliverable:** A board-identification record and a 250 ms LED heartbeat that verifies compile, upload, reset, and loop execution.

#### Components

- Arduino Uno or Maker UNO
- USB data cable
- Arduino IDE 2.x

#### Wiring

| From | To | Purpose |
|---|---|---|
| LED_BUILTIN | On-board LED | No external wiring |
| USB | Computer | Power + serial upload |

#### Detailed procedure

1. Connect the board using a USB data cable and identify the board/port shown by the IDE.
2. Open the starter sketch and predict the LED period before compiling.
3. Select Arduino Uno and the detected serial port, then compile and upload.
4. Time ten complete blink cycles and compare the observed period with the expected 500 ms cycle.
5. Change INTERVAL_MS to 1000, upload again, and record the changed evidence.

#### Solution sketch

```cpp
const uint8_t LED_PIN = LED_BUILTIN;
const unsigned long INTERVAL_MS = 250;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(INTERVAL_MS);
  digitalWrite(LED_PIN, LOW);
  delay(INTERVAL_MS);
}
```

#### Acceptance checks

- Sketch compiles with no error
- Upload completes on the selected port
- LED cycles 250 ms ON and 250 ms OFF
- Measured ten-cycle duration is approximately 5 seconds

#### Troubleshooting

- **Port missing:** Try a known USB data cable, reconnect, and confirm the CH340/USB serial device.
- **Upload timeout:** Check Board and Port, close Serial Monitor, then press reset before retrying.
- **Wrong timing:** Confirm milliseconds and that both HIGH and LOW paths use INTERVAL_MS.
### Lab 2: Serial Command Control

**Alignment:** LO1<br>
**Objective:** Trace UART data from a typed ASCII command to a validated output state.<br>
**Deliverable:** A line-oriented command parser that accepts ON, OFF, and STATUS without blocking indefinitely.

#### Components

- Arduino Uno or Maker UNO
- USB data cable
- Arduino IDE Serial Monitor

#### Wiring

| From | To | Purpose |
|---|---|---|
| LED_BUILTIN | On-board LED | Output |
| USB serial | Computer | 9600 bit/s, newline terminator |

#### Detailed procedure

1. Upload the starter sketch and open Serial Monitor at 9600 baud with Newline selected.
2. Send ON, OFF, and STATUS while observing both the LED and acknowledgement text.
3. Send a lowercase command and an invalid command; record how the parser handles each.
4. Disconnect and reconnect the board, then confirm the default output is safe and OFF.

#### Solution sketch

```cpp
String command;
bool ledOn = false;

void applyOutput() {
  digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  applyOutput();
  Serial.begin(9600);
  Serial.println("READY: ON | OFF | STATUS");
}

void loop() {
  if (Serial.available() == 0) return;
  command = Serial.readStringUntil('\n');
  command.trim();
  command.toUpperCase();
  if (command == "ON") ledOn = true;
  else if (command == "OFF") ledOn = false;
  else if (command == "STATUS") { /* report only */ }
  else { Serial.println("ERR"); return; }
  applyOutput();
  Serial.println(ledOn ? "LED=ON" : "LED=OFF");
}
```

#### Acceptance checks

- ON lights the LED
- OFF extinguishes the LED
- STATUS reports the true output state
- Unknown input returns ERR without changing output

#### Troubleshooting

- **Garbled text:** Set Serial Monitor to 9600 baud to match Serial.begin().
- **Commands ignored:** Select Newline and confirm the parser removes carriage return/newline characters.
- **LED state wrong:** Read back the maintained ledOn state rather than assuming the command succeeded.

## Topic 2: Introduction to Basic Electronics

Basic electronics turns code into safe physical behaviour. Ohm's law sets current limits, breadboard topology determines real connectivity, pull resistors prevent floating inputs, debounce rejects switch transitions, and PWM changes duty cycle while a driver protects the microcontroller from higher-current loads.

### Lab 3: Safe LED Circuit and Ohm's Law

**Alignment:** LO2<br>
**Objective:** Calculate and build a current-limited LED circuit within an Arduino digital pin's electrical boundary.<br>
**Deliverable:** A documented 5 V digital-output circuit using a 330 ohm resistor and measured LED voltage.

#### Components

- Arduino Uno or Maker UNO
- Breadboard
- LED
- 330 ohm resistor
- Jumper wires
- Multimeter

#### Wiring

| From | To | Purpose |
|---|---|---|
| D7 | 330 ohm resistor | Series current limit |
| Resistor | LED anode | Long lead |
| LED cathode | GND | Short lead / flat edge |

#### Detailed procedure

1. Calculate R=(5 V-2 V)/0.01 A and explain why 330 ohm is a safe standard value.
2. Build the series path D7 -> resistor -> LED -> GND with power disconnected.
3. Upload the sketch and verify the LED toggles once per second.
4. Measure LED forward voltage while ON and calculate the observed current from the resistor voltage.

#### Solution sketch

```cpp
const uint8_t LED_PIN = 7;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

#### Acceptance checks

- LED polarity is correct
- A current-limiting resistor is in series
- LED toggles at 1 Hz
- Calculated current remains close to or below 10 mA

#### Troubleshooting

- **LED never lights:** Reverse the LED and confirm D7 is connected through the resistor to the anode.
- **LED very dim:** Measure the supply and forward voltage; confirm the resistor is 330 ohm, not 330 kilohm.
- **Board resets:** Disconnect immediately and check for a short between 5 V and GND.
### Lab 4: Push Button with INPUT_PULLUP

**Alignment:** LO2<br>
**Objective:** Eliminate a floating input and debounce a mechanical switch using a stable time window.<br>
**Deliverable:** An active-LOW button that toggles an LED once per physical press without double triggers.

#### Components

- Arduino Uno or Maker UNO
- Push button
- LED circuit from Lab 3
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| D2 | Push button terminal A | INPUT_PULLUP |
| Push button terminal B | GND | Pressed = LOW |
| D7 | LED + 330 ohm | Output evidence |

#### Detailed procedure

1. Place the button across the breadboard centre gap and identify the internally common legs.
2. Wire D2 to one side and GND to the opposite side; do not add an external pull-down.
3. Upload the sketch and press/release the button repeatedly at different speeds.
4. Observe the raw state in Serial Monitor and confirm one LED toggle per accepted press.

#### Solution sketch

```cpp
const uint8_t BUTTON_PIN = 2;
const uint8_t LED_PIN = 7;
const unsigned long DEBOUNCE_MS = 30;
bool ledOn = false;
bool stableState = HIGH;
bool lastRaw = HIGH;
unsigned long changedAt = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool raw = digitalRead(BUTTON_PIN);
  if (raw != lastRaw) { changedAt = millis(); lastRaw = raw; }
  if (millis() - changedAt >= DEBOUNCE_MS && raw != stableState) {
    stableState = raw;
    if (stableState == LOW) {
      ledOn = !ledOn;
      digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
    }
  }
}
```

#### Acceptance checks

- Released input reads HIGH
- Pressed input reads LOW
- LED toggles once per press
- Bounce within 30 ms does not create extra toggles

#### Troubleshooting

- **Input always LOW:** Check that D2 and GND are not on the same internally connected button leg.
- **Random triggers:** Confirm INPUT_PULLUP is used and all grounds are common.
- **Double toggles:** Increase DEBOUNCE_MS slightly and ensure only the falling edge toggles state.
### Lab 5: PWM Fade with Non-blocking Timing

**Alignment:** LO2<br>
**Objective:** Relate 8-bit PWM values to duty cycle and vary LED brightness without blocking other logic.<br>
**Deliverable:** A triangular 0-255 PWM ramp on D9 with calculated duty-cycle checkpoints.

#### Components

- Arduino Uno or Maker UNO
- LED
- 330 ohm resistor
- Breadboard
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| D9 (~) | 330 ohm resistor | PWM output |
| Resistor | LED anode | Series |
| LED cathode | GND | Return |

#### Detailed procedure

1. Move the LED circuit to PWM-capable pin D9 and confirm the tilde marking/pin map.
2. Upload the non-blocking fade sketch and monitor the brightness value at key checkpoints.
3. Calculate duty cycle for values 64, 128, and 192 using value/255 x 100%.
4. Change STEP to 15 and compare the smoothness and cycle duration.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- LED fades up and down continuously
- No delay() is used in loop()
- Value never exceeds 0-255
- Calculated 128 duty cycle is approximately 50%

#### Troubleshooting

- **No fade:** Confirm the LED is on a PWM pin such as D9, not a non-PWM pin.
- **Brightness jumps:** Reduce STEP or shorten UPDATE_MS.
- **Value wraps:** Reverse direction before the integer crosses the 0 or 255 bounds.

## Topic 3: Analogue Sensors and Transducers

Analogue control starts with a continuous quantity and ends with a bounded digital decision. The 10-bit ADC quantises voltage into 0-1023, calibration maps real endpoints, filtering reduces noise, hysteresis stabilises threshold control, and servo power must remain separate from the signal pin.

### Lab 6: LDR Dark-Activated Lamp with Hysteresis

**Alignment:** LO3<br>
**Objective:** Convert a light-dependent voltage divider into a stable two-threshold control decision.<br>
**Deliverable:** A calibrated dark-activated lamp that avoids chatter around the switching threshold.

#### Components

- Arduino Uno or Maker UNO
- LDR
- 10 kilohm resistor
- LED + 330 ohm
- Breadboard
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| 5 V | LDR | Divider top |
| LDR/resistor junction | A0 | ADC input |
| 10 kilohm resistor | GND | Divider bottom |
| D7 | LED circuit | Lamp output |

#### Detailed procedure

1. Build the divider and record A0 values under bright, room, and covered conditions.
2. Choose ON_THRESHOLD below the dark value and OFF_THRESHOLD above it to create a dead band.
3. Upload the solution and slowly shade the LDR while observing state and ADC evidence.
4. Explain why one threshold would chatter when readings contain noise.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- Serial output shows plausible 0-1023 readings
- Lamp turns ON in dark conditions
- Lamp turns OFF in bright conditions
- Output remains stable inside the hysteresis band

#### Troubleshooting

- **Reading fixed at 0:** Check A0 is not shorted to GND and the LDR is connected to 5 V.
- **Reading fixed at 1023:** Check the 10 kilohm resistor reaches GND.
- **Logic reversed:** Swap divider orientation or reverse the comparison to match measured calibration.
### Lab 7: Potentiometer-Controlled Servo

**Alignment:** LO3<br>
**Objective:** Map a 10-bit ADC measurement to a bounded servo command while respecting the servo power boundary.<br>
**Deliverable:** A 0-180 degree servo position controller with clamped input and separate-power guidance.

#### Components

- Arduino Uno or Maker UNO
- 10 kilohm potentiometer
- SG90 servo
- External regulated 5 V supply recommended
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| Pot outer pins | 5 V and GND | Divider |
| Pot wiper | A0 | ADC input |
| Servo signal | D9 | Control pulse |
| Servo V+ | Regulated 5 V | Do not overload I/O pin |
| All grounds | Common GND | Signal reference |

#### Detailed procedure

1. Wire the potentiometer divider and confirm A0 spans most of 0-1023.
2. Connect the servo signal to D9 and establish a common ground with its power source.
3. Upload the solution, rotate slowly, and verify commanded angle follows the knob.
4. Test the endpoints and confirm constrain() prevents commands outside 0-180 degrees.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- ADC reading changes smoothly
- Servo follows the potentiometer
- Command stays within 0-180 degrees
- Board does not reset when servo moves

#### Troubleshooting

- **Servo jitters:** Improve the 5 V supply, common the grounds, and add a capacitor near the servo.
- **Servo moves backward:** Reverse the map output range if required by the application.
- **Board resets:** Power the servo from a suitable external 5 V source rather than an I/O pin.

## Topic 4: Digital Sensors and Transducers

Digital sensors encode information as levels, pulse widths or framed data. Reliable control requires correct thresholds, edges, timeouts and explicit fault states. Ultrasonic distance uses round-trip time of flight; PIR motion produces an active-level contract combined with a non-blocking hold timer.

### Lab 8: Ultrasonic Distance with Timeout

**Alignment:** LO4<br>
**Objective:** Measure echo pulse width, convert time-of-flight to distance, and handle a missing echo safely.<br>
**Deliverable:** A distance monitor that reports centimetres or NO_ECHO within a bounded 30 ms wait.

#### Components

- Arduino Uno or Maker UNO
- HC-SR04/HY-SRF05 ultrasonic sensor
- Breadboard
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| Sensor VCC | 5 V | Supply |
| Sensor GND | GND | Return |
| TRIG | D9 | 10 microsecond output pulse |
| ECHO | D10 | Pulse input |

#### Detailed procedure

1. Wire the sensor and confirm the trigger and echo pins are not swapped.
2. Upload the sketch and position a flat target 20-100 cm in front of the sensor.
3. Compare Serial Monitor distance with a ruler at three positions.
4. Remove the target and confirm the 30 ms timeout returns NO_ECHO instead of blocking forever.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- Distance is within a reasonable tolerance of the ruler
- Readings update continuously
- Missing echo returns NO_ECHO
- No divide-by-zero or indefinite wait occurs

#### Troubleshooting

- **Always NO_ECHO:** Swap TRIG/ECHO if reversed and verify the sensor has 5 V and common GND.
- **Distance doubles:** The conversion must divide the round-trip distance by two.
- **Unstable values:** Use a flat target, avoid soft fabric, and keep within the sensor's working zone.
### Lab 9: PIR Motion-Activated Light

**Alignment:** LO4<br>
**Objective:** Use a digital motion sensor contract and a non-blocking hold timer to control a light.<br>
**Deliverable:** A motion light that extends its ON period when new motion arrives and expires safely after five seconds.

#### Components

- Arduino Uno or Maker UNO
- HC-SR501 PIR sensor
- LED + 330 ohm
- Breadboard
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| PIR VCC | 5 V | Supply |
| PIR GND | GND | Return |
| PIR OUT | D2 | Digital input |
| D7 | LED circuit | Light output |

#### Detailed procedure

1. Wire the PIR and allow its warm-up/calibration interval after power-up.
2. Upload the sketch and move across the sensor field of view.
3. Trigger motion again before five seconds expires and confirm the hold timer extends.
4. Remain still and verify the output turns OFF after the bounded hold period.

#### Solution sketch

```cpp
const uint8_t PIR_PIN = 2;
const uint8_t LIGHT_PIN = 7;
const unsigned long HOLD_MS = 5000;
unsigned long lastMotionMs = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) lastMotionMs = millis();
  bool active = lastMotionMs != 0 && millis() - lastMotionMs < HOLD_MS;
  digitalWrite(LIGHT_PIN, active ? HIGH : LOW);
}
```

#### Acceptance checks

- Motion drives the output HIGH
- Output remains ON for five seconds after the latest motion
- New motion extends the timer
- loop() remains responsive without delay(5000)

#### Troubleshooting

- **Always HIGH:** Wait for warm-up and check the sensor retrigger jumper and sensitivity settings.
- **No detection:** Confirm OUT reaches D2 and walk laterally across the field of view.
- **Light turns off too soon:** Update lastMotionMs every time the PIR is HIGH.

## Topic 5: Actuators

Actuators consume energy and therefore require a power stage. MOSFETs or driver arrays switch load current, flyback paths clamp inductive energy, step sequences create position, and feedback controllers validate sensor readings before applying hysteresis and commanding the actuator.

### Lab 10: DHT11 Temperature and Humidity Monitor

**Alignment:** LO5<br>
**Objective:** Read a library-managed digital sensor transaction and reject invalid measurements before control use.<br>
**Deliverable:** A one-hertz temperature/humidity monitor that identifies NaN failures instead of treating them as real values.

#### Components

- Arduino Uno or Maker UNO
- DHT11 module
- 10 kilohm pull-up if using a bare sensor
- Jumper wires
- Adafruit DHT sensor library

#### Wiring

| From | To | Purpose |
|---|---|---|
| DHT VCC | 5 V | Supply |
| DHT GND | GND | Return |
| DHT DATA | D2 | Digital data |
| DATA to VCC | 10 kilohm | Pull-up for bare sensor |

#### Detailed procedure

1. Install the Adafruit DHT sensor library and its required dependency from Library Manager.
2. Wire the DHT11 and upload the monitor sketch.
3. Warm the sensor gently and observe the change without touching exposed conductors.
4. Disconnect DATA briefly and confirm the sketch reports READ_ERROR rather than a numeric control value.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- Temperature and humidity update approximately once per second
- Values are plausible for the room
- Disconnected/failed read reports READ_ERROR
- dht.begin() is called in setup()

#### Troubleshooting

- **READ_ERROR:** Check sensor type, D2 wiring, pull-up, common ground, and the two-second minimum sample interval if needed.
- **Values never change:** Avoid reading faster than the sensor supports and confirm the correct DHT type.
- **Compile error:** Install both the DHT sensor library and Adafruit Unified Sensor dependency.
### Lab 11: Stepper Motor Position Control

**Alignment:** LO5<br>
**Objective:** Drive a four-phase stepper through a transistor array and relate commanded steps to angular position.<br>
**Deliverable:** A 28BYJ-48/ULN2003 actuator that moves one revolution forward and backward at a bounded speed.

#### Components

- Arduino Uno or Maker UNO
- 28BYJ-48 stepper
- ULN2003 driver board
- External 5 V supply
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| D8-D11 | ULN2003 IN1-IN4 | Phase controls |
| ULN2003 5 V | External 5 V | Motor power |
| ULN2003 GND | Arduino GND | Common reference |
| Stepper | ULN2003 socket | Keyed connector |

#### Detailed procedure

1. Connect the driver inputs in the library sequence and establish common ground.
2. Upload the sketch with STEPS_PER_REV set for the supplied motor/gearbox.
3. Mark the shaft, observe one forward and one reverse revolution, and record position error.
4. Increase speed modestly and identify the point where the motor begins to miss steps.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- Motor completes a forward and reverse move
- Direction reverses correctly
- Driver—not Arduino I/O—supplies coil current
- Grounds are common and board remains stable

#### Troubleshooting

- **Motor vibrates:** Check IN1-IN4 order and use the phase order required by the library/driver.
- **Weak torque:** Use a suitable external 5 V supply and lower the speed.
- **Wrong angle:** Calibrate STEPS_PER_REV for the actual gearbox and stepping mode.
### Lab 12: DHT Fan Controller with Hysteresis

**Alignment:** LO5<br>
**Objective:** Integrate measurement, decision logic, and a protected continuous-drive actuator into a feedback controller.<br>
**Deliverable:** A temperature-controlled DC fan with MOSFET switching, flyback protection, PWM drive, and hysteresis.

#### Components

- Arduino Uno or Maker UNO
- DHT11
- Logic-level N-channel MOSFET
- DC fan/motor
- Flyback diode
- External motor supply
- Jumper wires

#### Wiring

| From | To | Purpose |
|---|---|---|
| DHT DATA | D2 | Measurement |
| D5 PWM | MOSFET gate through 220 ohm | Control |
| 10 kilohm | Gate to GND | Safe default OFF |
| Motor/fan | External supply + MOSFET drain | Power path |
| Flyback diode | Across motor | Cathode to supply + |
| All grounds | Common GND | Reference |

#### Detailed procedure

1. Build the low-side MOSFET driver with power disconnected and verify diode polarity.
2. Upload the controller and confirm the fan is OFF below FAN_ON_C.
3. Warm the DHT11 above the ON threshold and observe full PWM drive.
4. Let the sensor cool below FAN_OFF_C and confirm the fan does not chatter between thresholds.

#### Solution sketch

```cpp
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
```

#### Acceptance checks

- Fan turns ON above 30 C
- Fan remains ON until temperature falls below 28 C
- Invalid DHT read leaves the previous safe state and reports an error
- Motor current never flows through an Arduino I/O pin

#### Troubleshooting

- **Fan never starts:** Check external supply, common ground, MOSFET pinout, and gate drive.
- **Arduino resets:** Separate motor power, add decoupling, and verify flyback diode orientation.
- **Fan chatters:** Use distinct ON/OFF thresholds and a realistic sample interval.

## Technical References

- https://docs.arduino.cc/language-reference/
- https://www.tertiarycourses.com.sg/arduino-masterclass.html
