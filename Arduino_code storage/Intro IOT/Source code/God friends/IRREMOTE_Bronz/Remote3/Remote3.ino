#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN A5  // IR receiver pin 11
void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xA05F7F00: Serial.print("OK \n"); break;
      case 0xFD027F00: Serial.print("LEFT \n"); break;
      case 0xBF407F00: Serial.print("RIGHT \n"); break;
      case 0xFC037F00: Serial.print("FORWARD \n"); break;
      case 0xA15E7F00: Serial.print("REVERSE \n"); break;
      case 0xE51A7F00: Serial.print("1 \n"); break;
      case 0xE01F7F00: Serial.print("2 \n"); break;
      case 0xA7587F00: Serial.print("3 \n"); break;
      case 0xE9167F00: Serial.print("4 \n"); break;
      case 0xE41B7F00: Serial.print("5 \n"); break;
      case 0xAB547F00: Serial.print("6 \n"); break;
      case 0xED127F00: Serial.print("7 \n"); break;
      case 0xE8177F00: Serial.print("8 \n"); break;
      case 0xAF507F00: Serial.print("9 \n"); break;
      case 0xEC137F00: Serial.print("0 \n"); break;
      case 0x8E717F00: Serial.print("* \n"); break;
      case 0x8D727F00: Serial.print("# \n"); break;
      case 0xBD427F00: Serial.print("REPEAT \n"); break;
      case 0x6A957F00:
        Serial.println("OPEN_LINK_1");  // Send command to open link 1
        break;
    }
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
}
