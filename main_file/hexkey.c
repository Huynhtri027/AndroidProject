
#include "msp430FG4618.h"
#include "library.c"
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  PxDIR=0xff;
  P7DIR=0xf0;
  
  while(1)
  {
    
    P7OUT=0xef;
    if(!(P7IN&BIT0))
    {
      macdinh1; 
    }
    else  if(!(P7IN&BIT1))
    {
      macdinh5;
    }
    else  if(!(P7IN&BIT2))
    {
      macdinh9;
    }
    else  if(!(P7IN&BIT3))
    {
      macdinhd;
    }
    
     P7OUT=0xdf;
    if(!(P7IN&BIT0))
    {
      macdinh2;
    }
    else  if(!(P7IN&BIT1))
    {
      macdinh6;
    }
    else  if(!(P7IN&BIT2))
    {
      macdinha;
    }
    else  if(!(P7IN&BIT3))
    {
      macdinhe;
    }
    
     P7OUT=0xbf;
    if(!(P7IN&BIT0))
    {
      macdinh3;
    }
    else  if(!(P7IN&BIT1))
    {
      macdinh7;
    }
    else  if(!(P7IN&BIT2))
    {
      macdinhb;
    }
    else  if(!(P7IN&BIT3))
    {
      macdinhf;
    }

	P7OUT=0x7f;
    if(!(P7IN&BIT0))
    {
      macdinh4;
    }
    else  if(!(P7IN&BIT1))
    {
      macdinh8;
    }
    else  if(!(P7IN&BIT2))
    {
      macdinhc;
    }
    else  if(!(P7IN&BIT3))
    {
      macdinhg;
    }
    //PxOUT=0xff;
  }

  
}
