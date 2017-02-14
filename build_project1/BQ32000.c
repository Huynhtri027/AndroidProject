#include "LCD.h"
#include "BQ32000.h"

#define SCL     P1_out->_bit.b0
#define SDAIN   P1_int->_bit.b1
#define SDAOUT  P1_out->_bit.b1
#define SCL1    P1_dir->_bit.b0
#define SDA1    P1_dir->_bit.b1

unsigned char second=0, minute=0, hour=0, date=0, month=0, year=14; 
unsigned char a=0, number=0, ok=0;
char set0=1, set1=1, up0=1, up1=1, down0=1, down1=1;
void delay_us(unsigned long t)
{
	int i;
	for (i = 0; i<t; i++ )
        {}
}
void I2C_Start(void)
{
      SCL1 = 1;
      SDA1 = 1;
      SCL = 1; 
      SCL = 0;
      SDAOUT = 1; 
      SCL = 1;
      delay_us(3); //  SDA tu cao xuong thap trong khi SDL cao Start I2C
      SDAOUT = 0;
      delay_us(3);
      SCL = 0;     // SDL thap nhan du lieu 
      delay_us(3);
}
//-----------------------------------------------------------------------------
void I2C_Stop(void)
{
     SCL1=1;
     SDA1=1;
     SCL=1; 
     SCL=0;
     SDAOUT=0;    //  SDA tu thap len cao trong khi SDL cao Stop I2C
     delay_us(3); 
     SCL=1;         
     delay_us(3);
     SDAOUT = 1;
}
//-----------------------------------------------------------------------------
unsigned char I2C_Write(unsigned char dat)
{
   SCL1=1;
   SDA1=1;
   unsigned char i;
   for (i=0;i<8;i++)
      {
         SDAOUT= (dat & 0x80)? 1:0;
         SCL=1;SCL=0;
         dat<<=1;
      }
   SCL = 1;
   delay_us(3);
   SCL = 0;
   return dat;
}
//-----------------------------------------------------------------------------
unsigned char I2C_Read(char ack)
{
   SCL1=1;
   SDA1=0;
   char rd_bit;
   unsigned char i, dat;
   dat = 0x00;
   for(i=0;i<8;i++)       
      {
         delay_us(3);
         SCL = 1; 
         delay_us(3);    
         rd_bit = SDAIN; 
         dat = dat<<1;
         dat = dat | rd_bit; 
         SCL = 0;          
      }
    if (ack) 
      SDAOUT = 0; 
    else 
      SDAOUT = 1;
    SCL = 1;
    delay_us(3);
    SCL = 0;
    SDAOUT = 1; 
    delay_us(3);
   return dat;
}
//-----------------------------------------------------------------------------
void rtc_write(unsigned char add, unsigned char dat)
{
  unsigned int temp;
  I2C_Start();
  I2C_Write(0xd0);
  I2C_Write(add); 
  temp = dat;
  I2C_Write(((dat/10)<<4)|(temp%10)); 
  I2C_Stop();
}
//-----------------------------------------------------------------------------
unsigned char rtc_read(unsigned char add)
{
   unsigned int dat;
   unsigned int temp;
   I2C_Start();
   I2C_Write(0xd0); 
   I2C_Write(add);
   I2C_Start(); 
   I2C_Write(0xd1); 
   dat = I2C_Read(0);
   I2C_Stop();
   temp = dat;
   dat = (temp & 0x0f) + ((dat>>4)*10);
   return (dat);
}
//-----------------------------------------------------------------------------
void writebq(void)
{
  rtc_write(0x00, second);
  rtc_write(0x01, minute);
  rtc_write(0x02, hour);
  rtc_write(0x04, date);
  rtc_write(0x05, month);
  rtc_write(0x06, year);
}
//-----------------------------------------------------------------------------
void readbq(void)
{
   if(number==0)
      {
         if(a==1)
            {
               writebq();
               a=0;
            }
         second = rtc_read(0x00);
         minute = rtc_read(0x01);
         hour = rtc_read(0x02);
         date = rtc_read(0x04);
         month = rtc_read(0x05);
         year = rtc_read(0x06);
      }
}
//-----------------------------------------------------------------------------
void Calib_1Hz(void)
{
   rtc_write(0x07,0x40);
   rtc_write(0x20,0x5e);
   rtc_write(0x21,0xc7);
   rtc_write(0x22,0x01);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------



