#include <Arduino.h>


enum State // define 2 estados para o comportamento do LDR ( maquina de estados)
  {
    ldr_ligado = 0,
    ldr_desligado
  };

  State ldr_state = ldr_ligado;


struct LDR { // Criação de uma estrutura para o LDR
    int pin;        // Pin onde está ligado o LDR
    int value;     // valor de leitura do LDR
    int threshold; // Valor a que o LDR vai acencer o LED
    int timer;     // tempo entre leituras do LDR
  };

LDR ldr = {25, 0, 1500, 500}; // iniciar as variáveis do LDR

int botao_automatico_pin = 17;
int botao_manual_pin = 16;
int led_pin = 4;
unsigned long previous = 0;
unsigned long previous2 = 0;



void setup() 
{
  Serial.begin(115200); 
  pinMode(ldr.pin, INPUT); 
  pinMode(led_pin, OUTPUT);
  pinMode(botao_automatico_pin, INPUT);
  pinMode(botao_manual_pin, INPUT);
}




 
void loop() 
{
  if(millis()-previous > 500)           // de meio em meio segundo verifica o estado do botão automático
  {
    if(digitalRead(botao_automatico_pin) == HIGH)
    {
      ldr_state = ldr_ligado;                                 // dependendo do seu estado muda para o caso apropriado
    }
    else if(digitalRead(botao_automatico_pin) == LOW)
    {
      ldr_state = ldr_desligado;
    }
    previous = millis();
  }
  switch (ldr_state) 
  {
    case ldr_ligado:
    if(millis() - previous2 > ldr.timer)  // faz a leitura do LDR de acordo com o tempo definido
    {
      ldr.value = analogRead(ldr.pin);
      previous2 = millis();
      Serial.printf("LDR Value: %d\n", ldr.value);  // escreve no monitor o valor de leitura do LDR e se está escuro ou não dependendo do valor que definimos
      if(ldr.value > ldr.threshold)
      {
        Serial.println("LDR is in light condition.");
        digitalWrite(led_pin, HIGH);
      }
      else
      {
        Serial.println("LDR is in dark condition.");
        digitalWrite(led_pin, LOW);
      }
    }
      break;
    
    case ldr_desligado:
    if(digitalRead(botao_manual_pin) == LOW) // o funcionamento do LED é controlado de forma manual com um botão
    {
      digitalWrite(led_pin, HIGH);
    }
    else
    {
      digitalWrite(led_pin, LOW);
    }
    break;
}
}

