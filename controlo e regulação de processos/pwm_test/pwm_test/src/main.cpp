#include <Arduino.h>
const int potPin = 4;
const int pwmPin = 17;

const int freq = 5000;
const int pwmChannel = 0;
const int resolution = 8;

int adcMin = 200;   // lowest observed value
int adcMax = 3900;  // highest observed value

void setup() {
  Serial.begin(115200);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop() {
  int val = analogRead(potPin);
  val = constrain(val, adcMin, adcMax);  // limit range
  int duty = map(val, adcMin, adcMax, 0, 255);

  ledcWrite(pwmChannel, duty);
  Serial.printf("ADC: %d  Duty: %d\n", val, duty);
  delay(50);
}

