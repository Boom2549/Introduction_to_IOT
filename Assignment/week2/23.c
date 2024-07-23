//23

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
  int Temp = analogRead(A0);
  Serial.println(Temp);
  //none
  if (Temp > 750) {
    digitalWrite(led9, 0);
    digitalWrite(led10, 0);
    digitalWrite(led11, 0);
  }
  //blue switch3
  else if (Temp > 715) {
    digitalWrite(led9, 0);
    digitalWrite(led10, 0);
    digitalWrite(led11, 1);
  }
  //green switch2
  else if (Temp > 705) {
    digitalWrite(led9, 0);
    digitalWrite(led10, 1);
    digitalWrite(led11, 0);
  } 
  //red switch1
  else if (Temp > 510) {
    digitalWrite(led9, 1);
    digitalWrite(led10, 0);
    digitalWrite(led11, 0);
  }  
}
