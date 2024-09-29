//declare variables for the motor pins
int motorPin1 = 8;     // Blue
int motorPin2 = 9;     // Pink
int motorPin3 = 10;    // Yellow
int motorPin4 = 11;    // Orange
                       // Red
int motorSpeed = 1500; //variable to set stepper speed (microseconds)
int stepCount = 0;     // number of steps the motor has taken

void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(115200);  // initialize the serial port:
}
void loop() {
  //wavedrive();  // จ่ายไฟให ้ทํางานครั้งละ 1 ขด
  //fullstep();   // จ่ายไฟให ้ทํางานครั้งละ 2 ขด
  halfstep();   // ใชทั้งสองแบบรวมกันทําให ้หมุนได ้ครั้งละครึ่งเสตป ้

  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
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