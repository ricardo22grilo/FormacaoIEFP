#include <Arduino.h>

int num1 = 17;
int num2 = 11;

void setup() 
{
  Serial.begin(115200);

 if(num1 == num2)
 {
    Serial.println("num1 é igual a num2");
  }
  else if( num1 > num2)
  {
    Serial.println("num1 é maior que num2");
  }
  else
  {
    Serial.println("num2 é maior que num1");
  }

}

void loop()
{

}


