#include <Arduino.h>

const int led_sem1_verde = 0;
const int led_sem1_amarelo = 26; 
const int led_sem1_vermelho = 25;
const int led_sem_pessoa_verde = 16;
const int led_sem_pessoa_vermelho = 17;

unsigned long previous = millis();


int intervalVerde = 2000;
int intervalAmarelo = 1000;

const int led_sem2_verde = 14;
const int led_sem2_amarelo = 13;
const int led_sem2_vermelho = 2;
const int botao = 12;



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
  pinMode(led_sem_pessoa_verde, OUTPUT);
  pinMode(led_sem_pessoa_vermelho, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
  liga_sem1_verde();
  liga_sem2_vermelho();
}

void loop() {
  
  if (digitalRead(botao) == LOW) 
  {
    liga_sem1_vermelho();
    liga_sem2_vermelho();
    digitalWrite(led_sem_pessoa_verde, HIGH);
    digitalWrite(led_sem_pessoa_vermelho, LOW);
    delay(5000);
    digitalWrite(led_sem_pessoa_verde, LOW);
    digitalWrite(led_sem_pessoa_vermelho, HIGH);
    previous = millis();
  }
  else if (millis() - previous < intervalVerde) 
  {
    liga_sem1_verde();
    liga_sem2_vermelho();
  }
  else if (millis() - previous < intervalVerde + intervalAmarelo)
  {
  liga_sem1_amarelo();
  liga_sem2_vermelho();
  }
  else if (millis() - previous < 2 * intervalVerde + intervalAmarelo)
  {
    liga_sem1_vermelho();
    liga_sem2_verde();
  }
  else if (millis() - previous < 2 * (intervalVerde + intervalAmarelo)) 
  {
    liga_sem1_vermelho();
    liga_sem2_amarelo();
  }
  else
  {
  previous = millis();
  }
}