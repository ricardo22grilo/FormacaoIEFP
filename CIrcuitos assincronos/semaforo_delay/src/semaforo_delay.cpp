#include <Arduino.h>

const int led_sem1_verde = 0;
const int led_sem1_amarelo = 25;
const int led_sem1_vermelho = 26;

const int led_sem2_verde = 14;
const int led_sem2_amarelo = 13;
const int led_sem2_vermelho = 2;
const int botao = 27;

unsigned long previous = millis();



void liga_sem1_verde()
{
  digitalWrite(led_sem1_verde, HIGH);
  digitalWrite(led_sem1_amarelo, LOW);
  digitalWrite(led_sem1_vermelho, LOW);
}

void liga_sem1_amarelo()
{
  digitalWrite(led_sem1_verde, LOW);
  digitalWrite(led_sem1_amarelo, HIGH);
  digitalWrite(led_sem1_vermelho, LOW);
}

void liga_sem1_vermelho()
{
  digitalWrite(led_sem1_verde, LOW);
  digitalWrite(led_sem1_amarelo, LOW);
  digitalWrite(led_sem1_vermelho, HIGH);
}

void liga_sem2_verde()
{
  digitalWrite(led_sem2_verde, HIGH);
  digitalWrite(led_sem2_amarelo, LOW);
  digitalWrite(led_sem2_vermelho, LOW);
}

void liga_sem2_amarelo()
{
  digitalWrite(led_sem2_verde, LOW);
  digitalWrite(led_sem2_amarelo, HIGH);
  digitalWrite(led_sem2_vermelho, LOW);
}
void liga_sem2_vermelho()
{
  digitalWrite(led_sem2_verde, LOW);
  digitalWrite(led_sem2_amarelo, LOW);
  digitalWrite(led_sem2_vermelho, HIGH);
}

void setup()
{
  pinMode(led_sem1_verde, OUTPUT);
  pinMode(led_sem1_amarelo, OUTPUT);
  pinMode(led_sem1_vermelho, OUTPUT);
  pinMode(led_sem2_verde, OUTPUT);
  pinMode(led_sem2_amarelo, OUTPUT);
  pinMode(led_sem2_vermelho, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(botao)==LOW)
  {
    liga_sem1_vermelho();
    liga_sem2_vermelho();
    delay(5000);
  }
  else
  {
    liga_sem1_verde();
    liga_sem2_vermelho();
    delay(5000);
    
    liga_sem1_amarelo();
    liga_sem2_vermelho();
    delay(2000);

    liga_sem1_vermelho();
    liga_sem2_verde();
    delay(5000);

    liga_sem1_vermelho();
    liga_sem2_amarelo();
    delay(2000);
  }


}