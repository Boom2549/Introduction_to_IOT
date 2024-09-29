//declare variables for the motor pins
int motorPin1 = 8;     // Blue
int motorPin2 = 9;     // Pink
int motorPin3 = 10;    // Yellow
int motorPin4 = 11;    // Orange
                       // Red
int motorSpeed = 50;  //variable to set stepper speed
int stepCount = 0;     // number of steps the motor has taken
void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(115200);  // initialize the serial port:
}
void loop() {
  wavedrive();  // จ่ายไฟให ้ทํางานครั้งละ 1 ขด
  //fullstep();   // จ่ายไฟให ้ทํางานครั้งละ 2 ขด
  //halfstep();   // ใชทั้งสองแบบรวมกันทําให ้หมุนได ้ครั้งละครึ่งเสตป ้

  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
}
void wavedrive()
{
 // 1
 digitalWrite(motorPin4, 0);
 digitalWrite(motorPin3, 0);
 digitalWrite(motorPin2, 0);
 digitalWrite(motorPin1, 1);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPin4, 0);
 digitalWrite(motorPin3, 0);
 digitalWrite(motorPin2, 1);
 digitalWrite(motorPin1, 0);
 delay(motorSpeed);
 // 3
 digitalWrite(motorPin4, 0);
 digitalWrite(motorPin3, 1);
 digitalWrite(motorPin2, 0);
 digitalWrite(motorPin1, 0);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPin4, 1);
 digitalWrite(motorPin3, 0);
 digitalWrite(motorPin2, 0);
 digitalWrite(motorPin1, 0);
 delay(motorSpeed);
}