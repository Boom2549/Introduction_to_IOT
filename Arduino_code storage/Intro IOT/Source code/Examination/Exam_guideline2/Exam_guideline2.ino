//แนวข้อสอบ 2

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
#define  LDR  A1                            
#define  R0  10000                                       
#define  B    3435                                        
#define  R1  10000                                       
float T0 = 25;  
float TR ;
float T;
float T_celcius;
float T_av;
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
  T0 = T0 + 273.15;                                     
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

void one () 
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDP, LOW);
}
void two () 
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void three () 
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}
void four () 
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}

void five () 
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}

void six () 
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDP, LOW);
}

void seven () 
{
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDP, LOW);
}

void eight () 
{
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segDP, 0);
}

void nine () 
{
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
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

  if(ldrread>700)
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
  else
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
