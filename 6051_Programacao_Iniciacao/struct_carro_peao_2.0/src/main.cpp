#include <Arduino.h>

//esta versão do código tira partido da coordenação dos vários semáforos, utilizando o mesmo periférico para controlar vários Leds




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

//criamos as variáveis para os semáforos dos peões
sem_peao sp1 = {14,15};
sem_peao sp2 = {18,19};


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
  digitalWrite(sc1.pin_vermelho, LOW);
  digitalWrite(sc1.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,LOW);
  digitalWrite(sp1.pin_vermelho,HIGH);
  digitalWrite(sp2.pin_verde,HIGH);
  digitalWrite(sp2.pin_vermelho,LOW);
  
}

void liga_sem2_verde()
{
  digitalWrite(sc2.pin_verde, HIGH);
  digitalWrite(sc2.pin_vermelho, LOW);
  digitalWrite(sc2.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,HIGH);
  digitalWrite(sp1.pin_vermelho,LOW);
  digitalWrite(sp2.pin_verde,LOW);
  digitalWrite(sp2.pin_vermelho,HIGH);
}

void liga_sem1_vermelho()
{
  digitalWrite(sc1.pin_verde, LOW);
  digitalWrite(sc1.pin_vermelho, HIGH);
  digitalWrite(sc1.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,HIGH);
  digitalWrite(sp1.pin_vermelho,LOW);
  digitalWrite(sp2.pin_verde,LOW);
  digitalWrite(sp2.pin_vermelho,HIGH);
}


void liga_sem2_vermelho()
{
  
  digitalWrite(sc2.pin_verde, LOW);
  digitalWrite(sc2.pin_vermelho, HIGH);
  digitalWrite(sc2.pin_amarelo, LOW);
  //
  digitalWrite(sp1.pin_verde,LOW);
  digitalWrite(sp1.pin_vermelho,HIGH);
  digitalWrite(sp2.pin_verde,HIGH);
  digitalWrite(sp2.pin_vermelho,LOW);
  
}

void liga_sem1_amarelo()
{
  digitalWrite(sc1.pin_verde, LOW);
  digitalWrite(sc1.pin_vermelho, LOW);
  digitalWrite(sc1.pin_amarelo, HIGH);
  //
  digitalWrite(sp1.pin_verde,HIGH);
  digitalWrite(sp1.pin_vermelho,LOW);
  digitalWrite(sp2.pin_verde,LOW);
  digitalWrite(sp2.pin_vermelho,HIGH);
  //
}

void liga_sem2_amarelo()
{
  
  digitalWrite(sc2.pin_verde, LOW);
  digitalWrite(sc2.pin_vermelho, LOW);
  digitalWrite(sc2.pin_amarelo, HIGH);
  //
  digitalWrite(sp1.pin_verde,LOW);
  digitalWrite(sp1.pin_vermelho,HIGH);
  digitalWrite(sp2.pin_verde,HIGH);
  digitalWrite(sp2.pin_vermelho,LOW);

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

  pinMode(sp1.pin_vermelho, OUTPUT);
  pinMode(sp1.pin_verde, OUTPUT);
  pinMode(sp2.pin_vermelho, OUTPUT);
  pinMode(sp2.pin_verde, OUTPUT);
 

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
