#include "msp430g2553.h"
#include "LCD.c"

void hienthi(unsigned char num)
{
  lcd_gotoxy(0,0);
  lcd2so(num);
  
}
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR&=~0XFF;
  P2DIR=0XFF;
  lcd_init();
  clear();
  while(1)
  {
    P1OUT=0XEF;
    if(!(P1IN&BIT0))
    {
      hienthi(1);
    }
    else if(!(P1IN&BIT1))
    {
      hienthi(5);
    }
     else if(!(P1IN&BIT2))
    {
      hienthi(9);
    }
     else if(!(P1IN&BIT3))
    {
      hienthi(13);
    }
    P1OUT=0XDF;
    if(!(P1IN&BIT0))
    {
      hienthi(2);
    }
    else if(!(P1IN&BIT1))
    {
      hienthi(6);
    }
     else if(!(P1IN&BIT2))
    {
      hienthi(10);
    }
     else if(!(P1IN&BIT3))
    {
      hienthi(14);
    }
     P1OUT=0XBF;
    if(!(P1IN&BIT0))
    {
      hienthi(3);
    }
    else if(!(P1IN&BIT1))
    {
      hienthi(7);
    }
     else if(!(P1IN&BIT2))
    {
      hienthi(11);
    }
     else if(!(P1IN&BIT3))
    {
      hienthi(15);
    }
     P1OUT=0X7F;
    if(!(P1IN&BIT0))
    {
      hienthi(4);
    }
    else if(!(P1IN&BIT1))
    {
      hienthi(8);
    }
     else if(!(P1IN&BIT2))
    {
      hienthi(12);
    }
     else if(!(P1IN&BIT3))
    {
      hienthi(16);
    }
  }


}
