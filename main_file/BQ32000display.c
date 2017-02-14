
#include "msp430fg4618.h"
#include "LCD.c"
#include "BQ32000.c"

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  lcd_init();
  clear();
  while(1)
  {
    readbq();
    hienthi();
  }
  
}
