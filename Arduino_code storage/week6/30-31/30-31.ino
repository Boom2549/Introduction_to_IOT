#define THERMISTOR A5  // thermistor pin
#define R0 10000
#define B 3435  // B: 3435 K the beta coefficient of the thermistor
#define R1 10000
float T0 = 25;  // °C reference temp.
float R;
float T;
float C;

void setup() {
  T0 = T0 + 273.15;  // conversion from Celsius to kelvin
  Serial.begin(9600);
}

void loop() {
  int samples;
  samples = analogRead(THERMISTOR);   // read the input on analog pin 0
  Serial.print("Analog reading : ");  // print out the value
  Serial.println(samples);
  R = R1 * (samples/(1023.0-samples));
  Serial.print("ความต้านทานเทอร์มิสเตอร R : ");
  Serial.println(R);
  T = 1 / ((1.0 / T0) + ((1.0 / B) * log(R / R0)));
  C = T - 273.15;
  Serial.print("อุณหภูมิ C : ");
  Serial.println(C);

  delay(1000);  // Wait for next sample
}