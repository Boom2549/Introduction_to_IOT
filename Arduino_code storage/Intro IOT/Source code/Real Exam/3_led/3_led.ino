int led1 = 10;
int led2 = 11;
int bt = 12;

void setup() {

  pinMode(bt, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}
void pressed() {
  digitalWrite(led1, 1);
  digitalWrite(led2, 0);
}
void unpressed() {
  digitalWrite(led1, 1);
  digitalWrite(led2, 1);
  delay(1000);
  digitalWrite(led2, 0);
  delay(1000);
  digitalWrite(led2, 1);
  delay(1000);
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  delay(1000);
  digitalWrite(led2, 1);
  delay(1000);
  digitalWrite(led2, 0);
  delay(1000);
}
//T1 = 6s, T1on-off = 3
//T2 = 2s, T2on-off = 1
void loop() {
  int status = digitalRead(bt);
  Serial.println(status);

  if (status == 0) {
    pressed();
  }
  else {
    unpressed();
  }
}