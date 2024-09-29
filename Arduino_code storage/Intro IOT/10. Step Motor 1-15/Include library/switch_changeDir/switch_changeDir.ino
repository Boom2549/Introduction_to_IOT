#include <Stepper.h>
int stepsPerRevolution = 2048;  // Number of steps per revolution
int motSpeed = 10;              // Speed of the motor in RPM
int dt = 500;                   // Delay between steps

int buttonPin = 12;             // Pin for the button
int motDir = 1;                 // Motor direction
int buttonValNew;
int buttonValOld = 1;           // Previous button state
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;  // Debounce delay in milliseconds

// Initialize the stepper library with the number of steps per revolution and motor pins
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);  // Set the motor speed
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
}

void loop() {
  // Read the current state of the button
  int reading = digitalRead(buttonPin);

  // Check if the button state has changed
  if (reading != buttonValOld) {
    // Reset the debouncing timer
    lastDebounceTime = millis();
  }

  // Check if the state is stable after debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button is pressed (transition from HIGH to LOW)
    if (buttonValNew == HIGH && reading == LOW) {
      motDir = motDir * -1;  // Reverse the direction of the motor
    }
    buttonValNew = reading;
  }

  // Move the motor one step in the current direction
  myStepper.step(motDir * 1);
  buttonValOld = reading;  // Save the button state for the next loop iteration
}
