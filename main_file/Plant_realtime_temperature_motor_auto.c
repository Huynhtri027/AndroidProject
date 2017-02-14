
#include  "msp430fg4618.h"
#include  "LCD.c"
#include  "dht11.c"
#include  "BQ32000.c"
unsigned int tset;
unsigned int hset;




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
    
  }
  
}
