
#include "msp430fg4618.h"
#include "ds18b20.c"
#include "library.c"
unsigned int tset;

void thongtin()
{
  lcd_gotoxy(0,0);
  lcd_putc('t');
  lcd_putc(223);
  lcd_puts("now : ");
  lcd_gotoxy(8,0);
  lcd2so(Do1Convert()/16);
  
  lcd_gotoxy(0,1);
  lcd_putc('t');
  lcd_putc(223);
  lcd_puts("set : ");
  lcd_gotoxy(8,1);
  lcd2so(tset);  
}

void motor()
{
	while((Do1Convert()/16)>tset)
	{
		PxOUT=0x02;
		thongtin();
	}

}


void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P7DIR=BIT2;
  PxDIR=0xff;
  lcd_init();
  clear();
  
  
  
  while(1)
  {
   PxOUT&=~0xff;
   thongtin();
   motor();
  }
  
}