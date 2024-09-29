#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11

void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0x66997B85: Serial.print("OK "); break;
      case 0x6F907B85: Serial.print("LEFT "); break;
      case 0x7D827B85: Serial.print("RIGHT "); break;
      case 0x7E817B85: Serial.print("FORWARD "); break;
      case 0x77887B85: Serial.print("REVERSE "); break;
      case 0x78877B85: Serial.print("1 "); break;
      case 0x79867B85: Serial.print("2 "); break;
      case 0x7A857B85: Serial.print("3 "); break;
      case 0x748B7B85: Serial.print("4 "); break;
      case 0x758A7B85: Serial.print("5 "); break;
      case 0x76897B85: Serial.print("6 "); break;
      case 0x708F7B85: Serial.print("7 "); break;
      case 0x718E7B85: Serial.print("8 "); break;
      case 0x728D7B85: Serial.print("9 "); break;
      case 0x6D927B85: Serial.print("0 "); break;
      case 0x6C937B85: Serial.print("* "); break;
      case 0x7F807B85: Serial.print("# "); break;
      case 0x609F7B85: Serial.print("REPEAT "); break;
      default: Serial.print("other button ");
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
}