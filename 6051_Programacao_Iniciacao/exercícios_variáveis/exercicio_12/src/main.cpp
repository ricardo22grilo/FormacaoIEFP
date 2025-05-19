#include <Arduino.h>


double primeiro = 12.5;
double segundo = 1.8;
double terceiro = 7.2;
double media = 0.0;

void setup() 
{
  Serial.begin(115200);
  media = (primeiro + segundo + terceiro) / 3.0;
  Serial.printf("A media dos numeros %.2f\n", media);
}

void loop() 
{
  
}

