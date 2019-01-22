#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define sw (PINA&(1<<0))
int main()
{
  DDRA=DDRA&~(1<<0);
  DDRC=0xff;
  while(1)
  {
    if(sw==1)
	PORTC=0x00;
	else
	PORTC=0xff;
  }
}
