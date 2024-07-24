//24
//RGB = 9.10.11
int led9 = 9, led10 = 10, led11 = 11;
void setup()
{
  Serial.begin(115200);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
}

void loop()
{
  int temp = analogRead(A0);
  Serial.println(temp);
  if (temp > 700)
  {
    digitalWrite(led9, 1);
    digitalWrite(led10, 1);
    digitalWrite(led11, 1);
  }
  else if (temp > 600)
  {
    digitalWrite(led9, 1);
    digitalWrite(led10, 1);
    digitalWrite(led11, 0);
  }
  else if (temp > 500)
  {
    digitalWrite(led9, 1);
    digitalWrite(led10, 0);
    digitalWrite(led11, 1);
  }
  else if (temp > 400)
  {
    digitalWrite(led9, 1);
    digitalWrite(led10, 0);
    digitalWrite(led11, 0);
  }
  else if (temp > 300)
  {
    digitalWrite(led9, 0);
    digitalWrite(led10, 1);
    digitalWrite(led11, 1);
  }
  else if (temp > 200)
  {
    digitalWrite(led9, 0);
    digitalWrite(led10, 1);
    digitalWrite(led11, 0);
  }
  else if (temp > 100)
  {
    digitalWrite(led9, 0);
    digitalWrite(led10, 0);
    digitalWrite(led11, 1);
  }
}
