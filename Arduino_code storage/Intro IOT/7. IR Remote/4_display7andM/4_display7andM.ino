#include <IRremote.hpp>  // Include the library
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;   
#define IR_RECEIVE_PIN 11  
int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;

int digit1 = 10;    //1000
int digit2 = 9;     //100
int digit3 = 6;     //10
int digit4 = 5;     //1

void setup() {
  matrix.begin();
  Serial.begin(9600);                                     // เมื่อไหร่จะทำเสร็จ
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // ลูกอีหน่อแตด
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
}
const uint32_t okay[] = {
  0xfa28a48a,
  0x88b08a88,
  0xa48a2fa1,
};
const uint32_t leftarrow[] = {
  0x400c03f,
  0xf7ff7ff3,
  0xff0c0040,
};
const uint32_t rightarrow[] = {
  0x20030ff,
  0xcffeffef,
  0xfc030020,
};
const uint32_t uparrow[] = {
  0x600f00f,
  0x1f83fc0,
  0xf00f00f0,
};
const uint32_t downarrow[] = {
  0xf00f00f,
  0x3fc1f80,
  0xf00f0060,
};
const uint32_t one[] = {
  0x601e01e,
  0x600600,
  0x600601f8,
};
const uint32_t two[] = {
  0xf01f01b,
  0x300700,
  0x600f01f8,
};
const uint32_t three[] = {
  0x1f81f801,
  0x81f81f80,
  0x181f81f8,
};
const uint32_t four[] = {
  0x19819819,
  0x81fc1fc0,
  0x18018018,
};
const uint32_t five[] = {
  0x1f81f818,
  0x1f81f80,
  0x181f81f8,
};
const uint32_t six[] = {
  0x1f81f818,
  0x1f81f81,
  0x981f81f8,
};
const uint32_t seven[] = {
  0xfc0fc00,
  0xc01c0380,
  0x300600e0,
};
const uint32_t eight[] = {
  0x1f81f810,
  0x81f81f81,
  0x81f81f8,
};
const uint32_t nine[] = {
  0x1f81f819,
  0x81f81f80,
  0x18018018,
};
const uint32_t zero[] = {
  0x1f81f819,
  0x81981981,
  0x981f81f8,
};
const uint32_t dot[] = {
  0x26436c1f,
  0x87fe7fe1,
  0xf836c264,
};
const uint32_t hastax[] = {
  0x1987fe7f,
  0xe1981987,
  0xfe7fe188,
};
const uint32_t home[] = {
  0x1f820440,
  0x28018018,
  0xf1891f9f,
};
const uint32_t netflix[] = {
  0x71c79c7d,
  0xc7fc7fc7,
  0x7c73c71c,
};
const uint32_t black[] = {
  0x0,
  0x0,
  0x0,
};
void A() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 0);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void B() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void C() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 0);
  digitalWrite(segmentC, 0);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 0);
  digitalWrite(segmentDP, 0);
}
void D() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 0);
  digitalWrite(segmentDP, 0);
}
void E() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 0);
  digitalWrite(segmentC, 0);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void F() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 0);
  digitalWrite(segmentC, 0);
  digitalWrite(segmentD, 0);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void zero0() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 0);
  digitalWrite(segmentDP, 0);
}
void one1() {
  digitalWrite(segmentA, 0);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 0);
  digitalWrite(segmentE, 0);
  digitalWrite(segmentF, 0);
  digitalWrite(segmentG, 0);
  digitalWrite(segmentDP, 0);
}
void two2() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 0);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 0);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void three3() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 0);
  digitalWrite(segmentF, 0);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void four4() {
  digitalWrite(segmentA, 0);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 0);
  digitalWrite(segmentE, 0);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void five5() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 0);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 0);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void six6() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 0);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void seven7() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 0);
  digitalWrite(segmentE, 0);
  digitalWrite(segmentF, 0);
  digitalWrite(segmentG, 0);
  digitalWrite(segmentDP, 0);
}
void eight8() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 1);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void nine9() {
  digitalWrite(segmentA, 1);
  digitalWrite(segmentB, 1);
  digitalWrite(segmentC, 1);
  digitalWrite(segmentD, 1);
  digitalWrite(segmentE, 0);
  digitalWrite(segmentF, 1);
  digitalWrite(segmentG, 1);
  digitalWrite(segmentDP, 0);
}
void off() {
  digitalWrite(digit1, 0);
  digitalWrite(digit2, 0);
  digitalWrite(digit3, 0);
  digitalWrite(digit4, 0);
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0x66997B85:
        Serial.print("OK \n");
        matrix.loadFrame(okay);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              nine9();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x6F907B85:
        Serial.print("LEFT \n");
        matrix.loadFrame(leftarrow);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              F();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              zero0();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x7D827B85:
        Serial.print("RIGHT \n");
        matrix.loadFrame(rightarrow);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              D();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              two2();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x7E817B85:
        Serial.print("FORWARD \n");
        matrix.loadFrame(uparrow);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              E();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              one1();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x77887B85:
        Serial.print("REVERSE \n");
        matrix.loadFrame(downarrow);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              eight8();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x78877B85:
        Serial.print("1 \n");
        matrix.loadFrame(one);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              seven7();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x79867B85:
        Serial.print("2 \n");
        matrix.loadFrame(two);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              six6();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x7A857B85:
        Serial.print("3 \n");
        matrix.loadFrame(three);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              A();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              five5();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x748B7B85:
        Serial.print("4 \n");
        matrix.loadFrame(four);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              four4();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              B();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x758A7B85:
        Serial.print("5 \n");
        matrix.loadFrame(five);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              five5();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              A();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x76897B85:
        Serial.print("6 \n");
        matrix.loadFrame(six);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              nine9();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x708F7B85:
        Serial.print("7 \n");
        matrix.loadFrame(seven);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              zero0();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              F();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x718E7B85:
        Serial.print("8 \n");
        matrix.loadFrame(eight);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              one1();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              E();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x728D7B85:
        Serial.print("9 \n");
        matrix.loadFrame(nine);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              two2();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              D();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x6D927B85:
        Serial.print("0 \n");
        matrix.loadFrame(zero);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              D();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              two2();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x6C937B85:
        Serial.print("* \n");
        matrix.loadFrame(dot);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              C();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              three3();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x7F807B85:
        Serial.print("# \n");
        matrix.loadFrame(hastax);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              seven7();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              F();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              eight8();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              zero0();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      case 0x609F7B85:
        Serial.print("REPEAT \n");
        matrix.loadFrame(home);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              zero0();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              F();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;
      /*case 0x6A957F00:
        Serial.println("OPEN_LINK_1");
        matrix.loadFrame(netflix);
        for (int d = 1; d <= 4; d++) {
          switch (d) {
            case 1:
              digitalWrite(digit1, 1);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              six6();
              break;
            case 2:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 1);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 0);
              A();
              break;
            case 3:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 1);
              digitalWrite(digit4, 0);
              nine9();
              break;
            case 4:
              digitalWrite(digit1, 0);
              digitalWrite(digit2, 0);
              digitalWrite(digit3, 0);
              digitalWrite(digit4, 1);
              five5();
              break;
          };
          delay(250);
          off();
        }
        matrix.loadFrame(black);
        break;*/
    }
    IrReceiver.resume();
  }
}