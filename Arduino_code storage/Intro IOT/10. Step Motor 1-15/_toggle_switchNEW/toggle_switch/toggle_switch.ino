#define bt 12
int motorPin1 = 8;   // Blue
int motorPin2 = 9;   // Pink
int motorPin3 = 10;  // Yellow
int motorPin4 = 11;  // Orange

int motorSpeed = 1500;  //variable to set stepper speed (microseconds)
int stepCount = 0;      // number of steps the motor has taken
int reverseMode = 0;    // integer to toggle motor direction (0 for forward, 1 for reverse)

void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(bt, INPUT_PULLUP);
  Serial.begin(115200);  // initialize the serial port
}

void loop() {
  Serial.println(stepCount);
  stepCount++;

  int status = digitalRead(bt);
  static int lastStatus = HIGH;  // store the last button status

  // Check for a button press (state change from HIGH to LOW)
  if (status == LOW && lastStatus == HIGH) {
    reverseMode = !reverseMode;  // Toggle the direction using integer (0 or 1)
    Serial.print("Direction toggled, reverseMode = ");
    Serial.println(reverseMode);
    delay(200);  // Debouncing delay to prevent multiple toggles
  }

  lastStatus = status;  // Update the last status

  if (reverseMode == 1) {
    reverse_fullstep();  // Reverse motor direction
  } else {
    fullstep();  // Forward motor direction
  }

  Serial.print("steps: ");
  Serial.println(stepCount);
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

