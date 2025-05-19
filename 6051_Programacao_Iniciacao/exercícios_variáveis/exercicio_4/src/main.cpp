#include <Arduino.h>

int valor_1 = 10;
int valor_2 = 20;
int temporario=0;



void setup() 
{
 Serial.begin(115200);
 Serial.printf("Valor 1: %d\n", valor_1);
 Serial.printf("Valor 2: %d\n", valor_2);
 temporario = valor_1;
 valor_1 = valor_2;
 valor_2 = temporario;
 Serial.printf("Valor 1: %d\n", valor_1);
 Serial.printf("Valor 2: %d\n", valor_2);

}

void loop() 
{

}

