//26

int led = 8;
void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop()
{
  int temp = analogRead(A1);
  Serial.println(temp);
  if (temp < 200)
    digitalWrite(led, 1);
  else
    digitalWrite(led, 0);
}