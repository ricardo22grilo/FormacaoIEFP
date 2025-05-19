#include <Arduino.h>

double temperatura = 25.5;
double temp_kelvin;
double temp_fahrenheit;

void setup() 
{
  temp_kelvin = temperatura + 273.15;
  temp_fahrenheit = (temperatura * 9.0/5.0) + 32.0;
  Serial.printf("temperatura em celsius: %.2f\n", temperatura);
  Serial.printf("temperatura em kelvin: %.2f\n", temp_kelvin);
  Serial.printf("temperatura em fahrenheit: %.2f\n", temp_fahrenheit);
}

void loop() 
{
  // put your main code here, to run repeatedly:
}

