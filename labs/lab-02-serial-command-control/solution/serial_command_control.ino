String command;
bool ledOn = false;

void applyOutput() {
  digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  applyOutput();
  Serial.begin(9600);
  Serial.println("READY: ON | OFF | STATUS");
}

void loop() {
  if (Serial.available() == 0) return;
  command = Serial.readStringUntil('\n');
  command.trim();
  command.toUpperCase();
  if (command == "ON") ledOn = true;
  else if (command == "OFF") ledOn = false;
  else if (command == "STATUS") { /* report only */ }
  else { Serial.println("ERR"); return; }
  applyOutput();
  Serial.println(ledOn ? "LED=ON" : "LED=OFF");
}
