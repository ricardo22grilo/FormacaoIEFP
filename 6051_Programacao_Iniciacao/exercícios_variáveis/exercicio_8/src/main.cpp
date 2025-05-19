#include <Arduino.h>



float valor_original = 7.8;
int valor_convertido = 0;


void setup() 
{
  Serial.begin(115200);
  valor_convertido = (int)valor_original;
  Serial.println(valor_original);
  Serial.println(valor_convertido);
}