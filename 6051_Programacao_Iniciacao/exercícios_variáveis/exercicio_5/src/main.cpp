#include <Arduino.h>


void setup()
{
Serial.begin(115200);
Serial.printf("int:%d\n", sizeof(int));
Serial.printf("float :%d\n", sizeof(float));
Serial.printf("double :%d\n", sizeof(double));
Serial.printf("char :%d\n", sizeof(char));
Serial.printf("bool :%d\n", sizeof(bool));
Serial.printf("short :%d\n", sizeof(short));
Serial.printf("long :%d\n", sizeof(long));
Serial.printf("long long :%d\n", sizeof(long long));
}



void loop() 
{
 
}

