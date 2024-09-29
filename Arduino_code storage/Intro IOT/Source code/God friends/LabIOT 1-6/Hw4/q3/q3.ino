int analogPin = A0; 
int uv = 10;         
int val = 0; 

void setup() {
  Serial.begin(9600);     
  pinMode(uv,OUTPUT);    
}

void loop() {
  val = analogRead(analogPin); 
  Serial.println(val);          
  if(val<900){
    digitalWrite(uv,HIGH);
  }
  else {
      digitalWrite(uv,LOW); 
  }
}
