# Lab 7: Potentiometer-Controlled Servo

Alignment: **LO3**<br>
Estimated time: **15 minutes**

## Objective

Map a 10-bit ADC measurement to a bounded servo command while respecting the servo power boundary.

## Deliverable

A 0-180 degree servo position controller with clamped input and separate-power guidance.

## Components

- Arduino Uno or Maker UNO
- 10 kilohm potentiometer
- SG90 servo
- External regulated 5 V supply recommended
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| Pot outer pins | 5 V and GND | Divider |
| Pot wiper | A0 | ADC input |
| Servo signal | D9 | Control pulse |
| Servo V+ | Regulated 5 V | Do not overload I/O pin |
| All grounds | Common GND | Signal reference |

## Procedure

1. Wire the potentiometer divider and confirm A0 spans most of 0-1023.
2. Connect the servo signal to D9 and establish a common ground with its power source.
3. Upload the solution, rotate slowly, and verify commanded angle follows the knob.
4. Test the endpoints and confirm constrain() prevents commands outside 0-180 degrees.

## Files

- `starter/pot_servo.ino` - learner starter with TODO markers.
- `solution/pot_servo.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] ADC reading changes smoothly
- [ ] Servo follows the potentiometer
- [ ] Command stays within 0-180 degrees
- [ ] Board does not reset when servo moves

## Troubleshooting

- **Servo jitters:** Improve the 5 V supply, common the grounds, and add a capacitor near the servo.
- **Servo moves backward:** Reverse the map output range if required by the application.
- **Board resets:** Power the servo from a suitable external 5 V source rather than an I/O pin.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
