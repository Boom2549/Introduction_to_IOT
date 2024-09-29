#include <IRremote.h>
int led = A5;
int IRPin = A4;
int button01 = 10;
int button02 = 11;
int button03 = 12;
int button04 = 13;
IRsend irsend(IRPin);
void setup() {
  pinMode(button01, INPUT);
  pinMode(button02, INPUT);
  pinMode(button03, INPUT);
  pinMode(button04, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(button01) == HIGH) {
    digitalWrite(led, 1);
    unsigned long tData = 0x14C01111;  // 14C0 base 16 = 0328 base 10
    irsend.sendSony(tData, 32);
    delay(500);
    digitalWrite(led, 0);
  }
  if (digitalRead(button02) == HIGH) {
    digitalWrite(led, 1);
    unsigned long tData = 0x14C02222;  // 14C0 base 16 = 0328 base 10
    irsend.sendSony(tData, 32);
    delay(500);
    digitalWrite(led, 0);
  }
  if (digitalRead(button03) == HIGH) {
    digitalWrite(led, 1);
    unsigned long tData = 0x14C03333;  // 14C0 base 16 = 0328 base 10
    irsend.sendSony(tData, 32);
    delay(500);
    digitalWrite(led, 0);
  }
  if (digitalRead(button04) == HIGH) {
    digitalWrite(led, 1);
    unsigned long tData = 0x14C04444;  // 14C0 base 16 = 0328 base 10
    irsend.sendSony(tData, 32);
    delay(500);
    digitalWrite(led, 0);
  }
}