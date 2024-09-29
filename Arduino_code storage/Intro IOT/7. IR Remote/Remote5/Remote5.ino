#include <IRremote.h>  // Include the library
IRsend irsend;
int key = A4;  // KEY pin
int led = A5;
unsigned long codeSony = 0xa90;      // Sony TV power code
int codeLenSony = 12;                // the length of the code
unsigned long codeNEC = 0x1234ABCD;  // NEC code
int codeLenNEC = 32;                 // the length of the code
void setup() {
  pinMode(led, OUTPUT);
  pinMode(key, INPUT_PULLUP);
}
void loop() {
  if (digitalRead(key) == HIGH) {
    digitalWrite(led, HIGH);                 // turn LED on
    irsend.sendSony(codeSony, codeLenSony);  // Sony code
    delay(1000);
    irsend.sendNEC(codeNEC, codeLenNEC);  // NEC code
    delay(1000);
    digitalWrite(led, LOW);  // turn LED off
  }
}