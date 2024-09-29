int segmentA = 1;
int segmentB = 2;
int segmentC = 3;
int segmentD = 4;
int segmentE = 5;
int segmentF = A0;
int segmentG = A1;
int segmentDP = A2;

int digit1 = 10;    //left
int digit2 = 9;
int digit3 = 7;
int digit4 = 6;
int num[][4] = {

  { 10, 10, 10, 6 },
  { 10, 10, 6, 7 },
  { 10, 6, 7, 0 },
  { 6, 7, 0, 1 },
  { 7, 0, 1, 1 },
  { 0, 1, 1, 0 },
  { 1, 1, 0, 6 },
  { 1, 0, 6, 3 },
  { 0, 6, 3, 10 },
  { 6, 3, 10, 10 },
  { 3, 10, 10, 10 },
  { 10, 10, 10, 10 },
};

int frame = 0;
int time = 0;

void setup() {
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

void loop() {
  displayNumber(frame);

  if (millis() - time > 1000) {
    frame++;
    if (frame > 11) frame = 0;
    time = millis();
  }
}

void displayNumber(int f) {
  for (int digit = 1; digit <= 4; digit++) {
    switch (digit) {
      case 1:
        digitalWrite(digit1, HIGH);
        break;
      case 2:
        digitalWrite(digit2, HIGH);
        break;
      case 3:
        digitalWrite(digit3, HIGH);
        break;
      case 4:
        digitalWrite(digit4, HIGH);
        break;
    }
    displaySegment(num[f][digit - 1]);  // แสดงผลบน 7-Segment ขนาด 1 หลัก
    delay(5);                           // หน่วงเวลา 0.5 วินาที
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
  }
}

void displaySegment(int numberToDisplay) {
  switch (numberToDisplay) {

    case 0:  // แสดงผลเลข 0
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;
    case 1:  // แสดงผลเลข 1
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case 2:  // แสดงผลเลข 2
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;

    case 3:  // แสดงผลเลข 3
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 4:  // แสดงผลเลข 4
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 5:  // แสดงผลเลข 5
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 6:  // แสดงผลเลข 6
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 7:  // แสดงผลเลข 7
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 8:  // แสดงผลเลข 8
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 9:  // แสดงผลเลข 9
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 10:  // แสดงผลเลข 0
      digitalWrite(segmentA, 0);
      digitalWrite(segmentB, 0);
      digitalWrite(segmentC, 0);
      digitalWrite(segmentD, 0);
      digitalWrite(segmentE, 0);
      digitalWrite(segmentF, 0);
      digitalWrite(segmentG, 0);
  }
}