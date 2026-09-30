# Lab 9: PIR Motion-Activated Light

Alignment: **LO4**<br>
Estimated time: **10 minutes**

## Objective

Use a digital motion sensor contract and a non-blocking hold timer to control a light.

## Deliverable

A motion light that extends its ON period when new motion arrives and expires safely after five seconds.

## Components

- Arduino Uno or Maker UNO
- HC-SR501 PIR sensor
- LED + 330 ohm
- Breadboard
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| PIR VCC | 5 V | Supply |
| PIR GND | GND | Return |
| PIR OUT | D2 | Digital input |
| D7 | LED circuit | Light output |

## Procedure

1. Wire the PIR and allow its warm-up/calibration interval after power-up.
2. Upload the sketch and move across the sensor field of view.
3. Trigger motion again before five seconds expires and confirm the hold timer extends.
4. Remain still and verify the output turns OFF after the bounded hold period.

## Files

- `starter/pir_motion_light.ino` - learner starter with TODO markers.
- `solution/pir_motion_light.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Motion drives the output HIGH
- [ ] Output remains ON for five seconds after the latest motion
- [ ] New motion extends the timer
- [ ] loop() remains responsive without delay(5000)

## Troubleshooting

- **Always HIGH:** Wait for warm-up and check the sensor retrigger jumper and sensitivity settings.
- **No detection:** Confirm OUT reaches D2 and walk laterally across the field of view.
- **Light turns off too soon:** Update lastMotionMs every time the PIR is HIGH.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
