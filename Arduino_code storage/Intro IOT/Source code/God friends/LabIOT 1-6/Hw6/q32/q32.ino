#define THERMISTOR A5    
#define R0 10000        
#define B 3435         
#define R1 10000        

float T0 = 25;    

void setup() {
    T0 = T0 + 273.15;
    Serial.begin(9600);
}

void loop() {
    int samples;
    samples = analogRead(THERMISTOR); 
    Serial.print("Analog reading : ");
    Serial.println(samples);

    float R = R1 * (1023.0 / samples - 1);

    Serial.print("Thermistor Resistance : ");
    Serial.println(R);

    float ln = log(R / R0);
    float T = 1.0 / ((1.0 / T0) + (ln / B));
    float C = T - 273.15; 

    Serial.print("Temperature : ");
    Serial.println(C);


    static int count = 0;
    static float sum = 0;
    count++;
    sum += C;

    if (count == 3) {
        float average = sum / 3;
        Serial.print("Average Tem : ");
        Serial.println(average);

        count = 0;
        sum = 0;
    }

    delay(1000); 
}
