# Lab 4: Push Button with INPUT_PULLUP

Alignment: **LO2**<br>
Estimated time: **10 minutes**

## Objective

Eliminate a floating input and debounce a mechanical switch using a stable time window.

## Deliverable

An active-LOW button that toggles an LED once per physical press without double triggers.

## Components

- Arduino Uno or Maker UNO
- Push button
- LED circuit from Lab 3
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| D2 | Push button terminal A | INPUT_PULLUP |
| Push button terminal B | GND | Pressed = LOW |
| D7 | LED + 330 ohm | Output evidence |

## Procedure

1. Place the button across the breadboard centre gap and identify the internally common legs.
2. Wire D2 to one side and GND to the opposite side; do not add an external pull-down.
3. Upload the sketch and press/release the button repeatedly at different speeds.
4. Observe the raw state in Serial Monitor and confirm one LED toggle per accepted press.

## Files

- `starter/button_input_pullup.ino` - learner starter with TODO markers.
- `solution/button_input_pullup.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Released input reads HIGH
- [ ] Pressed input reads LOW
- [ ] LED toggles once per press
- [ ] Bounce within 30 ms does not create extra toggles

## Troubleshooting

- **Input always LOW:** Check that D2 and GND are not on the same internally connected button leg.
- **Random triggers:** Confirm INPUT_PULLUP is used and all grounds are common.
- **Double toggles:** Increase DEBOUNCE_MS slightly and ensure only the falling edge toggles state.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
