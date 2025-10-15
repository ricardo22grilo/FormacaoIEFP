#include <Arduino.h>

int ldrPin = A0;
int led_verde =17;
int led_amarelo = 16;
int led_vermelho = 4;

int ldrstate;

unsigned long previous = 0;
int interval;
int int_verde = 1000;
int int_amarelo = 1000;
int int_vermelho = 1000;

int state = 0;

void liga_verde()
{
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, LOW);
}
void liga_amarelo()
{
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW);
}
void liga_vermelho()
{
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, HIGH);
}

enum State
{
  SEMAFORO = 0,
  VERDE,
  AMARELO,
  VERMELHO
};

State quantidade_luz = SEMAFORO;

void setup() 
{
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void loop() 
{
ldrstate = analogRead(ldrPin);

  switch (quantidade_luz)
  {
    case SEMAFORO:
    if( millis() - previous > interval )
    {
      if(state == 0)
      {
        liga_verde();
        interval = int_verde;
      }
      else if (state == 1)
      {
        liga_amarelo();
        interval = int_amarelo;
      }
      else if(state == 2)
      {
        liga_vermelho();
        interval = int_vermelho;
      }
      state++;
      if(state >2)
      {
        state = 0;
      }
      previous = millis();
    }
    if(ldrstate >= 307 && ldrstate < 400)
    {
      quantidade_luz = VERDE;
    }
    else if(ldrstate >= 400 && ldrstate < 700)
    {
      quantidade_luz = AMARELO;
    }
    else if(ldrstate >= 700)
    {
      quantidade_luz = VERMELHO;
    }
    break;
    case VERDE:
    liga_verde();
    if(ldrstate < 307)
    {
      quantidade_luz = SEMAFORO;
    }
      delay(1000);
    break;
    case AMARELO:
    liga_amarelo();
    if(ldrstate < 307)
    {
      quantidade_luz = SEMAFORO;
    }
      delay(1000);
    break;
    case VERMELHO:
    liga_vermelho();
    if(ldrstate < 300)
    {
      quantidade_luz = SEMAFORO;
    }
      delay(1000);
    break;
  }
}