#include  "msp430fg4618.h"
#include  "LCD.c"
#include  "dht11.c"
#include  "BQ32000.c"
unsigned int tset;
unsigned int hset;

unsigned char Hourset= ;
unsigned char Minuteset= ;
unsigned char Secondset= ;
unsigned char Dateset= ;
unsigned char Monthset= ;
unsigned char Yearset= ;

unsigned char Hourset1= ;
unsigned char Minuteset1= ;
unsigned char Secondset1= ;
unsigned char Dateset1= ;
unsigned char Monthset1= ;
unsigned char Yearset1= ;

unsigned char Hourset2= ;
unsigned char Minuteset2= ;
unsigned char Secondset2= ;
unsigned char Dateset2= ;
unsigned char Monthset2= ;
unsigned char Yearset2= ;

unsigned char Hourset3= ;
unsigned char Minuteset3= ;
unsigned char Secondset3= ;
unsigned char Dateset3= ;
unsigned char Monthset3= ;
unsigned char Yearset3= ;

unsigned char Hourset4= ;
unsigned char Minuteset4= ;
unsigned char Secondset4= ;
unsigned char Dateset4= ;
unsigned char Monthset4= ;
unsigned char Yearset4= ;

void setting()
{
  
      date;
      month;
      year;
      hour;
      minute;
      second;
      writebq();
}

void hienthi()
{ 
  
       lcd_gotoxy(0,0);
       lcd_puts("D:");

       
       lcd_gotoxy(2,0);
       lcd_number(date/10,0,0);
       lcd_gotoxy(3,0);
       lcd_number(date%10,0,0);
       
       lcd_gotoxy(4,0);
       lcd_puts("/");
       
       lcd_gotoxy(5,0);
       lcd_number(month/10,0,0);
       lcd_gotoxy(6,0);
       lcd_number(month%10,0,0);
       
       lcd_gotoxy(7,0);
       lcd_puts("/");
       
       lcd_gotoxy(8,0);
       lcd_number(year/10,0,0);
       lcd_gotoxy(9,0);
       lcd_number(year%10,0,0);

       lcd_gotoxy(0,1);       // Hien thi:   hh:mm:ss
       lcd_puts("T:");

       
       lcd_gotoxy(2,1);
       lcd_number(hour/10,0,0);
       lcd_gotoxy(3,1);
       lcd_number(hour%10,0,0);
       
       lcd_gotoxy(4,1);
       lcd_puts(":");
       
       lcd_gotoxy(5,1);
       lcd_number(minute/10,0,0);
       lcd_gotoxy(6,1);
       lcd_number(minute%10,0,0);
       
       lcd_gotoxy(7,1);
       lcd_puts(":");
       
       lcd_gotoxy(8,1);
       lcd_number(second/10,0,0);
       lcd_gotoxy(9,1);
       lcd_number(second%10,0,0);
       
  
        
}

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  lcd_init();
  dht_init();
  clear();
  setting();
  PXDIR=0xff;
  while(1)
  {
    PXOUT&=~0xff;
    readbq();
    hienthi();
    hienthidht11();
    while((dht[1]>=hset||dht[3]>=tset))
	{
		PXOUT=0x02;
		readbq();
    		hienthi();
                hienthidht11();
	}
    if(date==Dateset && month==Monthset && year==Yearset && hour==Hourset && minute==Minuteset &&second==Secondset)
    {
      while(second!=timestop)
      {
      PXOUT=0x02;
      readbq();
      hienthi();
      hienthidht11();
      }
    }

     if(date==Dateset1 && month==Monthset1 && year==Yearset1 && hour==Hourset1 && minute==Minuteset1 &&second==Secondset1)
    {
      while(second!=timestop1)
      {
      PXOUT=0x02;
      readbq();
      hienthi();
      hienthidht11();
      }
    }

    if(date==Dateset2 && month==Monthset2 && year==Yearset2 && hour==Hourset2 && minute==Minuteset2 &&second==Secondset2)
    {
      while(second!=timestop2)
      {
      PXOUT=0x02;
      readbq();
      hienthi();
      hienthidht11();
      }
    }

    if(date==Dateset3 && month==Monthset3 && year==Yearset3 && hour==Hourset3 && minute==Minuteset3 &&second==Secondset3)
    {
      while(second!=timestop3)
      {
      PXOUT=0x02;
      readbq();
      hienthi();
      hienthidht11();
      }
    }

    if(date==Dateset4 && month==Monthset4 && year==Yearset4 && hour==Hourset4 && minute==Minuteset4 &&second==Secondset4)
    {
      while(second!=timestop4)
      {
      PXOUT=0x02;
      readbq();
      hienthi();
      hienthidht11();
      }
    }
    
  }
  
}
