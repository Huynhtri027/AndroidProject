
#include "MSP430.h"
#include "7seg.h"

void hienthi(unsigned char led0)
{  
  int donvi,chuc;
	donvi=led0%10;
  	chuc=led0/10;
    for(int i=0;i<100;i++)
  {
  P1OUT=donvi+16;
  __delay_cycles(1000);
  P1OUT=chuc;
  __delay_cycles(1000);
  }
    
}
void hienthidoset(unsigned char nhietdoset,unsigned char nhietdo)
{

int donvi,chuc;
	donvi=nhietdoset%10;
  	chuc=nhietdoset/10;
int donvi1,chuc1;
	donvi1=nhietdo%10;
  	chuc1=nhietdo/10;
    for(int i=0;i<200;i++)
  {
  P1OUT=donvi+48;
  __delay_cycles(1000);
  P1OUT=chuc+32;
  __delay_cycles(1000);

 P1OUT=donvi1+16;
  __delay_cycles(1000);
  P1OUT=chuc1;
  __delay_cycles(1000);

  }

}

void hienthirealtime(unsigned char ngay, unsigned char thang, unsigned char nam)
{
  int dvng,chng,dvt,cht,dvn,chn;
  chng=ngay/10; dvng=ngay%10; cht=thang/10;dvt=thang%10;chn=nam/10;dvn=nam%10;
  for(int i=0;i<72;i++)
  {
    P1OUT=chng;
    __delay_cycles(1000);
    P1OUT=dvng+16;
    __delay_cycles(1000);
    
    P1OUT=cht+32;
    __delay_cycles(1000);
    P1OUT=dvt+48;
    __delay_cycles(1000);
    
    P1OUT=chn+64;
    __delay_cycles(1000);
    P1OUT=dvn+80;
    __delay_cycles(1000);
  }
  
  
}

void demxuong(unsigned int dv,unsigned int c,unsigned int number)

{
  int num, donvi,chuc;
  for(num=number;num>=0;num--)
  {
  
  donvi=num%10;
  chuc=num/10;
  for(int i=0;i<30;i++)
  {
  P1OUT=donvi+dv;
  __delay_cycles(10000);
  P1OUT=chuc+c;
  __delay_cycles(10000);
  }
  
  }
}

void demlen(unsigned int dv,unsigned int c,unsigned int number)

{
  int num, donvi,chuc;
  for(num=0;num<=number;num++)
  {
  
  donvi=num%10;
  chuc=num/10;
  for(int i=0;i<30;i++)
  {
  P1OUT=donvi+dv;
  __delay_cycles(10000);
  P1OUT=chuc+c;
  __delay_cycles(10000);
  }
  
  }
}
void demlen1(unsigned char so)
{
  unsigned int num,chuc,donvi;
  
  for(num=0;num<=so;num++)
  {
  donvi=num%10;
  chuc=num/10;
  for(int i=0;i<30;i++)
  {
   P1OUT=donvi+16;
   __delay_cycles(5000);
   P1OUT=chuc;
   __delay_cycles(5000);
  }
  __delay_cycles(1000);
  }
}

void demxuong1(unsigned char so)
{
  unsigned int num,chuc,donvi;
  
  for(num=so;num>0;num--)
  {
  donvi=num%10;
  chuc=num/10;
  for(int i=0;i<30;i++)
  {
   P1OUT=donvi+16;
   __delay_cycles(5000);
   P1OUT=chuc;
   __delay_cycles(5000);
  }
  __delay_cycles(1000);
  }
}
