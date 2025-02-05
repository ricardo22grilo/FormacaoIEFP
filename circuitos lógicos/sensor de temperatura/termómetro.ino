#include <LiquidCrystal.h>

int thermistorPin = A0;
float R1 = 10000;
float R2, logR2, logR2Cube, tK, tC, tF;
float A = 1.122775062e-3, B = 2.358874358e-4, C = 0.7504998806e-7;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int Vout = analogRead(thermistorPin);
  R2 = 10000*(1023.0/Vout -1.0);
  logR2 = log(R2);
  logR2Cube = pow(logR2,3);

  tK = (1.0 / (A + B*logR2 + C*logR2Cube));
  tC = tK - 273.15;
  
  lcd.print("Temp = ");
  lcd.print(tC);   
  lcd.print(" C");

  delay(750);
  lcd.clear();

  }
