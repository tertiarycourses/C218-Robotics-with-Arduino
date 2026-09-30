# Lab 11: Stepper Motor Position Control

Alignment: **LO5**<br>
Estimated time: **10 minutes**

## Objective

Drive a four-phase stepper through a transistor array and relate commanded steps to angular position.

## Deliverable

A 28BYJ-48/ULN2003 actuator that moves one revolution forward and backward at a bounded speed.

## Components

- Arduino Uno or Maker UNO
- 28BYJ-48 stepper
- ULN2003 driver board
- External 5 V supply
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| D8-D11 | ULN2003 IN1-IN4 | Phase controls |
| ULN2003 5 V | External 5 V | Motor power |
| ULN2003 GND | Arduino GND | Common reference |
| Stepper | ULN2003 socket | Keyed connector |

## Procedure

1. Connect the driver inputs in the library sequence and establish common ground.
2. Upload the sketch with STEPS_PER_REV set for the supplied motor/gearbox.
3. Mark the shaft, observe one forward and one reverse revolution, and record position error.
4. Increase speed modestly and identify the point where the motor begins to miss steps.

## Files

- `starter/stepper_position.ino` - learner starter with TODO markers.
- `solution/stepper_position.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Motor completes a forward and reverse move
- [ ] Direction reverses correctly
- [ ] Driver—not Arduino I/O—supplies coil current
- [ ] Grounds are common and board remains stable

## Troubleshooting

- **Motor vibrates:** Check IN1-IN4 order and use the phase order required by the library/driver.
- **Weak torque:** Use a suitable external 5 V supply and lower the speed.
- **Wrong angle:** Calibrate STEPS_PER_REV for the actual gearbox and stepping mode.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
