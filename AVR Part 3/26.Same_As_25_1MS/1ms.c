//REPEATED DELAY
/*
#define F_CPU 1000000UL
#include<avr/io.h>
void delay();
int i;
int main()
{
  DDRA=DDRA|(1<<0);
  while(1)
  {
    
        PORTA=PORTA|(1<<0);
        for(i=0;i<=3;i++)
     	delay();
        PORTA=PORTA&~(1<<0);
	    for(i=0;i<=3;i++)
         delay();
  }
}
void delay()
{
  TCNT0=6;
  TCCR0=0x01;
  while( (TIFR&(1<<TOV0))==0);//100uS
  TIFR=TIFR|(1<<TOV0);


}
*/
//Prescale 
#define F_CPU 1000000UL
#include<avr/io.h>
void delay();
int i;
int main()
{
  DDRA=DDRA|(1<<0);
  while(1)
  {
    
        PORTA=PORTA|(1<<0);
     	delay();
        PORTA=PORTA&~(1<<0);
         delay();
  }
}
void delay()
{
  TCNT0=131;
  TCCR0=0x02;
  while( (TIFR&(1<<TOV0))==0);//100uS
  TIFR=TIFR|(1<<TOV0);


}







