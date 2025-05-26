#include <Arduino.h>



int ldr_pin = 4;
int led_pin =17;

const int resistance = 10000;

int ldr_value = 0;

long previous = 0;

void setup() 
{
  Serial.begin(115200);
  pinMode(ldr_pin, INPUT);
  pinMode(led_pin, OUTPUT);

}

void loop() 
{
  if(millis() - 500 > previous)
  {
    ldr_value = analogRead(ldr_pin);
    previous = millis();
    Serial.printf("LDR Value: %d\n", ldr_value); 
    if(ldr_value > 1000)
    {
      digitalWrite(led_pin, HIGH);
    }
    else
    {
      digitalWrite(led_pin, LOW);
    }
  }
}

