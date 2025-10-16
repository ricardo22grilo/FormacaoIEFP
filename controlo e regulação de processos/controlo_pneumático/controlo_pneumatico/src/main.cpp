#include <Arduino.h>

int pinavanco = 4;
int pinrecuo = 17;



void ligaravanco()
{
  digitalWrite(pinrecuo, LOW);
  digitalWrite(pinavanco, HIGH);
}

void ligarrecuo()
{
  digitalWrite(pinavanco, LOW);
  digitalWrite(pinrecuo, HIGH);
}

void setup()
{
  Serial.begin(115200);
  pinMode(pinavanco, OUTPUT);
  pinMode(pinrecuo, OUTPUT);
  digitalWrite(pinavanco, LOW);
  digitalWrite(pinrecuo, LOW); 
}

void loop() 
{
  ligaravanco();
  Serial.println("Avanco");
  delay(3000);
  ligarrecuo();
  Serial.println("Recuo");
  delay(3000);
}