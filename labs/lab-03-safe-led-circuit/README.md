# Lab 3: Safe LED Circuit and Ohm's Law

Alignment: **LO2**<br>
Estimated time: **10 minutes**

## Objective

Calculate and build a current-limited LED circuit within an Arduino digital pin's electrical boundary.

## Deliverable

A documented 5 V digital-output circuit using a 330 ohm resistor and measured LED voltage.

## Components

- Arduino Uno or Maker UNO
- Breadboard
- LED
- 330 ohm resistor
- Jumper wires
- Multimeter

## Wiring contract

| From | To | Purpose |
|---|---|---|
| D7 | 330 ohm resistor | Series current limit |
| Resistor | LED anode | Long lead |
| LED cathode | GND | Short lead / flat edge |

## Procedure

1. Calculate R=(5 V-2 V)/0.01 A and explain why 330 ohm is a safe standard value.
2. Build the series path D7 -> resistor -> LED -> GND with power disconnected.
3. Upload the sketch and verify the LED toggles once per second.
4. Measure LED forward voltage while ON and calculate the observed current from the resistor voltage.

## Files

- `starter/safe_led_circuit.ino` - learner starter with TODO markers.
- `solution/safe_led_circuit.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] LED polarity is correct
- [ ] A current-limiting resistor is in series
- [ ] LED toggles at 1 Hz
- [ ] Calculated current remains close to or below 10 mA

## Troubleshooting

- **LED never lights:** Reverse the LED and confirm D7 is connected through the resistor to the anode.
- **LED very dim:** Measure the supply and forward voltage; confirm the resistor is 330 ohm, not 330 kilohm.
- **Board resets:** Disconnect immediately and check for a short between 5 V and GND.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
