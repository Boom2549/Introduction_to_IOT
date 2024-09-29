// 1) Using motor organizing 0 and 1 on 7segment

int segA = 1;
int segB = 2;
int segC = 3;
int segD = 4;
int segE = 5;
int segF = A0;
int segG = A1;
int segDP = A2;
int motorPin1 = 8;      // Blue
int motorPin2 = 9;      // Pink
int motorPin3 = 10;     // Yellow
int motorPin4 = 11;     // Orange
                        // Red
int motorSpeed = 2500;  //variable to set stepper speed (microseconds)
int stepCount = 0;      // number of steps the motor has taken

void setup() {
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(115200);  // initialize the serial port:
}

void zero() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}
void one() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDP, LOW);
}
void two() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void three() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void four() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void five() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void six() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 0);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}
void seven() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 0);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}
void eight() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}
void nine() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}
void off() {
  digitalWrite(segA, 0);
  digitalWrite(segB, 0);
  digitalWrite(segC, 0);
  digitalWrite(segD, 0);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}


void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1) {
  digitalWrite(motorPin4, pin4);
  digitalWrite(motorPin3, pin3);
  digitalWrite(motorPin2, pin2);
  digitalWrite(motorPin1, pin1);
  delayMicroseconds(motorSpeed);
}

void wavedrive() {
  motor_drive(1, 0, 0, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 0, 0, 1);
}

void reverse_wavedrive() {
  motor_drive(0, 0, 0, 1);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(1, 0, 0, 0);
}

void fullstep() {
  motor_drive(1, 1, 0, 0);
  motor_drive(0, 1, 1, 0);
  motor_drive(0, 0, 1, 1);
  motor_drive(1, 0, 0, 1);
}

void reverse_fullstep() {
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 1, 1, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(1, 0, 0, 1);
}

void halfstep() {
  motor_drive(1, 0, 0, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(0, 1, 1, 0);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 0, 0, 1);
  motor_drive(1, 0, 0, 1);
}

void reverse_halfstep() {
  motor_drive(1, 0, 0, 1);
  motor_drive(0, 0, 0, 1);
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 1, 1, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(1, 0, 0, 0);
}

void loop() {
  //cw
  for(int i = 1; i<=255; i++) {
    halfstep();
    one();
  }
  off();
  delay(1000);
  //ccw
  for(int i = 1; i<=255; i++) {
    reverse_halfstep();
    zero();
  }
  off();
  delay(1000);
}