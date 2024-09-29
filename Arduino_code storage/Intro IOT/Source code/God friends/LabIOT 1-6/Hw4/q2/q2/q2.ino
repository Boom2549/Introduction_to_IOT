int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 0
const int PIN_RED   = 9;
const int PIN_GREEN = 10;
const int PIN_BLUE  = 11;

int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(9600);    // setup serial communication
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);   // debug value

  if(val < 400) {
    analogWrite(PIN_RED,   0);
    analogWrite(PIN_GREEN, 240);
    analogWrite(PIN_BLUE,  150);
  }
  else if(val < 450) {
    analogWrite(PIN_RED,   170);
    analogWrite(PIN_GREEN, 160);
    analogWrite(PIN_BLUE,  204);
  }
  else if(val < 500) {
    analogWrite(PIN_RED,   20);
    analogWrite(PIN_GREEN, 150);
    analogWrite(PIN_BLUE,  200);
  }
  else if(val < 550) {
    analogWrite(PIN_RED,   250);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE,  250);
  }
  else if(val < 600) {
    analogWrite(PIN_RED,   250);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE,  0);
  }
  else if(val < 670) {
    analogWrite(PIN_RED,   0);
    analogWrite(PIN_GREEN, 250);
    analogWrite(PIN_BLUE,  0);
  }
  else {
    analogWrite(PIN_RED,   250);
    analogWrite(PIN_GREEN, 250);
    analogWrite(PIN_BLUE,  250);
  }
}
