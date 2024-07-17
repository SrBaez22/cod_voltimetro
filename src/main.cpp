#include <Arduino.h>
#define DATA 10
#define CLOCK 9
#define STB 8
#define MASK 0X80

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
  void enviaSerial_4094(unsigned char k)

  {
    unsigned char j;
    unsigned char tmp;
    for (j=0; j <= 7; j++)
    {
      tmp = k & (MASK>>j);
      if (tmp)
              digitalWrite(DATA,1);
      else
              digitalWrite(DATA,0);
      clock();
    
    }
    strobe();
  }

void converteToHex(unsigned char m){
  unsigned char aux;
  unsigned char dezena;
  unsigned char unidade;

  dezena = m/10;
  unidade = m%10;

  aux = dezena <<4 | unidade;

  enviaSerial_4094(aux);
   
}

void setup(){
pinMode(DATA,OUTPUT);
pinMode(CLOCK,OUTPUT);
pinMode(STB,OUTPUT);
digitalWrite(DATA, 0);
digitalWrite(CLOCK, 0);
digitalWrite(STB, 0);


}
void loop(){
  unsigned char i = 57;
  converteToHex(i);
  delay(1000);

}
