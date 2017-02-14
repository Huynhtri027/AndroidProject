#include "msp430g2553.h"
#include "7seg.c"
void main( void )
{

  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  PxDIR=0xff;
  P2SEL&=~BIT6+BIT7;
  PXIE|=0X03;
  PXIES|=0X03;
  PXIFG&=~0X03;
  _BIS_SR(GIE);
  while(1)
  {
   hienthi(0);
  }
}

#pragma vector=PORT2_VECTOR
__interrupt void Port2_ISR(void)
{
  if(!(PXIFG&0x01))
  {
    demxuong1(99);
  }
  PXIFG&=~0x01;
  
  if(!(PXIFG&0x02))
  {
    demlen1(10);
  }
  PXIFG&=~0x02;
}
