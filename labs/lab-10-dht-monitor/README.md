# Lab 10: DHT11 Temperature and Humidity Monitor

Alignment: **LO5**<br>
Estimated time: **10 minutes**

## Objective

Read a library-managed digital sensor transaction and reject invalid measurements before control use.

## Deliverable

A one-hertz temperature/humidity monitor that identifies NaN failures instead of treating them as real values.

## Components

- Arduino Uno or Maker UNO
- DHT11 module
- 10 kilohm pull-up if using a bare sensor
- Jumper wires
- Adafruit DHT sensor library

## Wiring contract

| From | To | Purpose |
|---|---|---|
| DHT VCC | 5 V | Supply |
| DHT GND | GND | Return |
| DHT DATA | D2 | Digital data |
| DATA to VCC | 10 kilohm | Pull-up for bare sensor |

## Procedure

1. Install the Adafruit DHT sensor library and its required dependency from Library Manager.
2. Wire the DHT11 and upload the monitor sketch.
3. Warm the sensor gently and observe the change without touching exposed conductors.
4. Disconnect DATA briefly and confirm the sketch reports READ_ERROR rather than a numeric control value.

## Files

- `starter/dht_monitor.ino` - learner starter with TODO markers.
- `solution/dht_monitor.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Temperature and humidity update approximately once per second
- [ ] Values are plausible for the room
- [ ] Disconnected/failed read reports READ_ERROR
- [ ] dht.begin() is called in setup()

## Troubleshooting

- **READ_ERROR:** Check sensor type, D2 wiring, pull-up, common ground, and the two-second minimum sample interval if needed.
- **Values never change:** Avoid reading faster than the sensor supports and confirm the correct DHT type.
- **Compile error:** Install both the DHT sensor library and Adafruit Unified Sensor dependency.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
