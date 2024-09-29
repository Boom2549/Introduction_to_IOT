int led1 = 9;
int led2 = 10;                         
void setup()
{
  
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
}
 

void loop()  
{ 

    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    delay(250);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    delay(250);
    
}