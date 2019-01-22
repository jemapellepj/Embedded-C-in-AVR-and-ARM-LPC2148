#define F_CPU 1000000UL
#include<avr/io.h>
void delay();
int i;
int main()
{
  DDRA=0xff;
  TCNT0=0;
  TCCR0=0x06;
  while(1)
  {
    do
	{
	   PORTA=TCNT0;
	}while( (TIFR&(1<<TOV0))==0);    

  }
return 0;
}
