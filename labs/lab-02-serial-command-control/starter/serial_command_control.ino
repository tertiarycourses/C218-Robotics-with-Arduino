String command;
bool ledOn = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("READY: ON | OFF | STATUS");
}

void loop() {
  // TODO: read one newline-terminated command, normalise it,
  // update ledOn only for valid commands, then report the state.
}
