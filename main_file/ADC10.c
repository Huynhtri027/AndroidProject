#include "msp430g2553.h"
#include "LCD.c"
unsigned char a;
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

 
  lcd_init();
  clear();
  ADC10CTL1 = INCH_4;         
  ADC10CTL0 = ADC10SHT_3+ ADC10ON +ENC;     
  ADC10AE0 |= BIT4; // kenh chuyen doi A0
  while(1)
  {
   
    
      ADC10CTL0|=ADC10SC; // adc hoat dong
    
      a=ADC10MEM*5/1024;
      lcd_gotoxy(0,0);
      lcd2so(a);  
  }
}
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
  
  
  __bic_SR_register_on_exit(CPUOFF);        
}