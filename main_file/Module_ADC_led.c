#include "msp430fg4618.h"
unsigned char a;
void main( void )
{
  // Stop watchdog timer to prevent time out reset
 WDTCTL = WDTPW + WDTHOLD;
 ADC12CTL0 = SHT0_2 + ADC12ON+REFON+REF2_5V;
 ADC12CTL1 = SHP+CONSEQ_0;
 ADC12IE = 0x01;
 ADC12CTL0 |= ENC;
 P6SEL |= 0x01;
 PXDIR=0xff;
 PXOUT&=~0xff;
 while(1)
   
 {
   ADC12CTL0 |= ADC12SC;                   // Start sampling/conversion
    __bis_SR_register(LPM0_bits|GIE);   
 }
}
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = ADC12_VECTOR

__interrupt void ADC12_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_VECTOR))) ADC12_ISR (void)
#else
#error Compiler not supported!
#endif
{
  if (ADC12MEM0 > 0x7ff)
     PXOUT |= 0x03;
  else
    PXOUT&=~0xff;
 __no_operation();
  __bic_SR_register_on_exit(LPM0_bits); 
}