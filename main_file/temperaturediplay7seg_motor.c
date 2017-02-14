
#include "msp430fg4618.h"
#include "ds18b20.c"
#include "library.c"
unsigned int tset;



void thongtin7seg()
{
hienthidoset(tset,Do1Convert()/16);	
}

void motor()
{
	while((Do1Convert()/16)>tset)
	{
		P11OUT=0x02;
		thongtin7seg();
	}
}



void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P7DIR=BIT2;
  PxDIR=0xff;	// led 7seg
  P11DIR=0xff;
  
  while(1)
  {
   P11OUT&=~0xff;
   thongtin7seg();
   motor();
  }
  
}
