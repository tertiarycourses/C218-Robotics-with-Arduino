# Lab 2: Serial Command Control

Alignment: **LO1**<br>
Estimated time: **15 minutes**

## Objective

Trace UART data from a typed ASCII command to a validated output state.

## Deliverable

A line-oriented command parser that accepts ON, OFF, and STATUS without blocking indefinitely.

## Components

- Arduino Uno or Maker UNO
- USB data cable
- Arduino IDE Serial Monitor

## Wiring contract

| From | To | Purpose |
|---|---|---|
| LED_BUILTIN | On-board LED | Output |
| USB serial | Computer | 9600 bit/s, newline terminator |

## Procedure

1. Upload the starter sketch and open Serial Monitor at 9600 baud with Newline selected.
2. Send ON, OFF, and STATUS while observing both the LED and acknowledgement text.
3. Send a lowercase command and an invalid command; record how the parser handles each.
4. Disconnect and reconnect the board, then confirm the default output is safe and OFF.

## Files

- `starter/serial_command_control.ino` - learner starter with TODO markers.
- `solution/serial_command_control.ino` - complete reference implementation.
- `verify.py` - checks that the solution contains the expected mechanisms and balanced braces.

## Acceptance checks

- [ ] ON lights the LED
- [ ] OFF extinguishes the LED
- [ ] STATUS reports the true output state
- [ ] Unknown input returns ERR without changing output

## Troubleshooting

- **Garbled text:** Set Serial Monitor to 9600 baud to match Serial.begin().
- **Commands ignored:** Select Newline and confirm the parser removes carriage return/newline characters.
- **LED state wrong:** Read back the maintained ledOn state rather than assuming the command succeeded.

## Run the verifier

```bash
python3 verify.py
```

Full step-by-step context also appears in `../../LG-Arduino Masterclass.md`.
