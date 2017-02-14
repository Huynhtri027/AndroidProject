#include "msp430FG4618.h"
#include "stepmotor.c"
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
      quay_buoc(1); 
    }
    else  if(!(P7IN&BIT1))
    {
      quay_buoc(5);
    }
    else  if(!(P7IN&BIT2))
    {
      quay_buoc(9);
    }
    else  if(!(P7IN&BIT3))
    {
      quay_buoc(13);
    }
    
     P7OUT=0xdf;
    if(!(P7IN&BIT0))
    {
      quay_buoc(2);
    }
    else  if(!(P7IN&BIT1))
    {
      quay_buoc(6);
    }
    else  if(!(P7IN&BIT2))
    {
      quay_buoc(10);
    }
    else  if(!(P7IN&BIT3))
    {
      quay_buoc(14);
    }
    
     P7OUT=0xbf;
    if(!(P7IN&BIT0))
    {
      quay_buoc(3);
    }
    else  if(!(P7IN&BIT1))
    {
      quay_buoc(7);
    }
    else  if(!(P7IN&BIT2))
    {
      quay_buoc(11);
    }
    else  if(!(P7IN&BIT3))
    {
      quay_buoc(15);
    }

	P7OUT=0x7f;
    if(!(P7IN&BIT0))
    {
      quay_buoc(4);
    }
    else  if(!(P7IN&BIT1))
    {
      quay_buoc(8);
    }
    else  if(!(P7IN&BIT2))
    {
      quay_buoc(12);
    }
    else  if(!(P7IN&BIT3))
    {
      quay_buoc(16);
    }
    PXOUT&=~0xff;
  }

  
}
