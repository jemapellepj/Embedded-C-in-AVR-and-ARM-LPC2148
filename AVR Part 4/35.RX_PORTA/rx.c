#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void usart_init();
void rx();
int main()
{
  usart_init();
  while(1)
  rx();

}
void usart_init()
{
  DDRA=0xff;
  UBRRL=51;
  UCSRB=UCSRB|(1<<RXEN);
  UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}
void rx()
{
  while( (UCSRA&(1<<RXC))==0);
  PORTA=UDR;
}


