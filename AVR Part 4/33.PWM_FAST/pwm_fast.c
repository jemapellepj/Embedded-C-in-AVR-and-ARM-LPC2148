/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int main()
{
  DDRB=DDRB|(1<<PB3);
  TCNT0=99;
  OCR0=99;
  TCCR0=0x69;
  while(1);
}
*/
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int i;
int main()
{
  DDRB=DDRB|(1<<PB3);
  TCNT0=99;
  TCCR0=0x69;
  while(1)
  {
      for(i=0;i<=255;i++)
	  {
	     OCR0=i;
		_delay_ms(10);
       }
  }
}

*/
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int i;
int main()
{
  DDRB=DDRB|(1<<PB3);
  DDRD=DDRD|(1<<PD7);
  TCNT0=99;TCCR0=0x69;
  TCNT2=99;TCCR2=0x69;
  while(1)
  {
      for(i=0;i<=255;i++)
	  {
	     OCR0=OCR2=i;
		_delay_ms(10);
       }
  }
}
*/

/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int i;
int main()
{
  DDRB=DDRB|(1<<PB3);
  DDRD=DDRD|(1<<PD7);
  TCNT0=99;TCCR0=0x69;
  TCNT2=99;TCCR2=0x69;
  while(1)
  {
      for(i=0;i<=255;i++)
	  {
	     OCR0=OCR2=i;
		_delay_ms(10);
       }
  }
}
*/

#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int i;
int main()
{
  DDRB=DDRB|(1<<PB3);
  DDRD=DDRD|(1<<PD7);
  TCNT0=99;TCCR0=0x69;
  TCNT2=99;TCCR2=0x79;
  while(1)
  {
      for(i=0;i<=255;i++)
	  {
	     OCR0=OCR2=i;
		_delay_ms(10);
       }
  }
}

