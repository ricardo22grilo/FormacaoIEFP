#include <Arduino.h>


// definimos a estrutura para os semáforos dos carros
struct Sem_Carros
{
  const int pin_amarelo;
  const int pin_vermelho;
  const int pin_verde;
};

// definimos a estrutura para os semáforos dos peões
struct sem_peao
{
  const int pin_vermelho;
  const int pin_verde;
};
 

//criamos as variáveis para os semáforos dos carros
Sem_Carros sc1 = {16,4,17};
Sem_Carros sc2 = {26,25,0};
Sem_Carros sc3 = {13,14,2};
Sem_Carros sc4 = {19,18,12};
  

//criamos as variáveis para os semáforos dos peões
sem_peao sp1 = {14,15};
sem_peao sp2 = {16,17};
sem_peao sp3 = {18,19};
sem_peao sp4 = {20,21};
sem_peao sp5 = {22,23};
sem_peao sp6 = {24,25};
sem_peao sp7 = {26,27};
sem_peao sp8 = {28,29};

unsigned long previous = millis();

unsigned int tempo_vermelho = 3000;
unsigned int tempo_amarelo = 1000;
unsigned int tempo_verde = 3000;


//criamos uma variáveis para controlar os diferentes estados dos semáforos

enum State
  {
    LED_VERDE = 0,
    LED_AMARELO,
    LED_VERMELHO,
    LED_AMARELO_VERMELHO
  };

  State estado = LED_VERDE;


//criamos funções para ligar cada combinação de semáforos 
void liga_sem1_verde()
{
  digitalWrite(sc1.pin_verde, HIGH);
  digitalWrite(sc3.pin_verde, HIGH);
  digitalWrite(sc1.pin_vermelho, LOW);
  digitalWrite(sc3.pin_vermelho, LOW);
  digitalWrite(sc3.pin_amarelo, LOW);
  digitalWrite(sc1.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,LOW);
  digitalWrite(sp1.pin_vermelho,HIGH);
  digitalWrite(sp2.pin_verde,LOW);
  digitalWrite(sp2.pin_vermelho,HIGH);
  digitalWrite(sp5.pin_verde,LOW);
  digitalWrite(sp5.pin_vermelho,HIGH);
  digitalWrite(sp6.pin_verde,LOW);
  digitalWrite(sp6.pin_vermelho,HIGH);
  digitalWrite(sp3.pin_verde,HIGH);
  digitalWrite(sp3.pin_vermelho,LOW);
  digitalWrite(sp4.pin_verde,HIGH);
  digitalWrite(sp4.pin_vermelho,LOW);
  digitalWrite(sp7.pin_verde,HIGH);
  digitalWrite(sp7.pin_vermelho,LOW);
  digitalWrite(sp8.pin_verde,HIGH);
  digitalWrite(sp8.pin_vermelho,LOW);
  
  
}

void liga_sem2_verde()
{
  digitalWrite(sc2.pin_verde, HIGH);
  digitalWrite(sc4.pin_verde, HIGH);
  digitalWrite(sc2.pin_vermelho, LOW);
  digitalWrite(sc4.pin_vermelho, LOW);
  digitalWrite(sc2.pin_amarelo, LOW);
  digitalWrite(sc4.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,HIGH);
  digitalWrite(sp1.pin_vermelho,LOW);
  digitalWrite(sp2.pin_verde,HIGH);
  digitalWrite(sp2.pin_vermelho,LOW);
  digitalWrite(sp5.pin_verde,HIGH);
  digitalWrite(sp5.pin_vermelho,LOW);
  digitalWrite(sp6.pin_verde,HIGH);
  digitalWrite(sp6.pin_vermelho,LOW);
  digitalWrite(sp3.pin_verde,LOW);
  digitalWrite(sp3.pin_vermelho,HIGH);
  digitalWrite(sp4.pin_verde,LOW);
  digitalWrite(sp4.pin_vermelho,HIGH);
  digitalWrite(sp7.pin_verde,LOW);
  digitalWrite(sp7.pin_vermelho,HIGH);
  digitalWrite(sp8.pin_verde,LOW);
  digitalWrite(sp8.pin_vermelho,HIGH);
}

void liga_sem1_vermelho()
{
  digitalWrite(sc1.pin_verde, LOW);
  digitalWrite(sc3.pin_verde, LOW);
  digitalWrite(sc1.pin_vermelho, HIGH);
  digitalWrite(sc3.pin_vermelho, HIGH);
  digitalWrite(sc3.pin_amarelo, LOW);
  digitalWrite(sc1.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,HIGH);
  digitalWrite(sp1.pin_vermelho,LOW);
  digitalWrite(sp2.pin_verde,HIGH);
  digitalWrite(sp2.pin_vermelho,LOW);
  digitalWrite(sp5.pin_verde,HIGH);
  digitalWrite(sp5.pin_vermelho,LOW);
  digitalWrite(sp6.pin_verde,HIGH);
  digitalWrite(sp6.pin_vermelho,LOW);
  digitalWrite(sp3.pin_verde,LOW);
  digitalWrite(sp3.pin_vermelho,HIGH);
  digitalWrite(sp4.pin_verde,LOW);
  digitalWrite(sp4.pin_vermelho,HIGH);
  digitalWrite(sp7.pin_verde,LOW);
  digitalWrite(sp7.pin_vermelho,HIGH);
  digitalWrite(sp8.pin_verde,LOW);
  digitalWrite(sp8.pin_vermelho,HIGH);
}


void liga_sem2_vermelho()
{
  
  digitalWrite(sc2.pin_verde, LOW);
  digitalWrite(sc4.pin_verde, LOW);
  digitalWrite(sc2.pin_vermelho, HIGH);
  digitalWrite(sc4.pin_vermelho, HIGH);
  digitalWrite(sc2.pin_amarelo, LOW);
  digitalWrite(sc4.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,LOW);
  digitalWrite(sp1.pin_vermelho,HIGH);
  digitalWrite(sp2.pin_verde,LOW);
  digitalWrite(sp2.pin_vermelho,HIGH);
  digitalWrite(sp5.pin_verde,LOW);
  digitalWrite(sp5.pin_vermelho,HIGH);
  digitalWrite(sp6.pin_verde,LOW);
  digitalWrite(sp6.pin_vermelho,HIGH);
  digitalWrite(sp3.pin_verde,HIGH);
  digitalWrite(sp3.pin_vermelho,LOW);
  digitalWrite(sp4.pin_verde,HIGH);
  digitalWrite(sp4.pin_vermelho,LOW);
  digitalWrite(sp7.pin_verde,HIGH);
  digitalWrite(sp7.pin_vermelho,LOW);
  digitalWrite(sp8.pin_verde,HIGH);
  digitalWrite(sp8.pin_vermelho,LOW);
}

void liga_sem1_amarelo()
{
  digitalWrite(sc1.pin_verde, LOW);
  digitalWrite(sc3.pin_verde, LOW);
  digitalWrite(sc1.pin_vermelho, LOW);
  digitalWrite(sc3.pin_vermelho, LOW);
  digitalWrite(sc3.pin_amarelo, HIGH);
  digitalWrite(sc1.pin_amarelo, HIGH);
  //
  digitalWrite(sp1.pin_verde,HIGH);
  digitalWrite(sp1.pin_vermelho,LOW);
  digitalWrite(sp2.pin_verde,HIGH);
  digitalWrite(sp2.pin_vermelho,LOW);
  digitalWrite(sp5.pin_verde,HIGH);
  digitalWrite(sp5.pin_vermelho,LOW);
  digitalWrite(sp6.pin_verde,HIGH);
  digitalWrite(sp6.pin_vermelho,LOW);
  digitalWrite(sp3.pin_verde,LOW);
  digitalWrite(sp3.pin_vermelho,HIGH);
  digitalWrite(sp4.pin_verde,LOW);
  digitalWrite(sp4.pin_vermelho,HIGH);
  digitalWrite(sp7.pin_verde,LOW);
  digitalWrite(sp7.pin_vermelho,HIGH);
  digitalWrite(sp8.pin_verde,LOW);
  digitalWrite(sp8.pin_vermelho,HIGH);
  //
}

void liga_sem2_amarelo()
{
  
  digitalWrite(sc2.pin_verde, LOW);
  digitalWrite(sc4.pin_verde, LOW);
  digitalWrite(sc2.pin_vermelho, LOW);
  digitalWrite(sc4.pin_vermelho, LOW);
  digitalWrite(sc2.pin_amarelo, HIGH);
  digitalWrite(sc4.pin_amarelo, HIGH);
  //
  digitalWrite(sp1.pin_verde,LOW);
  digitalWrite(sp1.pin_vermelho,HIGH);
  digitalWrite(sp2.pin_verde,LOW);
  digitalWrite(sp2.pin_vermelho,HIGH);
  digitalWrite(sp5.pin_verde,LOW);
  digitalWrite(sp5.pin_vermelho,HIGH);
  digitalWrite(sp6.pin_verde,LOW);
  digitalWrite(sp6.pin_vermelho,HIGH);
  digitalWrite(sp3.pin_verde,HIGH);
  digitalWrite(sp3.pin_vermelho,LOW);
  digitalWrite(sp4.pin_verde,HIGH);
  digitalWrite(sp4.pin_vermelho,LOW);
  digitalWrite(sp7.pin_verde,HIGH);
  digitalWrite(sp7.pin_vermelho,LOW);
  digitalWrite(sp8.pin_verde,HIGH);
  digitalWrite(sp8.pin_vermelho,LOW);
}


// defínimos a função de cada periférico
void setup()
{
  pinMode(sc1.pin_vermelho, OUTPUT);
  pinMode(sc1.pin_amarelo, OUTPUT);
  pinMode(sc1.pin_verde, OUTPUT);
  pinMode(sc2.pin_vermelho, OUTPUT);
  pinMode(sc2.pin_amarelo, OUTPUT);
  pinMode(sc2.pin_verde, OUTPUT);
  pinMode(sc3.pin_vermelho, OUTPUT);
  pinMode(sc3.pin_amarelo, OUTPUT);
  pinMode(sc3.pin_verde, OUTPUT);
  pinMode(sc4.pin_vermelho, OUTPUT);
  pinMode(sc4.pin_amarelo, OUTPUT);
  pinMode(sc4.pin_verde, OUTPUT);
  pinMode(sp1.pin_vermelho, OUTPUT);
  pinMode(sp1.pin_verde, OUTPUT);
  pinMode(sp2.pin_vermelho, OUTPUT);
  pinMode(sp2.pin_verde, OUTPUT);
  pinMode(sp3.pin_vermelho, OUTPUT);
  pinMode(sp3.pin_verde, OUTPUT);
  pinMode(sp4.pin_vermelho, OUTPUT);
  pinMode(sp4.pin_verde, OUTPUT);
  pinMode(sp5.pin_vermelho, OUTPUT);
  pinMode(sp5.pin_verde, OUTPUT);
  pinMode(sp6.pin_vermelho, OUTPUT);
  pinMode(sp6.pin_verde, OUTPUT);
  pinMode(sp7.pin_vermelho, OUTPUT);
  pinMode(sp7.pin_verde, OUTPUT);
  pinMode(sp8.pin_vermelho, OUTPUT);
  pinMode(sp8.pin_verde, OUTPUT);

}

void loop() 
{
  switch(estado)
    {
    case LED_VERDE:
      liga_sem1_vermelho();
      liga_sem2_verde();

      if(millis() - previous > tempo_vermelho)
      {
        estado = LED_AMARELO;
        previous = millis();
      }
      break;
    case LED_AMARELO:
    liga_sem1_vermelho();
    liga_sem2_amarelo();

      if(millis() - previous > tempo_amarelo)
      {
        estado = LED_VERMELHO;
        previous = millis();
      }
      break;
    case LED_VERMELHO:
      liga_sem1_verde();
      liga_sem2_vermelho();

      if(millis() - previous > tempo_verde)
      {
        estado = LED_AMARELO_VERMELHO;
        previous = millis();
      }
      break;
    case LED_AMARELO_VERMELHO:
      liga_sem1_amarelo();
      liga_sem2_vermelho();

      if(millis() - previous > tempo_amarelo )
      {
        estado = LED_VERDE;
        previous = millis();
      }
      break;
    }
}
