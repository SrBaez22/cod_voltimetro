#include <Arduino.h>
#define DATA 10
#define CLOCK 9
#define STB 8
#define MASK 0X80
#define ponto 7
#define AD 36 
#define Vmax 3.3 
#define Resolucao 4096

void clock(void){
  digitalWrite(CLOCK,0);
  delay(100);
  digitalWrite(CLOCK,1);
  delay(100);
  digitalWrite(CLOCK,0);

}
void strobe(void){
  digitalWrite(STB,0);
  delay(10);
  digitalWrite(STB,1);
  delay(10);
  digitalWrite(STB,0);

}
  void enviaSerial_4094(unsigned int k)

  {
    unsigned char j;
    unsigned int tmp;
    for (j=0; j <= 15; j++)
    {
      tmp = k & (MASK>>j);
      if (tmp){
              digitalWrite(DATA,1);
              Serial.print(1);
      }
      else{
              digitalWrite(DATA,0);
              Serial.print(0);
    }
      clock();
    
    }
              Serial.println("");

    strobe();
  }

void converteToHex(unsigned int m){

 // char buf[10];

  unsigned int aux;
  unsigned int tmp;
  unsigned int milhar;
  unsigned int centena;
  unsigned int dezena;
  unsigned int unidade;

  milhar = m/1000;
  aux = m % 1000;
  centena = aux/100;

  dezena = m/10;
  unidade = m%10;
 // Serial.println(milhar);
  //Serial.println(centena);
  //Serial.println(dezena);
  //Serial.println(unidade);

tmp=(milhar<<12) | (centena<<8)|(dezena<<4)|unidade;
// sprintf(buf, "%X4 -- %d",tmp, tmp);

 // Serial.print("Hexadecimal=");
  //Serial.println(buf);
  enviaSerial_4094(tmp);
   
}

void setup(){
Serial.begin(9600);

pinMode(DATA,OUTPUT);
pinMode(CLOCK,OUTPUT);
pinMode(STB,OUTPUT);
pinMode(ponto, OUTPUT);

digitalWrite(DATA, 0);
digitalWrite(CLOCK, 0);
digitalWrite(STB, 0);
digitalWrite(ponto, 0);


}
void loop(){
unsigned int leitura;
  float voltimetro;
 


  leitura = analogRead(AD);
  int ValorLido;

  voltimetro = (leitura * (3.3/1024));
ValorLido = voltimetro*100;

  Serial.println(ValorLido);



 // unsigned int i = 2457;
  converteToHex(ValorLido);
  digitalWrite(ponto, 1);
    delay(10);
 // Serial.println(i);
 // delay(1000);

}
