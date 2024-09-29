#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
void setup() {
 matrix.begin();
}
const uint32_t heart[] = {
	0xd812,
	0x41041040,
	0x88070000,
	66
};
const uint32_t pad[] = {
  0x8,
	0x80500000,
	0x50088000,
	66
};

void loop(){
 matrix.loadFrame(heart);
 delay(500);
 matrix.loadFrame(pad);
 delay(500);
}