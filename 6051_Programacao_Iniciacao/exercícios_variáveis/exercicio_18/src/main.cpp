#include <Arduino.h>

int a = 10;

void setup() 
{
Serial.begin(115200);
a+=10; // soma 10 ao a;
Serial.println(a);
a-=5; // subtrai 5 do a;
Serial.println(a);
a*=2; // multiplica a por 2;
Serial.println(a);
a/=3; // divide a por 3;
Serial.println(a);
a++; // incrementa a;
Serial.println(a);
a--; // decrementa a;
Serial.println(a);
}

void loop() 
{

}