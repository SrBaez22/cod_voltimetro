#include <Arduino.h>
#define AD A0
void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned int leitura;
  float voltimetro;
  while (1){
 
  
  leitura = analogRead(AD);
  voltimetro = (leitura * (3.3/1024));

  Serial.println(voltimetro);
  delay(10);
}
}
