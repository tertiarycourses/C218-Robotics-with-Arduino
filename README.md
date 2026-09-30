# Arduino Masterclass

Build, measure and diagnose Arduino embedded-control systems in one hands-on day — using real circuits, sensor evidence, actuator drivers and runnable sketches.

| Course detail | Information |
|---|---|
| Course code | `C218` |
| Programme | Non-WSQ |
| Duration | 1 day · 7.5 instructional hours (9:30am – 5:30pm) |
| Registration | [View course details and register](https://www.tertiarycourses.com.sg/arduino-masterclass.html) |

## About the course

This course develops an end-to-end embedded-systems workflow: acquire analogue and digital sensor evidence, apply bounded Arduino control logic, drive protected actuators, and verify the resulting behaviour against a specification. Every lab ends with acceptance checks, so each build is proven before you move on.

> The Arduino kit is used for the training. The course fee does not include the kit.

## Learning outcomes

- **LO1** — Analyse real-life applications using Arduino microcontroller
- **LO2** — Implement basic electrical circuits using Arduino microcontroller
- **LO3** — Apply Arduino microcontroller to analogue sensors and transducers
- **LO4** — Apply Arduino microcontroller to digital sensors and transducers
- **LO5** — Implement actuators with Arduino microcontroller

## Topics covered

| Topic | Focus | Labs |
|---|---|---|
| 1 · Introduction to Embedded Systems | Embedded architecture, ATmega328P/Arduino boundaries, sketch lifecycle, timing, serial communication | Labs 1–2 |
| 2 · Introduction to Basic Electronics | Ohm's law, breadboards, digital I/O, pull-ups, debounce, PWM, protected loads | Labs 3–5 |
| 3 · Analogue Sensors and Transducers | 10-bit ADC, calibration, filtering, LDR control, hysteresis, servo mapping | Labs 6–7 |
| 4 · Digital Sensors and Transducers | Ultrasonic trigger/echo timing, timeouts, PIR motion states, responsive digital control | Labs 8–9 |
| 5 · Actuators | Motor/stepper drivers, flyback protection, DHT validity, feedback control | Labs 10–12 |

## Labs

- [Lab 1 — Board Check and Deterministic Blink](labs/lab-01-board-check-blink/)
- [Lab 2 — Serial Command Control](labs/lab-02-serial-command-control/)
- [Lab 3 — Safe LED Circuit and Ohm's Law](labs/lab-03-safe-led-circuit/)
- [Lab 4 — Push Button with INPUT_PULLUP](labs/lab-04-button-input-pullup/)
- [Lab 5 — PWM Fade with Non-blocking Timing](labs/lab-05-pwm-fade/)
- [Lab 6 — LDR Dark-Activated Lamp with Hysteresis](labs/lab-06-ldr-dark-lamp/)
- [Lab 7 — Potentiometer-Controlled Servo](labs/lab-07-pot-servo/)
- [Lab 8 — Ultrasonic Distance with Timeout](labs/lab-08-ultrasonic-distance/)
- [Lab 9 — PIR Motion-Activated Light](labs/lab-09-pir-motion-light/)
- [Lab 10 — DHT11 Temperature and Humidity Monitor](labs/lab-10-dht-monitor/)
- [Lab 11 — Stepper Motor Position Control](labs/lab-11-stepper-position/)
- [Lab 12 — DHT Fan Controller with Hysteresis](labs/lab-12-dht-fan-controller/)

Each lab folder has a detailed README, a starter `.ino`, a complete solution `.ino` and a lightweight `verify.py`.

## Repository structure

```
courseware/
  Arduino Masterclass-v1.0.pptx / .pdf   Trainer slide deck
  LG-Arduino Masterclass.docx / .pdf     Learner Guide
  LP-Arduino Masterclass.docx / .pdf     Lesson Plan
labs/                                    12 self-contained Arduino labs
LG-Arduino Masterclass.md                Searchable Markdown mirror of the Learner Guide
```

## Public/private boundary

This repository publishes the current slide deck, Lesson Plan, Learner Guide and labs. Credentials, `.env` files, superseded versions, source references and private build tooling are deliberately excluded.

## Provider

Courseware by [Tertiary Infotech Academy Pte Ltd](https://www.tertiaryinfotech.com/) (UEN 201200696W).
