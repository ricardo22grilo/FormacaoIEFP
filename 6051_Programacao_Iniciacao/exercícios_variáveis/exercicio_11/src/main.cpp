#include <Arduino.h>

int numero1 = 3;
int numero2 = 5;
int numero3 = 7;

void setup() 
{
  Serial.begin(115200);
  Serial.println(numero1 + numero2 + numero3);
}

void loop()
{

}

