#include <Arduino.h>

int botao = 25;
int led = 12;
unsigned long previous = 0;
int const interval = 3000;  // 3 seconds
bool ledState = LOW;


void setup() {
    pinMode(botao, INPUT);
    pinMode(led,OUTPUT);  
    Serial.begin(115200);
}


void loop() 
{
  if (digitalRead(botao) == LOW) 
  {
    if (ledState == LOW) 
    {  // Only change state when first pressed
      ledState = HIGH;
      previous = millis();  // Save the current time
      Serial.println("Botão pressionado");
    }
  }

  // Check if 3 seconds have passed
  if (ledState == HIGH && millis() - previous >= interval) 
  {
    ledState = LOW;
    Serial.println("Botão não pressionado");
  }

  digitalWrite(led, ledState);
}