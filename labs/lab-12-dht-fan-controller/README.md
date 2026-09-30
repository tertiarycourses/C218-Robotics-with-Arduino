# Lab 12: DHT Fan Controller with Hysteresis

Alignment: **LO5**<br>
Estimated time: **10 minutes**

## Objective

Integrate measurement, decision logic, and a protected continuous-drive actuator into a feedback controller.

## Deliverable

A temperature-controlled DC fan with MOSFET switching, flyback protection, PWM drive, and hysteresis.

## Components

- Arduino Uno or Maker UNO
- DHT11
- Logic-level N-channel MOSFET
- DC fan/motor
- Flyback diode
- External motor supply
- Jumper wires

## Wiring contract

| From | To | Purpose |
|---|---|---|
| DHT DATA | D2 | Measurement |
| D5 PWM | MOSFET gate through 220 ohm | Control |
| 10 kilohm | Gate to GND | Safe default OFF |
| Motor/fan | External supply + MOSFET drain | Power path |
| Flyback diode | Across motor | Cathode to supply + |
| All grounds | Common GND | Reference |

## Procedure

1. Build the low-side MOSFET driver with power disconnected and verify diode polarity.
2. Upload the controller and confirm the fan is OFF below FAN_ON_C.
3. Warm the DHT11 above the ON threshold and observe full PWM drive.
4. Let the sensor cool below FAN_OFF_C and confirm the fan does not chatter between thresholds.

## Files

- `starter/dht_fan_controller.ino` - learner starter with TODO markers.
- `solution/dht_fan_controller.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Fan turns ON above 30 C
- [ ] Fan remains ON until temperature falls below 28 C
- [ ] Invalid DHT read leaves the previous safe state and reports an error
- [ ] Motor current never flows through an Arduino I/O pin

## Troubleshooting

- **Fan never starts:** Check external supply, common ground, MOSFET pinout, and gate drive.
- **Arduino resets:** Separate motor power, add decoupling, and verify flyback diode orientation.
- **Fan chatters:** Use distinct ON/OFF thresholds and a realistic sample interval.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
