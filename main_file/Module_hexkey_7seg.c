#include "msp430FG4618.h"
#include "7seg.c"
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  PXDIR=0xff;
  P7DIR=0xf0;
  
  while(1)
  {
    
    P7OUT=0xef;
    if(!(P7IN&BIT0))
    {
      hienthi(1); 
    }
    else  if(!(P7IN&BIT1))
    {
      hienthi(5);
    }
    else  if(!(P7IN&BIT2))
    {
      hienthi(9);
    }
    else  if(!(P7IN&BIT3))
    {
      hienthi(13);
    }
    
     P7OUT=0xdf;
    if(!(P7IN&BIT0))
    {
      hienthi(2);
    }
    else  if(!(P7IN&BIT1))
    {
      hienthi(6);
    }
    else  if(!(P7IN&BIT2))
    {
      hienthi(10);
    }
    else  if(!(P7IN&BIT3))
    {
      hienthi(14);
    }
    
     P7OUT=0xbf;
    if(!(P7IN&BIT0))
    {
      hienthi(3);
    }
    else  if(!(P7IN&BIT1))
    {
      hienthi(7);
    }
    else  if(!(P7IN&BIT2))
    {
      hienthi(11);
    }
    else  if(!(P7IN&BIT3))
    {
      hienthi(15);
    }

	P7OUT=0x7f;
    if(!(P7IN&BIT0))
    {
      hienthi(4);
    }
    else  if(!(P7IN&BIT1))
    {
      hienthi(8);
    }
    else  if(!(P7IN&BIT2))
    {
      hienthi(12);
    }
    else  if(!(P7IN&BIT3))
    {
      hienthi(16);
    }
    PXOUT=0xff;
  }

  
}
