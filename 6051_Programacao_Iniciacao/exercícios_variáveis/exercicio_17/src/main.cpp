#include <Arduino.h>

char letra = 'A';
char letra2 = 'B';

void setup() 
{
  Serial.begin(115200);
  Serial.print(letra);
  Serial.println(letra2);
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
