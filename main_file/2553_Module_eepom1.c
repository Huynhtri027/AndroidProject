#include "msp430g2553.h"
#include "eeprom.c"
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P2SEL&=~BIT6+BIT7;
  PXDIR=0xff;
  PXOUT&=~0xff;
  for(int i=batdau;i<=ketthuc;i++)
{
  macdinh
__delay_cycles(1000000);
} 
  
 
}
