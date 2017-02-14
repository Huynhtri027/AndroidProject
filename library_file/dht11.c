#include "dht11.h"
unsigned char dht[6],err; 

int read_dht(unsigned char *p)
{
                                                                // Note: TimerA must be continuous mode (MC_2) at 1 MHz
    const unsigned b = BIT2;                                    // I/O bit
    const unsigned char *end = p + 6;                           // End of data buffer
    register unsigned char m = 1;                               // First byte will have only start bit
    register unsigned st, et;                                   // Start and end times
                                                                //
    p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = 0;                // Clear data buffer
                                                                //
    P7OUT &= ~b;                                                // Pull low
    P7DIR |= b;                                                 // Output
    //P1REN &= ~b;                                                // Drive low
    st = TAR; while((TAR - st) < 18000);                        // Wait 18 ms
    //P1REN |= b;                                                 // Pull low
    P7OUT |= b;                                                 // Pull high
    P7DIR &= ~b;                                                // Input
                                                                //
    st = TAR;                                                   // Get start time for timeout
    while(P7IN & b) if((TAR - st) > 100) return -1;             // Wait while high, return if no response
    et = TAR;                                                   // Get start time for timeout
    do {                                                        //
        st = et;                                                // Start time of this bit is end time of previous bit
        while(!(P7IN & b)) if((TAR - st) > 100) return -2;      // Wait while low, return if stuck low
        while(P7IN & b) if((TAR - st) > 200) return -3;         // Wait while high, return if stuck high
        et = TAR;                                               // Get end time
        if((et - st) > 110) *p |= m;                            // If time > 110 us, then it is a one bit
        if(!(m >>= 1)) m = 0x80, ++p;                           // Shift mask, move to next byte when mask is zero
    } while(p < end);                                           // Do until array is full
                                                                //
    p -= 6;                                                     // Point to start of buffer
    if(p[0] != 1) return -4;                                    // No start bit
    if(((p[1] + p[2] + p[3] + p[4]) & 0xFF) != p[5]) return -5; // Bad checksum
                                                                //
    return 0;                                                   // Good read
}

void dht_init()
{
    TACTL = TASSEL_2 | MC_2;                        // TimerA SMCLK, continuous
    __enable_interrupt();                           // 
    dht[1]=100;
}
void dht_read()
{
  err=read_dht(dht);
}
void hienthidht11()
{
  dht_read();
  lcd_gotoxy(11,0);
  if(!err)
  lcd2so(dht[3]);
  lcd_putc(223);
  lcd_puts("C");
  lcd_gotoxy(11,1);
  if(!err)
  lcd2so(dht[1]);
  lcd_puts("%H");
  __delay_cycles(200000);
}