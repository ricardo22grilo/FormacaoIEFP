#include <Arduino.h>

unsigned long previous = millis();
int state = 0;

int pin1 = 12;



void setup()
{

    Serial.begin(9600);
    pinMode(pin1,OUTPUT);
}

void loop() 
{
    if (millis()- previous >200)
    {
        state = !state;
        digitalWrite(pin1,state);
        previous = millis();
    }
}

 

