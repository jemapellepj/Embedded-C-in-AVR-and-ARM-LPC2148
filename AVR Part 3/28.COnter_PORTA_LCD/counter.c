#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void convert_ascii(int );
int main()
{
  TCNT0=0;
  TCCR0=0x06;
  lcd_init();
  while(1)
  {
    do
	{
	   //lcddata(TCNT0+48);
	   convert_ascii(TCNT0);
	   lcdcmd(0x01);
	}  while( (TIFR&(1<<TOV0))==0);    

  }
return 0;
}
void convert_ascii(int a)//253
{
  int i,a1;
  char pos=0x82;
  for(i=0;i<=2;i++)//i=0,1,2,3(flase)
  {
    lcdcmd(pos);
    a1=a%10;//3//5//2
	a=a/10; //25//2//0
	lcddata(a1+48);//'3'//'5'//'2'
	pos--;//0x81//0x80
  }
}
void lcd_init()
{
 DDRD=0xff;
 lcdcmd(0x02);lcdcmd(0x28);lcdcmd(0x0e);
}
void lcdcmd(char x)
{
	lcd=x&0xf0;
    lcdcmd_enable();
	lcd= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	lcd=lcd&~(1<<0);// PD0==RS=0;
	lcd=lcd&~(1<<1);// PD1==RW=0;
	lcd=lcd|(1<<2); // PD2==EN=1;
	lcd=lcd&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char data)
{ 
    lcd=data&0xf0;
    lcddata_enable();
	lcd=(data<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()
{
 	lcd=lcd|(1<<0);// PD0==RS=1;
	lcd=lcd&~(1<<1);// PD1==RW=0;
	lcd=lcd|(1<<2); // PD2==EN=1;
	lcd=lcd&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
