# Lab 8: Ultrasonic Distance with Timeout

Alignment: **LO4**<br>
Estimated time: **15 minutes**

## Objective

Measure echo pulse width, convert time-of-flight to distance, and handle a missing echo safely.

## Deliverable

A distance monitor that reports centimetres or NO_ECHO within a bounded 30 ms wait.

## Components

- Arduino Uno or Maker UNO
- HC-SR04/HY-SRF05 ultrasonic sensor
- Breadboard
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| Sensor VCC | 5 V | Supply |
| Sensor GND | GND | Return |
| TRIG | D9 | 10 microsecond output pulse |
| ECHO | D10 | Pulse input |

## Procedure

1. Wire the sensor and confirm the trigger and echo pins are not swapped.
2. Upload the sketch and position a flat target 20-100 cm in front of the sensor.
3. Compare Serial Monitor distance with a ruler at three positions.
4. Remove the target and confirm the 30 ms timeout returns NO_ECHO instead of blocking forever.

## Files

- `starter/ultrasonic_distance.ino` - learner starter with TODO markers.
- `solution/ultrasonic_distance.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Distance is within a reasonable tolerance of the ruler
- [ ] Readings update continuously
- [ ] Missing echo returns NO_ECHO
- [ ] No divide-by-zero or indefinite wait occurs

## Troubleshooting

- **Always NO_ECHO:** Swap TRIG/ECHO if reversed and verify the sensor has 5 V and common GND.
- **Distance doubles:** The conversion must divide the round-trip distance by two.
- **Unstable values:** Use a flat target, avoid soft fabric, and keep within the sensor's working zone.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
