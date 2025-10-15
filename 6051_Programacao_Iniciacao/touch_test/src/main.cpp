#include <Arduino.h>

void setup() {
  Serial.begin(115200);  
  Serial.println("FireBeetle Board-ESP32 Touch Test");
}

void loop() {
  Serial.println(touchRead(T0));  
  delay(500);
}