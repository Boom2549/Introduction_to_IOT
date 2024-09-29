void setup(){
  for(int i=9; i<=13; i++)
    pinMode(i, OUTPUT);
}

void loop(){
  for(int j=13; j>=9; j--)
  {
    digitalWrite(j, 1);
    delay(200);
    digitalWrite(j, 0);
    delay(200);
  }
  for(int k=9; k<=13; k++)
  {
    digitalWrite(k, 1);
    delay(200);
    digitalWrite(k, 0);
    delay(200);
  }
}