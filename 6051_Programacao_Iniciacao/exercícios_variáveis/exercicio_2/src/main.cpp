#include <Arduino.h>

float numero_1 = 14.3;
float numero_2 = 3.5;

void setup() 
{
Serial.begin(115200);
Serial.printf("numero_1 + numero_2 = %.2f\n", numero_1 + numero_2);
Serial.printf("numero_1 - numero_2 = %.2f\n", numero_1 - numero_2);
Serial.printf("numero_1 * numero_2 = %.2f\n", numero_1 * numero_2);
Serial.printf("numero_1 / numero_2 = %.2f\n", numero_1 / numero_2);
}

void loop()
{

}
  

