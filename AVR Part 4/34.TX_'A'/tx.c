/*
#define F_CPU 8000000UL
#include<avr/io.h>
int main()
{
  UBRRL=51;
  UCSRB=UCSRB|(1<<TXEN);
  UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
  UDR='A';
  while( (UCSRA&(1<<UDRE))==0);//wait
  UDR='B';
  while( (UCSRA&(1<<UDRE))==0);//wait
  UDR='C';
  while( (UCSRA&(1<<UDRE))==0);//wait
  UDR='D';
  while( (UCSRA&(1<<UDRE))==0);//wait
  UDR='2';
  while( (UCSRA&(1<<UDRE))==0);//wait
  while(1);
}
*/


#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void usart_init();
void tx();
void txstring(char *);
int main()
{
  usart_init();
  while(1)
  tx();

}
void usart_init()
{
   UBRRL=51;
  UCSRB=UCSRB|(1<<TXEN);
  UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}
void tx()
{
  txstring("WELCOME TO CETPA\r");
  txstring("INFOTECH PRIVATE LIMITED\r");
}

void txstring(char *x)
{
  while(*x)
  {
    UDR=*x;
	while( (UCSRA&(1<<UDRE))==0);
	_delay_ms(100);
	x++;
  }
}
