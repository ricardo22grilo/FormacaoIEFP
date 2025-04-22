#include <Arduino.h>

double temp_sensor[20]; // define um array com 20 posições para guardar os valores da temperatura
int posicao = 0; // variavel para controlar a posição do array
double media = 0;
double Vout = 0; // variavel que vai armazenar o valor lido no thermistor
int thermistorPin = A0; // define o pino usado para ler o sensor
float R1 = 10000;

float R2, logR2, logR2Cube, tK, tC, tF;  // valores usados na equação de steinhart-hart para calcular a temperatura do sensor
float A = 1.129148e-3; // valores usados na equação de steinhart-hart para calcular a temperatura do sensor
float B = 2.34125e-4; // valores usados na equação de steinhart-hart para calcular a temperatura do sensor
float C = 8.76741e-8; // valores usados na equação de steinhart-hart para calcular a temperatura do sensor
 long previous = millis();  


void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  if(millis()-previous >1000) // ciclo if que vai controlar o intervalo entre cada leitura do sensor
  {
    Vout = analogRead(thermistorPin); 
    R2 = 10000*(4095.0/Vout -1.0);
    logR2 = log(R2);
    logR2Cube = pow(logR2,3);
    tK = (1.0 / (A + B*logR2 + C*logR2Cube)); // equação de steinhart-hart para calcular a temperatura do sensor
    tC = tK - 273.15; // converte a temperatura calculada em Kelvin para Celcius

    temp_sensor[posicao] = tC; // guarda o valor calculado na posição do array
    Serial.printf("Temperatura: %f\n", temp_sensor[posicao]); // inprime o valor de cada leitura 
    posicao++; // faz o incremento a posição do array
    if(posicao == 20) // ciclo if para controlar o tamanho do array, quando chega a 20 retoma para zero, e calcula a média com os valores obtidos
    {
      posicao = 0;
      media = (temp_sensor[0] + temp_sensor[1] + temp_sensor[2] + temp_sensor[3] + temp_sensor[4] + temp_sensor[5] + temp_sensor[6] + temp_sensor[7] + temp_sensor[8] + temp_sensor[9] + temp_sensor[10] + temp_sensor[11] + temp_sensor[12] + temp_sensor[13] + temp_sensor[14] + temp_sensor[15] + temp_sensor[16] + temp_sensor[17] + temp_sensor[18] + temp_sensor[19])/20;
      Serial.printf("Media: %f\n", media);   
    }
    previous = millis(); // retoma o valor de millis para iniciar de novo o ciclo if de leitura do sensor
  }
}

