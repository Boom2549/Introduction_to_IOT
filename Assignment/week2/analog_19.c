//19
int led9 = 9, led10 = 10;

void setup()
{
  Serial.begin(115200);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop()
{
  int Temp = analogRead(Temp);
  Serial.println(Temp);

  if (Temp < 500) {
    digitalWrite(led9, 1);
    digitalWrite(led10, 0);
  }else{
    digitalWrite(led9, 0);
    digitalWrite(led10, 1);
  }
}
