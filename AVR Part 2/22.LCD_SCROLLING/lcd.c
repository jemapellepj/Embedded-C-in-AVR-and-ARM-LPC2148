//********USING CHAR STRING NULL CHAR & POINTER ********//
// PASSING STRING IN A FUNCTION
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
#define RS 0
#define EN 1
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
void lcd_write(const char *);
int main()
{
 lcd_init();
 
 while(1)
 { 
 	display();
	lcdcmd(0x01);
 }
}
void display()
{
  lcdcmd(0x80);
  lcd_write("WELCOME TO CETPA INFOTECH");
}
void lcd_write(const char *x)
{
  lcdcmd(0x8F);
  while( *x != '\0')
  {
 	lcddata(*x);
 	x++;
	lcdcmd(0x1c);
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
  	lcd=lcd&~(1<<RS);
	lcd=lcd|(1<<EN); 
	lcd=lcd&~(1<<EN);
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
 	lcd=lcd|(1<<RS);
	lcd=lcd|(1<<EN); 
	lcd=lcd&~(1<<EN); 
	_delay_ms(100);
}



