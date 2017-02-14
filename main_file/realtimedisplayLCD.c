
#include "msp430fg4618.h"
#include "BQ32000.c"
#include "library.c"

void setting()
{
  
      date;
      month;
      year;
      hour;
      minute;
      second;
      writebq();
}
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  lcd_init();
  clear();
  setting();
  while(1)
  {
    
    readbq();
    hienthi();
  }
  
}
