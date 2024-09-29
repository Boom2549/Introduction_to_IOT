//25

int led1 = 11;
int led2 = 12;
int led3 = 13;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  float temp = analogRead(A5);
  float v = temp / 1023 * 5;
  Serial.println(v);
  if (v>=2.4 && v<=2.6) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  } else if (v>=3.2 && v<=3.5){
  digitalWrite(led1, 0);
  digitalWrite(led2, 1);
  digitalWrite(led3, 0);
  } else if (v>=3.6 && v<=3.8){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
  } else {
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  }
}