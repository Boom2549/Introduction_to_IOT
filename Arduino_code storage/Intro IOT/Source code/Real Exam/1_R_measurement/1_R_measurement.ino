//25


void setup() {
  Serial.begin(115200);
}

void loop() {
  float temp = analogRead(A5);
  float V = temp / 1023 * 5;
  float R = 10000 * (temp / (1023.0 - temp));
  //float R = ((V / 5) - 1) * 10000;
  Serial.print("V : ");
  Serial.println(V);
  Serial.print("R = ");
  Serial.println(R);


 /* if (R <=-13400)
    R+=16400;
  else if (R <= -19700)
    R+=30000;*/






  delay(250);
}