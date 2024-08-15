int receiver = A4;
int red = 1;
int yellow = 11;
int green = 12;


void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  int signal = analogRead(receiver);
  Serial.println(signal);
  if(signal>0 && signal<=500)
  {
    digitalWrite(red, 1);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);
  }else if(signal>500 && signal<=600)
  {
    digitalWrite(red, 0);
    digitalWrite(yellow, 1);
    digitalWrite(green, 0);
  }
  if(signal>700)
  {
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(green, 1);
  }
  else
  {
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);
  }
}




