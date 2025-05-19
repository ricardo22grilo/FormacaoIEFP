#include <Arduino.h>

int idade = 27;

void setup()
{
 Serial.begin(115200);
 Serial.printf("a minha idade é %d\n", idade);
}

void loop() 
{

}
