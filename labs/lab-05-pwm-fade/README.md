# Lab 5: PWM Fade with Non-blocking Timing

Alignment: **LO2**<br>
Estimated time: **15 minutes**

## Objective

Relate 8-bit PWM values to duty cycle and vary LED brightness without blocking other logic.

## Deliverable

A triangular 0-255 PWM ramp on D9 with calculated duty-cycle checkpoints.

## Components

- Arduino Uno or Maker UNO
- LED
- 330 ohm resistor
- Breadboard
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| D9 (~) | 330 ohm resistor | PWM output |
| Resistor | LED anode | Series |
| LED cathode | GND | Return |

## Procedure

1. Move the LED circuit to PWM-capable pin D9 and confirm the tilde marking/pin map.
2. Upload the non-blocking fade sketch and monitor the brightness value at key checkpoints.
3. Calculate duty cycle for values 64, 128, and 192 using value/255 x 100%.
4. Change STEP to 15 and compare the smoothness and cycle duration.

## Files

- `starter/pwm_fade.ino` - learner starter with TODO markers.
- `solution/pwm_fade.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] LED fades up and down continuously
- [ ] No delay() is used in loop()
- [ ] Value never exceeds 0-255
- [ ] Calculated 128 duty cycle is approximately 50%

## Troubleshooting

- **No fade:** Confirm the LED is on a PWM pin such as D9, not a non-PWM pin.
- **Brightness jumps:** Reduce STEP or shorten UPDATE_MS.
- **Value wraps:** Reverse direction before the integer crosses the 0 or 255 bounds.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
