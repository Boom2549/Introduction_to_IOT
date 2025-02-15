//แนวข้อสอบ1

int segA = 13;
int segB = 12;
int segC = 11;
int segD = 10;
int segE = 9;
int segF = 8;
int segG = 7;
int segDP = 6;
int d1 = 5;
int d2 = 4;
int d3 = 3;
int d4 = 2;
#define PT A2
#define THERMISTOR A1
#define R0 10000
#define B 3435
#define R1 10000
int LED = 1;
float T0 = 25;
float TR;
float T;
float T_celcius;
float T_av;
int i = 0;


int photran_total;
int photran_av;

void setup() {
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  T0 = T0 + 273.15;
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}


void zero() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}

void one() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDP, LOW);
}
void two() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
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
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}

void seven() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDP, LOW);
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

void nine() {
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}

void off() {
  digitalWrite(segA, 0);
  digitalWrite(segB, 0);
  digitalWrite(segC, 0);
  digitalWrite(segD, 0);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}


void loop() {

  int photran = analogRead(PT);
  photran_total += photran;

  i++;
  if (i == 50) {
    photran_av = photran_total / 50;
    photran_total = 0;
    i = 0;
  }

  int photrand1 = photran_av % 10;
  int photrand10 = (photran_av % 100) / 10;
  int photrand100 = (photran_av % 1000) / 100;

  for (int d = 1; d <= 4; d++) {
    switch (d) {
      case 1:
        digitalWrite(d1, 1);
        digitalWrite(d2, 0);
        digitalWrite(d3, 0);
        digitalWrite(d4, 0);
        switch (photrand1) {
          case 0:
            zero();
            break;
          case 1:
            one();
            break;
          case 2:
            two();
            break;
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
          case 9:
            nine();
            break;
        };

        break;
      case 2:
        digitalWrite(d1, 0);
        digitalWrite(d2, 1);
        digitalWrite(d3, 0);
        digitalWrite(d4, 0);

        switch (photrand10) {
          case 0:
            zero();
            break;
          case 1:
            one();
            break;
          case 2:
            two();
            break;
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
          case 9:
            nine();
            break;
        };

        break;
      case 3:
        digitalWrite(d1, 0);
        digitalWrite(d2, 0);
        digitalWrite(d3, 1);
        digitalWrite(d4, 0);
        switch (photrand100) {
          case 0:
            zero();
            break;
          case 1:
            one();
            break;
          case 2:
            two();
            break;
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
          case 9:
            nine();
            break;
        };

        break;
      case 4:
        digitalWrite(d1, 0);
        digitalWrite(d2, 0);
        digitalWrite(d3, 0);
        digitalWrite(d4, 1);

        off();
        break;
    };
    delay(2);
    dactivatepin();
  }
  if ((photran < 500) && (photran_av != 0)) {
    digitalWrite(LED, 1);
  } else {
    digitalWrite(LED, 0);
  }
}

void dactivatepin() {
  digitalWrite(d1, 0);
  digitalWrite(d2, 0);
  digitalWrite(d3, 0);
  digitalWrite(d4, 0);
}
