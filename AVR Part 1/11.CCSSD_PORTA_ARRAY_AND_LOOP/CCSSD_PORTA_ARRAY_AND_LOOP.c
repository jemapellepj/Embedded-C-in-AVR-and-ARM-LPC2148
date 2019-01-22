#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
		//		0		1	2	3	4		5   6	7	 8	  9
char ccssd[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i;
int main()
{
  while(1)
  {
  	DDRA= 0b11111111;
	for(i=0;i<=9;i++)
	{
  		PORTA=ccssd[i];
 	 	_delay_ms(300);
  	}
  }
return 0;
}
