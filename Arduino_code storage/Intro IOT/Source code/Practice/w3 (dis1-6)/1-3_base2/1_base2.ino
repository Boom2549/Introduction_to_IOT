#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

uint8_t frame[8][12] = {
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 }
};

void setup() {
  matrix.begin();
}

void test() {
  frame[0][0] = 1;
}

void t() {
  frame[0][0] = 0;
}

void loop() {
  test();
  matrix.renderBitmap(frame, 8, 12);
  delay(100);
  t();
  matrix.renderBitmap(frame, 8, 12);
  delay(100);
}