#include <Arduino.h>

int tempo = 10;
int semanas= 0;
int dias= 0;


void setup() 
{
  Serial.begin(115200);
  semanas = tempo / 7;
  dias = tempo % 7;
  Serial.printf("tempo em semanas: %d\n", semanas);
  Serial.printf("tempo restante em dias: %d\n", dias);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

