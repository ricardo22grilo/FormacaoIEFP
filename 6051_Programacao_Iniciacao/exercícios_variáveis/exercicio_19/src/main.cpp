#include <Arduino.h>

int numero1 = 17;


void setup() 
{
  Serial.begin(115200);
  if((numero1 % 2) == 0)
  {
    Serial.println("numero1 é par");
  }
  else
  {
    Serial.println("numero1 é impar");
  }

  
}

void loop() 
{

}

