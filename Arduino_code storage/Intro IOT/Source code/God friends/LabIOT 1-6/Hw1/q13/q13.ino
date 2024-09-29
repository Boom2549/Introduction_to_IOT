                                 
// void setup()                   
// {                 
//   for(int i = 9 ; i <= 13 ; i++)
//   {
//     pinMode (i, OUTPUT);
//   }
// } 

// void loop()  
// { 
//   for( int i = 13; i >= 9 ; i--)  
//   {
//     digitalWrite(i, HIGH);
//     delay(100);
//     digitalWrite(i, LOW);
//     delay(100);
//   }
//   for( int i = 9; i <= 13 ; i++)  
//   {
//     digitalWrite(i, HIGH);
//     delay(100);
//     digitalWrite(i, LOW);
//     delay(100);
//   }
  
// }


void setup()
{
  for (int led = 9;led <= 13; led++)
  {
  pinMode(led,OUTPUT);
  }
}
void loop()
{
  for (int led = 13;led >= 9; led--)
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  for (int led = 9;led <= 13; led++)
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
}