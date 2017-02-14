#include "msp430fg4618.h"
#include "eeprom.c"
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  PXDIR=0xff;
  PXOUT&=~0xff;
  macdinh
  
  
 
}
