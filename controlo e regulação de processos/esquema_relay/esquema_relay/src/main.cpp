#include <Arduino.h>

int pinout = 4;

void setup() 
{
Serial.begin(115200);
pinMode(pinout, OUTPUT);
}

void loop() {
  digitalWrite(pinout, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(pinout, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}

