#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
#define RS 0
#define RW 1
#define EN 2
#define row0 0
#define row1 1
#define row2 2
#define row3 3
#define col0 4
#define col1 5
#define col2 6
#define col3 7
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
void lcdstring( char *);
void keypad_scan();
int main()
{
  PORTA=0x0f;
  DDRA =0xf0;
  lcd_init();
  while(1)
  {
    keypad_scan();
  }
}
void keypad_scan()
{
  PORTA=PORTA&~(1<<col0);
  PORTA=PORTA|(1<<col1)|(1<<col2)|(1<<col3);
  if( (PINA&(1<<row0))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 7 is pressed");
  }
  else if( (PINA&(1<<row1))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 4 is pressed");
  }
 else if( (PINA&(1<<row2))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 1 is pressed");
  }
 else if( (PINA&(1<<row3))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key ON/OF is pressed");
  }

  PORTA=PORTA&~(1<<col1);
  PORTA=PORTA|(1<<col0)|(1<<col2)|(1<<col3);

  if( (PINA&(1<<0))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 8 is pressed");
  }
  else if( (PINA&(1<<1))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 5 is pressed");
  }
 else if( (PINA&(1<<2))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 2 is pressed");
  }
 else if( (PINA&(1<<3))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 0 is pressed");
  }

  PORTA=PORTA&~(1<<col2);
  PORTA=PORTA|(1<<col0)|(1<<col1)|(1<<col3);

  if( (PINA&(1<<0))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 9 is pressed");
  }
  else if( (PINA&(1<<1))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 6 is pressed");
  }
 else if( (PINA&(1<<2))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key 3 is pressed");
  }
 else if( (PINA&(1<<3))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key = is pressed");
  }
 
  PORTA=PORTA&~(1<<col3);
  PORTA=PORTA|(1<<col0)|(1<<col1)|(1<<col2);

  if( (PINA&(1<<0))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key / is pressed");
  }
  else if( (PINA&(1<<1))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key * is pressed");
  }
 else if( (PINA&(1<<2))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key - is pressed");
  }
 else if( (PINA&(1<<3))==0)
  {
    lcdcmd(0x01);
	lcdstring("Key + is pressed");
  }
}
void lcdstring(char *x)
{
  while(*x !='\0')
  {
    lcddata(*x);
	x++;
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
	lcd=lcd&~(1<<RW);
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
	lcd=lcd&~(1<<RW);
	lcd=lcd|(1<<EN); 
	lcd=lcd&~(1<<EN); 
	_delay_ms(100);
}


















