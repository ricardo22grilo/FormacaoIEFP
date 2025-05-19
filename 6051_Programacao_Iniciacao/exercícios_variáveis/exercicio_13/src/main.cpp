#include <Arduino.h>

double numero1 = 99;
double numero2 = 10;

double soma;
double multiplicacao;
double divisao;
double subtracao;
double resto;

void setup() 
{
  Serial.begin(115200);
  multiplicacao = numero1*numero2;
  soma = numero1 + numero2;
  divisao = numero1/numero2;
  subtracao = numero1-numero2;
  resto = fmod(numero1, numero2);

  Serial.printf("soma: %f\n", soma);

  Serial.printf("multiplicacao: %f\n", multiplicacao);
  
  Serial.printf("divisao: %f\n", divisao);

  Serial.printf("subtracao: %f\n", subtracao);
  
  Serial.printf("resto: %f\n", resto);
  

}

void loop() {
  // put your main code here, to run repeatedly:
}

