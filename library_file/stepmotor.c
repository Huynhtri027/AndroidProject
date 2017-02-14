#include "stepmotor.h"
unsigned char Wave[]={0x01,0x02,0x04,0x08};
unsigned char Full[]={0x03,0x06,0x0c,0x09};
unsigned char Half[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
unsigned char t;
void quay_vong(unsigned char num)
{
  for(int i=0;i<num;i++)
  {
  for(int j=0;j<48;j++)
  {
    if(t==4)
      t=0;
    P1OUT=Wave[t];
    __delay_cycles(500000);
    t++;
  }
}
P1OUT=0X00;
}
void quay_buoc(unsigned char num)
{
  unsigned char i,j=0; 
  
  for(i=num;i>0;i--)
  {
    if(j==4)
      j=0;
    P1OUT=Wave[j];
    __delay_cycles(500000);
    j++;
  }
  
}
void wave()
{
  for(int i=0;i<4;i++)
  {
    P1OUT=Wave[i];
    __delay_cycles(500000);
  }
}
void full()
{
  for(int i=0;i<4;i++)
  {
    P1OUT=Full[i];
    __delay_cycles(500000);
  }
}
void half()
{
  for(int i=0;i<8;i++)
  {
    P1OUT=Half[i];
    __delay_cycles(500000);
  }
}

