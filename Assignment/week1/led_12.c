//12
int led1 = 9, led2 = 10;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  digitalWrite(led1, 1);
  delay(500);
  digitalWrite(led2, 1);
  delay(250);
  digitalWrite(led1, 0);
  delay(500);
  digitalWrite(led2, 0);
  delay(250);
}
