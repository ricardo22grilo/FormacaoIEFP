#include <Arduino.h>

int inteiro = 10;
float decimal = 13.8;

void setup() 
{
  Serial.begin(115200);
  Serial.println(inteiro + decimal); 
}

void loop()
{
  
}

