#include <Arduino.h>

int ledVerde = 17;
int ledVermelho = 16;
int ledAmarelo = 4;

unsigned long previous = 0;
const long interval = 5000;

int botaoVerde = 25;
int botaoVermelho = 26;
int botaoAmarelo = 0;


enum State
  {
    TUDO_DESLIGADO = 0,
    LED_VERDE,
    LED_VERMELHO,
    LED_AMARELO
  };

  State botao = TUDO_DESLIGADO;

void setup() 
{
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);

  pinMode(botaoVerde, INPUT);
  pinMode(botaoVermelho, INPUT);
  pinMode(botaoAmarelo, INPUT);
  Serial.begin(115200);
}

void loop()
{
  switch(botao)
    {
    case TUDO_DESLIGADO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      if(digitalRead(botaoVerde) == LOW)
      {
        botao = LED_VERDE;
        previous = millis();
      }
      else if(digitalRead(botaoVermelho) == LOW)
      {
        botao = LED_VERMELHO;
        previous = millis();
      }
      else if(digitalRead(botaoAmarelo) == LOW)
      {
        botao = LED_AMARELO;
        previous = millis();
      }
      break;
    
    case LED_VERDE:
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      if(millis() - previous >= interval)
      {
        botao = TUDO_DESLIGADO;
      }
      break;

      case LED_VERMELHO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAmarelo, LOW);
      if(millis() - previous >= interval)
      {
        botao = TUDO_DESLIGADO;
      }
      break;

      case LED_AMARELO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      if(millis() - previous >= interval)
      {
        botao = TUDO_DESLIGADO;
      }
      break;
    }
}



/*
int ledVerde = 2;
int ledVermelho = 16;
int ledAmarelo = 4;

unsigned long previous = 0;
const long interval = 5000;

int botaoVerde = 27;
int botaoVermelho = 26;
int botaoAmarelo = 25;


enum State
  {
    TUDO_DESLIGADO = 0,
    LED_VERDE,
    LED_VERMELHO,
    LED_AMARELO
  };

  State botao = TUDO_DESLIGADO;

void setup() 
{
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);

  pinMode(botaoVerde, INPUT);
  pinMode(botaoVermelho, INPUT);
  pinMode(botaoAmarelo, INPUT);
  Serial.begin(115200);
}

void loop()
{
  switch(botao)
    {
    case TUDO_DESLIGADO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      if(digitalRead(botaoVerde) == LOW)
      {
        botao = LED_VERDE;
      }
      else if(digitalRead(botaoVermelho) == LOW)
      {
        botao = LED_VERMELHO;
      }
      else if(digitalRead(botaoAmarelo) == LOW)
      {
        botao = LED_AMARELO;
      }
      break;
    
    case LED_VERDE:
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      if(millis() - previous >= interval)
      {
        botao = TUDO_DESLIGADO;
        previous = millis();
      }
      break;

      case LED_VERMELHO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAmarelo, LOW);
      if(millis() - previous >= interval)
      {
        botao = TUDO_DESLIGADO;
        previous = millis();
      }
      break;

      case LED_AMARELO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      if(millis() - previous >= interval)
      {
        botao = TUDO_DESLIGADO;
        previous = millis();
      }
      break;
    }
}
*/