#include "Arduino_LED_Matrix.h"  // Include the LED_Matrix library
ArduinoLEDMatrix matrix;         // Create an instance of the ArduinoLEDMatrix class

int segA = 1;
int segB = 2;
int segC = 3;
int segD = 4;
int segE = 5;
int segF = A0;
int segG = A1;
int segDP = A2;

const uint32_t frames[][4] = {
  { 0x0, 0x0, 0x0, 100 },                      //1
  { 0x0, 0x10010, 0x1001001, 100 },            //2
  { 0x0, 0x20020, 0x2002003, 100 },            //3
  { 0x0, 0x40040, 0x4004006, 100 },            //4
  { 0x0, 0x90080, 0x900900d, 100 },            //5
  { 0x0, 0x130100, 0x1301201b, 100 },          //6
  { 0x0, 0x270200, 0x26024037, 100 },          //7
  { 0x0, 0x4f0410, 0x4d04906f, 100 },          //8
  { 0x0, 0x9e0820, 0x9a0920de, 100 },          //9
  { 0x0, 0x13d1041, 0x351251bd, 100 },         //10
  { 0x0, 0x27b2092, 0x6a24a37a, 100 },         //11
  { 0x0, 0x9ef8259, 0xa9929de9, 100 },         //12
  { 0x0, 0x3de04a3, 0x52252bd2, 100 },         //13
  { 0x100100, 0x7bd0946, 0xa44a47a4, 100 },    //14
  { 0x200300, 0xf7b128d, 0x48948f49, 100 },    //15
  { 0x400700, 0xef7251a, 0x91291e93, 100 },    //16
  { 0x800e00, 0xdee4a25, 0x22522d26, 100 },    //17
  { 0x1001c00, 0xbdc945a, 0x45a45a4d, 100 },   //18
  { 0x2003800, 0x7b928a4, 0x8b48b49a, 100 },   //19
  { 0x4007000, 0xf725159, 0x17916934, 100 },   //20
  { 0x800e000, 0xee5a2a2, 0x2e22c269, 100 },   //21
  { 0x1001c000, 0xdca4554, 0x5d4594d3, 100 },  //22
  { 0x20038000, 0xb948aa8, 0xba8b39a6, 100 },  //23
  { 0x40070000, 0x7281541, 0x7416734c, 100 },  //24
  { 0x800e0000, 0xe512a92, 0xe92cf699, 100 },  //25
  { 0xc0000, 0xca25525, 0xd259ed32, 100 },     //26
  { 0x80000, 0x945aa4b, 0xa4b3ba64, 100 },     //27
  { 0x0, 0x28b5497, 0x496794c9, 100 },         //28
  { 0x0, 0x516a92e, 0x92cf3992, 100 },         //29
  { 0x0, 0xa2c514d, 0x249f7324, 100 },         //30
  { 0x100300, 0x459a49a, 0x493cf649, 100 },    //31
  { 0x300600, 0x8b24924, 0x9279fc92, 100 },    //32
  { 0x600c00, 0x1649249, 0x24f3e924, 100 },    //33
  { 0xc01800, 0x2c82482, 0x48e7c248, 100 },    //34
  { 0x1803000, 0x5904904, 0x90cf8490, 100 },   //35
  { 0x3006000, 0xb209209, 0x209f0920, 100 },   //36
  { 0x600c000, 0x6402402, 0x403e0240, 100 },   //37
  { 0xc018000, 0xc808808, 0x80bc0880, 100 },   //38
  { 0x18030000, 0x9009009, 0xf80900, 100 },    //39
  { 0x30060000, 0x2002002, 0xf00200, 100 },    //40
  { 0x600c0000, 0x4004004, 0xe00400, 100 },    //41
  { 0xc0080000, 0x8008008, 0xc00800, 100 },    //42
  { 0x80000000, 0x0, 0x800000, 100 },          //43

};

void setup() {
  matrix.loadSequence(frames);
  matrix.begin();
  matrix.play(true);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 3; i <= 8; i++) {
    delay(400);
    switch (i) {
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
    }
  }
}



void four() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void five() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void six() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 0);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}
void seven() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 0);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}
void eight() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}
void three() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}