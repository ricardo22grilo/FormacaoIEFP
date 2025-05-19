#include <Arduino.h>

#define PI 3.1415926535897932384626433832795

int raio = 5;
void setup() 
{
  Serial.begin(115200);
  Serial.printf("area do circulo: %f\n", PI * raio * raio);
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
