#include <Stepper.h>
int stepsPerRevolution = 2048;  // Number of steps per revolution
int motSpeed = 10;              // Speed of the motor in RPM
int dt = 500;                   // Delay between steps

// Initialize the stepper library with the number of steps per revolution and motor pins
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);  // Set the motor speed
}

void loop() {
  // Move forward one revolution
  myStepper.step(stepsPerRevolution);
  delay(dt);
  
  // Move backward one revolution
  myStepper.step(-stepsPerRevolution);
  delay(dt);
}
