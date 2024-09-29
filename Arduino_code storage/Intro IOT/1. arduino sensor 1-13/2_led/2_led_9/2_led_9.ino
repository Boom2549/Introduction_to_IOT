//8
int led = 9;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 480; i <= 500; i++){
    int on = 1500 - (i * 3);
    int off = 500 - i;
    digitalWrite(led, 1);
    delay(on);
    digitalWrite(led, 0);
    delay(off);
    Serial.println(i);
  }
  delay(1500);
}
