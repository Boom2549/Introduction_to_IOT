int led = 6;
int fade = 5;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i<=255; i+=fade) {
    analogWrite(led, i);
    delay(100);
    Serial.println(i);
  }
  for(int i = 255; i>=0; i-=fade) {
    analogWrite(led, i);
    delay(100);
    Serial.println(i);
  }
  
}
