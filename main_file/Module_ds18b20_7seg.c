
#include "msp430fg4618.h"
#include "ds18b20.c"
#include "7seg.c"



void thongtin7seg()
{
hienthi(Do1Convert()/16);	
}




void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P7DIR=BIT2;
  PxDIR=0xff;	// led 7seg
  
  
  while(1)
  {
   
   thongtin7seg();
   
  }
  
}
