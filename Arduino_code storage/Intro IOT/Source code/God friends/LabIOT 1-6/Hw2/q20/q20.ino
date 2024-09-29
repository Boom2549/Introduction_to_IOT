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
  
  if(Temp<200){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
  } else{
    digitalWrite(led1,0);
    digitalWrite(led2,1);
  }
}
