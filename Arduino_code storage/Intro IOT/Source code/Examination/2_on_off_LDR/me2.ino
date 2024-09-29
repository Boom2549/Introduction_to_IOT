// 2) on-off led by LDR displaying on-off

int segA = A0;
int segB = A1;
int segC = A2;
int segD = 2;
int segE = 4;
int segF = 7;
int segG = 8;
int segDP = 13;
int d1 = 10;
int d2 = 9;
int d3 = 6;
int d4 = 5;
#define  LDR  A5                            
int i=0;
int LED = 1;
int ldrread;

void setup ()
{
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
  Serial.begin(9600); 
  pinMode(LED, OUTPUT);

}

void F()
{
  digitalWrite(segA, 1);
  digitalWrite(segB, 0);
  digitalWrite(segC, 0);
  digitalWrite(segD, 0);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}

void N()
{
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 0);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}

void zero () 
{
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}

void off()
{
  digitalWrite(segA, 0);
  digitalWrite(segB, 0);
  digitalWrite(segC, 0);
  digitalWrite(segD, 0);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 0);
  digitalWrite(segDP, 0);
}

void dactivatepin()
{
  digitalWrite(d1, 0);
  digitalWrite(d2, 0);
  digitalWrite(d3, 0);
  digitalWrite(d4, 0);
}


void loop()
{ 
  ldrread = analogRead(LDR);

  if(ldrread>700)           //led on
  {
    for(int d = 1 ; d <= 4 ; d++)
    {
      switch(d)
      {
      case 1 :
        digitalWrite(d1, 1);
        digitalWrite(d2, 0);
        digitalWrite(d3, 0);
        digitalWrite(d4, 0);
        N();

        break;
      case 2 :
        digitalWrite(d1, 0);
        digitalWrite(d2, 1);
        digitalWrite(d3, 0);
        digitalWrite(d4, 0);
        zero();

        break;
      case 3 :
        digitalWrite(d1, 0);
        digitalWrite(d2, 0);
        digitalWrite(d3, 1);
        digitalWrite(d4, 0);
        off();

        break;
      case 4 :
        digitalWrite(d1, 0);
        digitalWrite(d2, 0);
        digitalWrite(d3, 0);
        digitalWrite(d4, 1);
        off();

        break;
      };
    delay(2);
    dactivatepin();
    digitalWrite(LED, 1);

    }
  }
  else                  //led off
  {

    for(int d = 1 ; d <= 4 ; d++)
    {
      switch(d)
      {
      case 1 :
        digitalWrite(d1, 1);
        digitalWrite(d2, 0);
        digitalWrite(d3, 0);
        digitalWrite(d4, 0);
        F();

        break;
      case 2 :
        digitalWrite(d1, 0);
        digitalWrite(d2, 1);
        digitalWrite(d3, 0);
        digitalWrite(d4, 0);
        F();

        break;
      case 3 :
        digitalWrite(d1, 0);
        digitalWrite(d2, 0);
        digitalWrite(d3, 1);
        digitalWrite(d4, 0);
        zero();

        break;
      case 4 :
        digitalWrite(d1, 0);
        digitalWrite(d2, 0);
        digitalWrite(d3, 0);
        digitalWrite(d4, 1);
        off();

        break;
      };
    delay(2);
    dactivatepin();
    digitalWrite(LED, 0);
    }
  }
}
