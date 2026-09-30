# Lab 6: LDR Dark-Activated Lamp with Hysteresis

Alignment: **LO3**<br>
Estimated time: **15 minutes**

## Objective

Convert a light-dependent voltage divider into a stable two-threshold control decision.

## Deliverable

A calibrated dark-activated lamp that avoids chatter around the switching threshold.

## Components

- Arduino Uno or Maker UNO
- LDR
- 10 kilohm resistor
- LED + 330 ohm
- Breadboard
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| 5 V | LDR | Divider top |
| LDR/resistor junction | A0 | ADC input |
| 10 kilohm resistor | GND | Divider bottom |
| D7 | LED circuit | Lamp output |

## Procedure

1. Build the divider and record A0 values under bright, room, and covered conditions.
2. Choose ON_THRESHOLD below the dark value and OFF_THRESHOLD above it to create a dead band.
3. Upload the solution and slowly shade the LDR while observing state and ADC evidence.
4. Explain why one threshold would chatter when readings contain noise.

## Files

- `starter/ldr_dark_lamp.ino` - learner starter with TODO markers.
- `solution/ldr_dark_lamp.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Serial output shows plausible 0-1023 readings
- [ ] Lamp turns ON in dark conditions
- [ ] Lamp turns OFF in bright conditions
- [ ] Output remains stable inside the hysteresis band

## Troubleshooting

- **Reading fixed at 0:** Check A0 is not shorted to GND and the LDR is connected to 5 V.
- **Reading fixed at 1023:** Check the 10 kilohm resistor reaches GND.
- **Logic reversed:** Swap divider orientation or reverse the comparison to match measured calibration.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
