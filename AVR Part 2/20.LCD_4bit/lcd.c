/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
int main()
{
 lcd_init();
 
 while(1)
 { 
    lcdcmd(0xc0);
 	display();
	lcdcmd(0x01);
 }
}


void display()
{
  lcddata('C');//0x41
  lcddata('E');//0x42
  lcddata('T');//0x43
  lcddata('P');//0x44
  lcddata('A');//0x32
}

void lcd_init()
{
 DDRD=0xff;
 lcdcmd(0x02);lcdcmd(0x28);lcdcmd(0x0e);
}
void lcdcmd(char x)
{
	PORTD=x&0xf0;
    lcdcmd_enable();
	PORTD= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	PORTD=PORTD&~(1<<0);// PD0==RS=0;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char x)
{ 
    PORTD=x&0xf0;
    lcddata_enable();
	PORTD=(x<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()
{
 	PORTD=PORTD|(1<<0);// PD0==RS=1;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(100);
}

*/
//************USING ARRAY******************//

/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
char a[]="CETPA "; int i;
char b[]="INFOTECH"; 
int main()
{
 lcd_init();
 
 while(1)
 { 
    lcdcmd(0xc0);
 	display();
	lcdcmd(0x01);
 }
}


void display()
{
  
  for(i=0;i<=5;i++)
  {
  	lcddata(a[i]);
  }

  for(i=0;i<=7;i++)
  {
  	lcddata(b[i]);
  }
}

void lcd_init()
{
 DDRD=0xff;
 lcdcmd(0x02);lcdcmd(0x28);lcdcmd(0x0e);
}
void lcdcmd(char x)
{
	PORTD=x&0xf0;
    lcdcmd_enable();
	PORTD= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	PORTD=PORTD&~(1<<0);// PD0==RS=0;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char x)
{ 
    PORTD=x&0xf0;
    lcddata_enable();
	PORTD=(x<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()
{
 	PORTD=PORTD|(1<<0);// PD0==RS=1;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(100);
}
*/

//************USING ARRAY******************//
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
char a[]="CETPA INFOTECH"; int i;
char b[]="PRIVATED LIMITED";
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
  for(i=0;i<=14;i++)
  {
  	lcddata(a[i]);
  }
  lcdcmd(0xc0);
  for(i=0;i<=15;i++)
  {
  	lcddata(b[i]);
  }

}

void lcd_init()
{
 DDRD=0xff;
 lcdcmd(0x02);lcdcmd(0x28);lcdcmd(0x0e);
}
void lcdcmd(char x)
{
	PORTD=x&0xf0;
    lcdcmd_enable();
	PORTD= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	PORTD=PORTD&~(1<<0);// PD0==RS=0;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char x)
{ 
    PORTD=x&0xf0;
    lcddata_enable();
	PORTD=(x<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()
{
 	PORTD=PORTD|(1<<0);// PD0==RS=1;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(100);
}

*/

//************USING ARRAY & NULL CHAR******************//
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
char a[]="CETPA INFOTECH"; int i;
char b[]="PRIVATED LIMITED";
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
  for(i=0;a[i]!='\0';i++)
  {
  	lcddata(a[i]);
  }
  lcdcmd(0xc0);
  for(i=0;b[i]!='\0';i++)
  {
  	lcddata(b[i]);
  }

}
void lcd_init()
{
 DDRD=0xff;
 lcdcmd(0x02);lcdcmd(0x28);lcdcmd(0x0e);
}
void lcdcmd(char x)
{
	PORTD=x&0xf0;
    lcdcmd_enable();
	PORTD= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	PORTD=PORTD&~(1<<0);// PD0==RS=0;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char x)
{ 
    PORTD=x&0xf0;
    lcddata_enable();
	PORTD=(x<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()

{
 	PORTD=PORTD|(1<<0);// PD0==RS=1;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(100);
}
*/

//********USING CHAR STRING NULL CHAR & POINTER ********//
// PASSING ARRAY IN A FUNCTION
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void lcd_init();
void lcddata(char );
void lcdcmd(char );
void lcdcmd_enable();
void lcddata_enable();
void display();
void lcd_write(char *);
char a[]="GOD IS ONE"; int i;
char b[]="BUT WHO BELIEVES";
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
  lcd_write(a);
  lcdcmd(0xC0);
  lcd_write(b);
}
void lcd_write(char *x)
{
  while( *x != '\0')
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
	PORTD=x&0xf0;
    lcdcmd_enable();
	PORTD= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	PORTD=PORTD&~(1<<0);// PD0==RS=0;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char data)
{ 
    PORTD=data&0xf0;
    lcddata_enable();
	PORTD=(data<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()
{
 	PORTD=PORTD|(1<<0);// PD0==RS=1;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(100);
}

*/

//********USING CHAR STRING NULL CHAR & POINTER ********//
// PASSING STRING IN A FUNCTION
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
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
  lcd_write("GOD IS ONE");//a
  lcdcmd(0xC0);
  lcd_write("BUT WHO BELIEVES");//b
}
void lcd_write(const char *x)
{
  //x[0]='S';
  while( *x != '\0')
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
	PORTD=x&0xf0;
    lcdcmd_enable();
	PORTD= (x<<4)&0xf0;
	lcdcmd_enable();
}
void lcdcmd_enable()
{
  	PORTD=PORTD&~(1<<0);// PD0==RS=0;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(1);
}
void lcddata(char data)
{ 
    PORTD=data&0xf0;
    lcddata_enable();
	PORTD=(data<<4)&0xf0;
	lcddata_enable();
	
}
void lcddata_enable()
{
 	PORTD=PORTD|(1<<0);// PD0==RS=1;
	PORTD=PORTD&~(1<<1);// PD1==RW=0;
	PORTD=PORTD|(1<<2); // PD2==EN=1;
	PORTD=PORTD&~(1<<2); // PD2==EN=0;
	_delay_ms(100);
}
*/

//********USING CHAR STRING NULL CHAR & POINTER ********//
// PASSING STRING IN A FUNCTION
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd PORTD
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
  lcd_write("GOD IS ONE");//a
  lcdcmd(0xC0);
  lcd_write("BUT WHO BELIEVES");//b
}
void lcd_write(const char *x)
{
  //x[0]='S';
  while( *x != '\0')
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
	_delay_ms(100);
}









