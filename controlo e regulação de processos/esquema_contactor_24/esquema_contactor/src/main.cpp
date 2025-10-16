#include <Arduino.h>

int pinout = 4;
int pinIn = 17;
int valor = 0;

void setup() 
{
Serial.begin(115200);
pinMode(pinout, OUTPUT);
pinMode(pinIn, INPUT);
}

void loop() {
  digitalWrite(pinout, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                  // wait for a second
  digitalWrite(pinout, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);
  valor = digitalRead(pinIn);
  if (valor == 1) 
  {
    digitalWrite(BUILTIN_LED, HIGH);
  } else {
    digitalWrite(BUILTIN_LED, LOW);
  }
}

