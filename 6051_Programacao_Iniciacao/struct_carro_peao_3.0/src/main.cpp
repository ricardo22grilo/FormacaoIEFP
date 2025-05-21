#include <Arduino.h>

//esta versão do código tira partido da coordenação dos vários semáforos, utilizando o mesmo periférico para controlar vários Leds




// definimos a estrutura para os semáforos dos carros
struct Sem_Carros
{
  bool estado_verde;
  bool estado_amarelo;
  bool estado_vermelho;
  const int pin_verde;
  const int pin_amarelo;
  const int pin_vermelho;
};

// definimos a estrutura para os semáforos dos peões
struct sem_peao
{
  bool estado_verde;
  bool estado_vermelho;
  const int pin_verde;
  const int pin_vermelho;
};
 
//criamos as variáveis para os semáforos dos carros
Sem_Carros sc1 = {HIGH,LOW,LOW,17,16,4};
Sem_Carros sc2 = {LOW,LOW,HIGH,25,26,0};

//criamos as variáveis para os semáforos dos peões
sem_peao sp1 = {HIGH,LOW,14,13};
sem_peao sp2 = {LOW,HIGH,12,2};


unsigned long previous = millis();

unsigned int tempo_vermelho = 3000;
unsigned int tempo_amarelo = 1000;
unsigned int tempo_verde = 3000;

//criamos uma variáveis para controlar os diferentes estados dos semáforos
enum State
  {
    sc1_vermelho_sc2_verde = 0,
    sc1_vermelho_sc2_amarelo,
    sc1_verde_sc2_vermelho,
    sc1_amarelo_sc2_vermelho
  };

  State estado = sc1_vermelho_sc2_verde;


//criamos funções para ligar cada combinação de semáforos 
void liga_sem1_verde()
{
  if ( sc1.estado_verde == LOW && sc1.estado_amarelo == LOW && sc1.estado_vermelho == HIGH)
  {
    sc1.estado_verde = !sc1.estado_verde;
    digitalWrite(sc1.pin_verde, sc1.estado_verde);
    sc1.estado_vermelho = !sc1.estado_vermelho;
    digitalWrite(sc1.pin_vermelho, sc1.estado_vermelho);
    digitalWrite(sc1.pin_amarelo, sc1.estado_amarelo);
  } 

  if (sp1.estado_verde == HIGH && sp1.estado_vermelho == LOW)
  {
    sp1.estado_verde = !sp1.estado_verde;
    digitalWrite(sp1.pin_verde, sp1.estado_verde);
    sp1.estado_vermelho = !sp1.estado_vermelho;
    digitalWrite(sp1.pin_vermelho, sp1.estado_vermelho);
  }
}

void liga_sem2_verde()
{
  if( sc2.estado_verde == LOW && sc2.estado_amarelo == LOW && sc2.estado_vermelho == HIGH)
  {
    sc2.estado_verde = !sc2.estado_verde;
    digitalWrite(sc2.pin_verde, sc2.estado_verde);
    sc2.estado_vermelho = !sc2.estado_vermelho;
    digitalWrite(sc2.pin_vermelho, sc2.estado_vermelho);
    digitalWrite(sc2.pin_amarelo, sc2.estado_amarelo);
  }
  if (sp2.estado_verde == HIGH && sp2.estado_vermelho == LOW)
  {
    sp2.estado_verde = !sp2.estado_verde;
    digitalWrite(sp2.pin_verde, sp2.estado_verde);
    sp2.estado_vermelho = !sp2.estado_vermelho;
    digitalWrite(sp2.pin_vermelho, sp2.estado_vermelho);
  }
}

void liga_sem1_vermelho()
{
  if( sc1.estado_vermelho == LOW && sc1.estado_amarelo == HIGH && sc1.estado_verde == LOW)
  {
    digitalWrite(sc1.pin_verde, sc1.estado_verde);
    sc1.estado_vermelho = !sc1.estado_vermelho;
    digitalWrite(sc1.pin_vermelho, sc1.estado_vermelho);
    sc1.estado_amarelo = !sc1.estado_amarelo;
    digitalWrite(sc1.pin_amarelo, sc1.estado_amarelo);
  }
  if (sp1.estado_verde == LOW && sp1.estado_vermelho == HIGH)
  {
    sp1.estado_verde = !sp1.estado_verde;
    digitalWrite(sp1.pin_verde, sp1.estado_verde);
    sp1.estado_vermelho = !sp1.estado_vermelho;
    digitalWrite(sp1.pin_vermelho, sp1.estado_vermelho);
  }
}


void liga_sem2_vermelho()
{
   if(sc2.estado_vermelho == LOW && sc2.estado_amarelo == HIGH && sc2.estado_verde == LOW)
  {
    digitalWrite(sc2.pin_verde, sc2.estado_verde);
    sc2.estado_vermelho = !sc2.estado_vermelho;
    digitalWrite(sc2.pin_vermelho, sc2.estado_vermelho);
    sc2.estado_amarelo = !sc2.estado_amarelo;
    digitalWrite(sc2.pin_amarelo, sc2.estado_amarelo);
  }
  if (sp2.estado_verde == LOW && sp2.estado_vermelho == HIGH)
  {
    sp2.estado_verde = !sp2.estado_verde;
    digitalWrite(sp2.pin_verde, sp2.estado_verde);
    sp2.estado_vermelho = !sp2.estado_vermelho;
    digitalWrite(sp2.pin_vermelho, sp2.estado_vermelho);
  }
}

void liga_sem1_amarelo()
{
  if( sc1.estado_vermelho == LOW && sc1.estado_amarelo == LOW && sc1.estado_verde == HIGH)
  {
    sc1.estado_verde = !sc1.estado_verde;
    digitalWrite(sc1.pin_verde, sc1.estado_verde);
    digitalWrite(sc1.pin_vermelho, sc1.estado_vermelho);
    sc1.estado_amarelo = !sc1.estado_amarelo;
    digitalWrite(sc1.pin_amarelo, sc1.estado_amarelo);
  }
}

void liga_sem2_amarelo()
{
  if(sc2.estado_vermelho == LOW && sc2.estado_amarelo == LOW && sc2.estado_verde == HIGH)
  {
    sc2.estado_verde = !sc2.estado_verde;
    digitalWrite(sc2.pin_verde, sc2.estado_verde);
    digitalWrite(sc2.pin_vermelho, sc2.estado_vermelho);
    sc2.estado_amarelo = !sc2.estado_amarelo;
    digitalWrite(sc2.pin_amarelo, sc2.estado_amarelo);
  }
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

  digitalWrite(sc2.pin_verde, sc2.estado_verde);
  digitalWrite(sc2.pin_vermelho, sc2.estado_vermelho);
  digitalWrite(sc2.pin_amarelo, sc2.estado_amarelo);

  digitalWrite(sc1.pin_verde, sc1.estado_verde);
  digitalWrite(sc1.pin_vermelho, sc1.estado_vermelho);
  digitalWrite(sc1.pin_amarelo, sc1.estado_amarelo);

  digitalWrite(sp1.pin_verde, sp1.estado_verde);
  digitalWrite(sp1.pin_vermelho, sp1.estado_vermelho);
  digitalWrite(sp2.pin_verde, sp2.estado_verde);
  digitalWrite(sp2.pin_vermelho, sp2.estado_vermelho);

  previous = millis();
 

}


void loop() 
{
  switch(estado)
    {
    case sc1_vermelho_sc2_verde:
      liga_sem1_vermelho();
      liga_sem2_verde();

      if(millis() - previous > tempo_vermelho)
      {
        estado = sc1_vermelho_sc2_amarelo;
        previous = millis();
      }
      break;
    case sc1_vermelho_sc2_amarelo:
    liga_sem1_vermelho();
    liga_sem2_amarelo();

      if(millis() - previous > tempo_amarelo)
      {
        estado = sc1_verde_sc2_vermelho;
        previous = millis();
      }
      break;
    case sc1_verde_sc2_vermelho:
      liga_sem1_verde();
      liga_sem2_vermelho();

      if(millis() - previous > tempo_verde)
      {
        estado = sc1_amarelo_sc2_vermelho;
        previous = millis();
      }
      break;
    case sc1_amarelo_sc2_vermelho:
      liga_sem1_amarelo();
      liga_sem2_vermelho();

      if(millis() - previous > tempo_amarelo )
      {
        estado = sc1_vermelho_sc2_verde;
        previous = millis();
      }
      break;
    }
}
