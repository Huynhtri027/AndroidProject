
#include "msp430fg4618.h"
#include "BQ32000.c"
#include "library.c"
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR=0xff;
      
      hour;
      minute;
      second;
      writebq();
  
  
  while(1)
  {
    readbq();
    hienthirealtime(hour,minute,second);
  }
  
}
