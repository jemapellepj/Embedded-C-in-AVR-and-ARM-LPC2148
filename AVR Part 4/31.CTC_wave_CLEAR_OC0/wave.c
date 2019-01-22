#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int main()
{
  DDRB=DDRB|(1<<PB3);
  TCNT0=0;
  OCR0=4;
  TCCR0=0x29;
  while(1);
}
