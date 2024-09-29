int led1 = 7;
int led2 = 8;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, 1);
  digitalWrite(led2, 1);
  delay(250);
  digitalWrite(led2, 0);
  delay(250);
  digitalWrite(led1, 0);
  digitalWrite(led2, 1);
  delay(250);
  digitalWrite(led2, 0);
  delay(250);
}