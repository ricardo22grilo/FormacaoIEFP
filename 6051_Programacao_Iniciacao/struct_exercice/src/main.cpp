#include <Arduino.h>

struct Thermistor
{
  double temp_valor [20];
  int posicao;
  double media;
  double Vout;
  double R2;
  double logR2;
  double logcubeR2;
  double tC;
  double tK;
};

Thermistor th1;
Thermistor th2;

const double R1 = 10000;
long previous = millis();

int th1_pin = A0;
int th2_pin = A1;
float A = 1.129148e-3; // valores usados na equação de steinhart-hart para calcular a temperatura do sensor
float B = 2.34125e-4; // valores usados na equação de steinhart-hart para calcular a temperatura do sensor
float C = 8.76741e-8; // valores usados na equação de steinhart-hart para calcular a temperatura do sensor


void setup() 
{
  Serial.begin(115200);
  pinMode(th1_pin, INPUT);
  pinMode(th2_pin,INPUT);
}

void loop() 
{
  if(millis()-previous > 1000)
  {
    th1.Vout = analogRead(th1_pin);
    th2.Vout = analogRead(th2_pin);
    th1.R2 = R1*(1050.0/th1.Vout - 1.0);
    th2.R2 = R1*(1050.0/th2.Vout - 1.0);
    th1.logR2 = log(th1.R2);
    th2.logR2 = log(th2.R2);
    th1.logcubeR2 = pow(th1.logR2,3);
    th2.logcubeR2 = pow(th2.logR2,3);
  }
}

