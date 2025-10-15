#include <Arduino.h>


int thermistorPin = A4;
float R1 = 10000;
float R2, logR2, logR2Cube, tK, tC, tF;
float A = 1.122775062e-3, B = 2.358874358e-4, C = 0.7504998806e-7;
int vout;

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  vout = analogRead(thermistorPin);
  R2 = 10000*(4095.0/vout -1.0);
  logR2 = log(R2);
  logR2Cube = pow(logR2,3);

  tK = (1.0 / (A + B*logR2 + C*logR2Cube));
  tC = tK - 273.15;
  Serial.print("temp= ");
  Serial.println(tC);
  delay(750);

  }
