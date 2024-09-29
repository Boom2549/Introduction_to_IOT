#include "Arduino_LED_Matrix.h" // Include the LED_Matrix Library
ArduinoLEDMatrix matrix; // Create an instance of the ArduinoLEDMatrix class
uint8_t frame[8][12] = {
 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 { 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
 { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 },
 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
 { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
 { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
 { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
}; // Pre-defined 2D array
void setup() {
 matrix.begin(); // Initialize LED matrix
}
void smile(){
 frame[3][5] = 1;
 frame[3][7] = 1;
}
void face(){
 frame[3][5] = 0;
 frame[3][7] = 0;
}
void loop(){
face();
matrix.renderBitmap(frame, 8, 12); // Display pattern on the LED matrix
delay(1000);
smile();
matrix.renderBitmap(frame, 8, 12);
delay(1000);
}