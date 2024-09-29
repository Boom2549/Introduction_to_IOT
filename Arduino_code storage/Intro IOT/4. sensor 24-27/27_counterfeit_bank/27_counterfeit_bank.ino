int led = 13;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int signal = analogRead(A5);
  Serial.println(signal);
  if (signal < 100)
    digitalWrite(led, 1);
  else
    digitalWrite(led, 0);
}
