#include <Arduino.h>

char letra = 'A'; 
void setup() 
{
Serial.begin(115200);
Serial.printf("o caracter é: %c\n", letra);
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
