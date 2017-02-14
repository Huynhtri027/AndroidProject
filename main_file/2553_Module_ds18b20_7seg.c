
#include "msp430g2553.h"
#include "ds18b20.c"
#include "7seg.c"

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR=BIT2;
  PXDIR=0xff;	// led 7seg
  PXSEL&=~BIT6+BIT7;
  
  
  while(1)
  {
   
   hienthi(Do1Convert()/16);
   
  }
  
}
