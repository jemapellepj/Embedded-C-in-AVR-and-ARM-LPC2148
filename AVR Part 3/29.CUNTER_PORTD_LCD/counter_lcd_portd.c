/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void delay();
void counter_init();
int i;
int main()
{
  lcd_init();
  counter_init();
  while(1)
  {
    do
	{
	  lcdcmd(0x01);
	  lcddata(TCNT0+48);
	}while( (TIFR&(1<<TOV0))==0);    

  }
return 0;
}
void counter_init()
{
  TCNT0=0;
  TCCR0=0x06;
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
	_delay_ms(50);
}
*/


//************************************************************
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void delay();
void counter_init();
void convert_to_ascii(int );
int i;
int main()
{
  lcd_init();
  counter_init();
  while(1)
  {
    do
	{
	  lcdcmd(0x01);
	  convert_to_ascii(TCNT0);//11111110
	}while( (TIFR&(1<<TOV0))==0);    

  }
return 0;
}
void convert_to_ascii(int  a)//254
{
  int a1,i;
  char pos=131;//0x83;
   for(i=0;i<=3;i++)//i=0,1,2
   {
     lcdcmd(pos); //0x82//0x81//0x80
	 a1=a%10;  //4//5//2
	 a=a/10;   //25//2//0
	 lcddata(a1+48);//'4'//'5'//'2'
	 pos--; //0x81//0x80
   }  
}
void counter_init()
{
  TCNT0=0;
  TCCR0=0x06;
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
	_delay_ms(50);
}
