# Lab 1: Board Check and Deterministic Blink

Alignment: **LO1**<br>
Estimated time: **15 minutes**

## Objective

Validate the Arduino Uno/Maker UNO toolchain and prove deterministic digital output timing.

## Deliverable

A board-identification record and a 250 ms LED heartbeat that verifies compile, upload, reset, and loop execution.

## Components

- Arduino Uno or Maker UNO
- USB data cable
- Arduino IDE 2.x

## Wiring contract

| From | To | Purpose |
|---|---|---|
| LED_BUILTIN | On-board LED | No external wiring |
| USB | Computer | Power + serial upload |

## Procedure

1. Connect the board using a USB data cable and identify the board/port shown by the IDE.
2. Open the starter sketch and predict the LED period before compiling.
3. Select Arduino Uno and the detected serial port, then compile and upload.
4. Time ten complete blink cycles and compare the observed period with the expected 500 ms cycle.
5. Change INTERVAL_MS to 1000, upload again, and record the changed evidence.

## Files

- `starter/board_check_blink.ino` - learner starter with TODO markers.
- `solution/board_check_blink.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] Sketch compiles with no error
- [ ] Upload completes on the selected port
- [ ] LED cycles 250 ms ON and 250 ms OFF
- [ ] Measured ten-cycle duration is approximately 5 seconds

## Troubleshooting

- **Port missing:** Try a known USB data cable, reconnect, and confirm the CH340/USB serial device.
- **Upload timeout:** Check Board and Port, close Serial Monitor, then press reset before retrying.
- **Wrong timing:** Confirm milliseconds and that both HIGH and LOW paths use INTERVAL_MS.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
