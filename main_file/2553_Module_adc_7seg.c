#include "msp430g2553.h"
unsigned char a;
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

 
  PXDIR=0xff;
  PXSEL&=~BIT6+BIT7;
  ADC10CTL1 = INCH_0;         
  ADC10CTL0 = ADC10SHT_3+ ADC10ON +ENC;     
  ADC10AE0 |= 0x01; // kenh chuyen doi A0
  while(1)
  {
   
    
      ADC10CTL0|=ADC10SC; // adc hoat dong
    
      if(ADC10MEM>512)
      {
        PXOUT=0x03;
      }
      PXOUT&=~0xff; 
  }
}
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
  
  
  __bic_SR_register_on_exit(CPUOFF);        
}