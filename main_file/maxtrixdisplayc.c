
#include "msp430fg4618.h"
#include "string.h"
#define CLK   BIT1;//xung clk 595
#define CHOT   BIT2;//chot 595
#define DATA BIT0;//du lieu

#define CLK1   BIT4;//xung clk 595
#define CHOT1   BIT5;//chot 595
#define DATA1 BIT3;//du lieu
unsigned long dich[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02};



void morong_port( unsigned long a)
{
  int b;
  unsigned long c;
  for(b=0;b<24;b++)
  {
    c=a&1;
    if (c==1)
    {PxOUT|=DATA;}
    else {PxOUT&=~DATA;}
       PxOUT&=~CLK;
       PxOUT|=CLK;
       a=a>>1;
  }
    PxOUT&=~CHOT;
    PxOUT|=CHOT;
  
    
}
void morong_port1( unsigned long a)
{
  int b;
  unsigned long c;
  for(b=0;b<8;b++)
  {
    c=a&1;
    if (c==1)
    {PxOUT|=DATA1;}
    else {PxOUT&=~DATA1;}
       PxOUT&=~CLK1;
       PxOUT|=CLK1;
       a=a>>1;
  } 
    PxOUT&=~CHOT1;
    PxOUT|=CHOT1;
}

void hienthist(unsigned long kitu[7],unsigned long kitu1[7],unsigned long kitu2[7])
{
  
    for(int h=0;h<6;h++)
    {
      kitu1[0]=kitu1[0]>>1;kitu1[1]=kitu1[1]>>1;kitu1[2]=kitu1[2]>>1;kitu1[3]=kitu1[3]>>1;
      kitu1[4]=kitu1[4]>>1;kitu1[5]=kitu1[5]>>1;kitu1[6]=kitu1[6]>>1;
    }
    
    for(int h=0;h<12;h++)
    {
      kitu2[0]=kitu2[0]>>1;kitu2[1]=kitu2[1]>>1;kitu2[2]=kitu2[2]>>1;kitu2[3]=kitu2[3]>>1;
      kitu2[4]=kitu2[4]>>1;kitu2[5]=kitu2[5]>>1;kitu2[6]=kitu2[6]>>1;
    }
    
    for(int j=0;j<25;j++)
    {
      
    for(int i=0;i<7;i++)
    { 
      morong_port(~(kitu[i]+kitu1[i]+kitu2[i]));
      morong_port1(dich[i]);
      __delay_cycles(3000);
      morong_port1(0x00);
    }
    kitu[0]=kitu[0]>>1;kitu[1]=kitu[1]>>1;kitu[2]=kitu[2]>>1;kitu[3]=kitu[3]>>1;
    kitu[4]=kitu[4]>>1;kitu[5]=kitu[5]>>1;kitu[6]=kitu[6]>>1;
    
    kitu1[0]=kitu1[0]>>1;kitu1[1]=kitu1[1]>>1;kitu1[2]=kitu1[2]>>1;kitu1[3]=kitu1[3]>>1;
    kitu1[4]=kitu1[4]>>1;kitu1[5]=kitu1[5]>>1;kitu1[6]=kitu1[6]>>1;
    
    kitu2[0]=kitu2[0]>>1;kitu2[1]=kitu2[1]>>1;kitu2[2]=kitu2[2]>>1;kitu2[3]=kitu2[3]>>1;
    kitu2[4]=kitu2[4]>>1;kitu2[5]=kitu2[5]>>1;kitu2[6]=kitu2[6]>>1;
    
    }   
}

void hienthichd(unsigned long kitu[7])
{
  
    
    for(int j=0;j<100;j++)
    {
    for(int i=0;i<9;i++)
    {
      morong_port(~kitu[i]);
      morong_port1(dich[i]);
      __delay_cycles(1000);
      morong_port1(0x00);
    }
    
    }
    
}
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  PxDIR=0XFF;
   while(1)
   {

unsigned long a[]={0x700000,0x880000,0x880000,0xf80000,0x880000,0x880000,0x880000};
unsigned long b[]={0xf00000,0x880000,0x880000,0xf80000,0x880000,0x880000,0xf00000};
unsigned long c[]={0x700000,0x880000,0x800000,0x800000,0x800000,0x880000,0x700000};
unsigned long d[]={0xf00000,0x880000,0x880000,0x880000,0x880000,0x880000,0xf00000};
unsigned long e[]={0xf00000,0x800000,0x800000,0xf00000,0x800000,0x800000,0xf00000};
unsigned long f[]={0xf00000,0x800000,0x800000,0xf00000,0x800000,0x800000,0x800000};
unsigned long g[]={0xf00000,0x880000,0x800000,0x980000,0x880000,0x880000,0x700000};
unsigned long h[]={0x880000,0x880000,0x880000,0xf80000,0x880000,0x880000,0x880000};
unsigned long i[]={0xf80000,0x200000,0x200000,0x200000,0x200000,0x200000,0xf80000};
unsigned long j[]={0xf80000,0x200000,0x200000,0x200000,0x200000,0x200000,0xc00000};
unsigned long k[]={0x880000,0x900000,0xa00000,0xc00000,0xa00000,0x900000,0x880000};
unsigned long l[]={0x800000,0x800000,0x800000,0x800000,0x800000,0x800000,0xf80000};
unsigned long m[]={0x880000,0xd80000,0xa80000,0x880000,0x880000,0x880000,0x880000};
unsigned long n[]={0x880000,0xc80000,0xa80000,0x980000,0x880000,0x880000,0x880000};
unsigned long o[]={0x700000,0x880000,0x880000,0x880000,0x880000,0x880000,0x700000};
unsigned long p[]={0x700000,0x880000,0x880000,0xf00000,0x800000,0x800000,0x800000};
unsigned long q[]={0x700000,0x880000,0x880000,0x880000,0x880000,0x980000,0x780000};
unsigned long r[]={0xf00000,0x880000,0x880000,0xf00000,0xa00000,0x900000,0x880000};
unsigned long s[]={0x700000,0x880000,0x880000,0x600000,0x180000,0x880000,0xf00000};
unsigned long t[]={0xf80000,0x200000,0x200000,0x200000,0x200000,0x200000,0x200000};
unsigned long u[]={0x880000,0x880000,0x880000,0x880000,0x880000,0x880000,0x700000};
unsigned long v[]={0x880000,0x880000,0x880000,0x880000,0x880000,0x500000,0x200000};
unsigned long w[]={0x880000,0x880000,0x880000,0x880000,0xa80000,0xd80000,0x880000};
unsigned long x[]={0x880000,0x880000,0x500000,0x200000,0x500000,0x880000,0x880000};
unsigned long y[]={0x880000,0x880000,0x500000,0x200000,0x200000,0x200000,0x200000};
unsigned long z[]={0xf80000,0x080000,0x100000,0x200000,0x400000,0x800000,0xf80000};

unsigned long _1[]={0x200000,0x600000,0xa00000,0x200000,0x200000,0x200000,0xf80000};
unsigned long _2[]={0x700000,0x880000,0x080000,0x100000,0x200000,0x400000,0xf80000};
unsigned long _3[]={0x700000,0x880000,0x080000,0x100000,0x080000,0x880000,0x700000};
unsigned long _4[]={0x080000,0x180000,0x280000,0x480000,0x880000,0xf80000,0x080000};
unsigned long _5[]={0xf80000,0x800000,0x800000,0xf00000,0x080000,0x080000,0xf00000};
unsigned long _6[]={0x780000,0x800000,0x800000,0xf00000,0x880000,0x880000,0x700000};
unsigned long _7[]={0xf80000,0x080000,0x100000,0x200000,0x200000,0x200000,0x200000};
unsigned long _8[]={0x700000,0x880000,0x880000,0xf80000,0x880000,0x880000,0x700000};
unsigned long _9[]={0x700000,0x880000,0x880000,0x780000,0x080000,0x080000,0xf00000};
unsigned long _0[]={0x700000,0x880000,0x880000,0x880000,0x880000,0x880000,0x700000};
     hienthist(dulieu);
} 
}


