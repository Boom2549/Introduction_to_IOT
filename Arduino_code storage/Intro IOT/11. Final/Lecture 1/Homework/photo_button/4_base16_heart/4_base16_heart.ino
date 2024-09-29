#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
void setup() {
  matrix.begin();
}
const uint32_t smile[] = {
  0x18c3de7f,
  0xf3fe1fc0,
  0xf8070020,
};
const uint32_t happy[] = {
  0x18c25242,
  0x12021040,
  0x88050020,
};
void loop() {
  matrix.loadFrame(smile);
  delay(500);
  matrix.loadFrame(happy);
  delay(500);
}