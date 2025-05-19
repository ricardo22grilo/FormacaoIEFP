#include <Arduino.h>


int idade = 27;
double altura =1.68;
String nome =  "Ricardo";
bool Homem = true;
char letra = 'R';


void setup() 
{
  Serial.begin(115200);
  Serial.printf("Idade: %d\n", idade);
  Serial.printf("Altura: %.2f\n", altura);
  Serial.printf("Nome: %s\n", nome.c_str());
  Serial.printf("Homem: %s\n", Homem);
  Serial.printf("Letra: %c\n", letra);
}

void loop() 
{
 
}

