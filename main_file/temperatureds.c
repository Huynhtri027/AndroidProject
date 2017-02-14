
#include "msp430fg4618.h"
#include "library.c"
#include "ds18b20.c"
unsigned int tset;

/*void thongtin()
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
dong}*/

/*void thongtin7seg()
{


hienthidoset(tset,Do1Convert()/16);	



dong1}*/



void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  //lcd_init();
  //clear();
  //P4DIR=0xff;
  //PxDIR=0xff;
  P7DIR=BIT2;
  while(1)
  {
   //PxOUT&=~0xff;
   //thongtin();
   //thongtin7seg();
   /*if((Do1Convert()/16)>tset)
   {
     PxOUT^=0x01;
     __delay_cycles(100000);
   dong}*/
 
  }
  
}
