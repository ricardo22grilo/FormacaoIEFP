#include <Arduino.h>

/*int const led_verde = 17;
int const led_amarelo = 16;
int const led_vermelho = 4;
unsigned long previous = 0;
int interval = 1000;

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

void setup()
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void loop()
{
  if( millis() - previous > interval && millis() - previous < 2 * interval)
  {
    liga_verde();
  }
  if(millis() - previous > 2*interval && millis() - previous < 3 * interval)
  {
    liga_amarelo();
  }
  if(millis() - previous > 3*interval)
  {
    liga_vermelho();
    previous = millis();
  }
}*/

/*int const led_verde = 17;
int const led_amarelo = 16;
int const led_vermelho = 4;
unsigned long previous = 0;
int interval = 10000;

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

void setup()
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void loop()
{
  if( millis() - previous > interval )
  {
    if(state == 0)
    {
      liga_verde();
      interval = 2000;
    }
    else if (state == 1)
    {
      liga_amarelo();
      interval = 10000;
    }
    else if(state == 2)
    {
      liga_vermelho();
    }
    state++;
    if(state >2)
  {
    state = 0;
  }
  previous = millis();
  }
  
}*/

// este é o código do semáforo, mas com intervalo a  atualizar

int const led_verde = 17;
int const led_amarelo = 16;
int const led_vermelho = 4;
unsigned long previous = 0;
int interval;
int int_verde = 3000;
int int_amarelo = 2000;
int int_vermelho = 5000;

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

void setup()
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void loop()
{
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
  
}