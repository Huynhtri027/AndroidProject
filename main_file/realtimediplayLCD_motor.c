
#include "msp430fg4618.h"
#include "BQ32000.c"
#include "LCD.c"
unsigned char Hourset= ;
unsigned char Minuteset= ;
unsigned char Secondset= ;
unsigned char Dateset= ;
unsigned char Monthset= ;
unsigned char Yearset= ;
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
  PxDIR=0xff;
  setting();
  while(1)
  {
    PxOUT&=~0xff;
    readbq();
    hienthi();
    if(date==Dateset && month==Monthset && year==Yearset && hour==Hourset && minute==Minuteset &&second==Secondset)
    {
      while(second!=timestop)
      {
      PxOUT=0x02;
      readbq();
      hienthi();
      }
    }
    
  }
  
}
