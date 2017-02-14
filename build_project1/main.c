#include "msp430g2553.h"
#include "LCD.c"
#include "ds18b20.c"


void thongtin()
{
  lcd_gotoxy(0,0);
  lcd_putc('t');
  lcd_putc(223);
  lcd_puts("now : ");
  lcd_gotoxy(8,0);
  lcd2so(Do1Convert()/16); 
}



void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR=BIT2;
  lcd_init();
  clear();
  
  
  
  while(1)
  {
   thongtin();
  }
  
}
