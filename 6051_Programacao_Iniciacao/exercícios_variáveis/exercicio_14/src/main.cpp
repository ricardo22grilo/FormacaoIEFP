#include <Arduino.h>

char primeiro = 'a';
char segundo = 'A';


void setup() 
{
  Serial.begin(115200);
  Serial.printf("primeiro: %c\n",primeiro);
  Serial.printf("segundo: %c\n",segundo);

}

void loop() 
{
  // put your main code here, to run repeatedly:
}

