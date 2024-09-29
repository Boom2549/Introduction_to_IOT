// int led = 9 ;        
// int i;
// void setup()                   
// {                 
//   pinMode(led, OUTPUT);               
// } 
// void loop()  
// { 
//   for( i = 1; i<500 ; i = i + 1 )
//   {
//     digitalWrite(led, HIGH);
//     delay(500-i);
//     digitalWrite(led, LOW);
//     delay(1500- i*3);
//   }                         
// }

// int led = 9 ;        
// void setup()                   
// {                 
//   pinMode(led, OUTPUT);               
// } 
// void loop()  
// { 
//   for(int i = 1; i<500 ;i ++)
//   {
//     digitalWrite(led, HIGH);
//     delay(500-i);
//     digitalWrite(led, LOW);
//     delay(1500- i*3);
//   }                         
// }




// int led = 9 ;        
// int i;
// void setup()                   
// {                 
//   pinMode(led, OUTPUT);               
// } 
// void loop()  
// { 
//   int decre = 100;
//   for( i = 0; i<=1500/decre ; i++ )
//   {
//     digitalWrite(led, HIGH);
//     delay(500);
//     digitalWrite(led, LOW);
//     delay(1500- decre*i);
//   }                         
// }


int led = 9 ;        
int i;
void setup()                   
{                 
  pinMode(led, OUTPUT);               
} 
void loop()  
{ 
  int decre = 100;
  for( i = 0; i>=0 ; i++ )
  {
    digitalWrite(led, HIGH);
    delay(500*pow(0.9,i));
    digitalWrite(led, LOW);
    delay(1500*pow(0.9,i));
  }                         
}
