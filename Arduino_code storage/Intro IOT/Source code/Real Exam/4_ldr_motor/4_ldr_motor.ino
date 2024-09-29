//declare variables for the motor pins
int motorPin1 = 8;      // Blue
int motorPin2 = 9;      // Pink
int motorPin3 = 10;     // Yellow
int motorPin4 = 11;     // Orange
                        // Red
int motorSpeed = 2500;  //variable to set stepper speed     small amount of number
int stepCount = 0;      // number of steps the motor has taken

void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1) {
  digitalWrite(motorPin4, pin4);
  digitalWrite(motorPin3, pin3);
  digitalWrite(motorPin2, pin2);
  digitalWrite(motorPin1, pin1);
  delayMicroseconds(motorSpeed);
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

void stop() {
  motor_drive(0, 0, 0, 0);
  motor_drive(0, 0, 0, 0);
  motor_drive(0, 0, 0, 0);
  motor_drive(0, 0, 0, 0);
}

void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int temp = analogRead(A5);
  Serial.println(temp);
  if (temp <= 500) {
    fullstep();
    Serial.print("steps:");
    Serial.println(stepCount);
    stepCount++;
    if (stepCount == 1530) {
      stop();
      stepCount = 0;
      delay(5000);
    }
  }
  else if (temp >= 600 && temp <= 800) {
    Serial.print("steps:");
    Serial.println(stepCount);
    stop();
    stepCount = 0;
  }
  else if (temp > 900) {
    reverse_fullstep();
    Serial.print("steps:");
    Serial.println(stepCount);
    int stepCount_re = 0;
    stepCount_re--;
    if (stepCount == -1020) {
      stop();
      stepCount = 0;
      delay(5000);
    }
  }
}
