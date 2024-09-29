int led1 = 9;
int led2 = 10;

void setup() {
  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

}

void loop() {
  int Temp = analogRead(A0);
  Serial.println(Temp);
  delay(100);
  
  if(Temp<200){
    digitalWrite(led1,1);
    digitalWrite(led2,0);//1,1 1 mean on
  } else{
    digitalWrite(led1,0);
    digitalWrite(led2,1);//1,0 0 mean off
  }
}
