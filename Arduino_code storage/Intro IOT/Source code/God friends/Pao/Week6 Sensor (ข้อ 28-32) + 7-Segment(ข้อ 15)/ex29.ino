#define  THERMISTOR  A3                          
#define  R0  10000                                      
#define  B    3435                                        
#define  R1  10000                                      
float T0 = 25;
float R;
float T;
float C;


void setup()  { 
T0 = T0 + 273.15;                                     
  Serial.begin(9600);
} 

void loop() { 
  int samples;
  samples = analogRead(THERMISTOR);         
  Serial.print("Analog reading : ");                  
  Serial.println(samples);


  delay(1000);  // Wait for next sample                                             
} 
