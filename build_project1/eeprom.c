#include "eeprom.h"
//typedef unsigned char uchar;
#define SCL     P2_out->_bit.b0
#define SDAIN   P2_in->_bit.b1
#define SDAOUT  P2_out->_bit.b1
#define SCL1    P2_dir->_bit.b0
#define SDA1    P2_dir->_bit.b1


void delay_us(unsigned long t)
{
	int i;
	for (i = 0; i<t; i++ )
        {}
}
void I2C_Start(void)
{
   
      /*SCL1 = 1;
      SDA1 = 1;
      SCL = 1;
      SCL = 0;
      SDAOUT = 1;  
      SCL = 1; 
      delay_us(3); //  SDA tu cao xuong thap trong khi SDL cao Start I2C
      SDAOUT = 0; 
      delay_us(3);
      SCL = 0;     // SDL thap nhan du lieu 
      delay_us(3);*/
      
  
      SCL1 = 1;
      SDA1 = 1;
      SCL = 0;
      SDAOUT = 1;
      SCL = 1;
      delay_us(3);
      SDAOUT = 0;
      delay_us(3);
      SCL = 0; 
      //delay_us(3); 
      
       
}
//-----------------------------------------------------------------------------
void I2C_Stop(void)
{
      SCL1 = 1;
      SDA1 = 1;
      SCL = 0;
      SDAOUT = 0;
      SCL = 1;
      delay_us(3);
      SDAOUT = 1;
      delay_us(3);
      
      //SCL = 0; 
      //delay_us(3); 
     
     
}

//unsigned char I2C_Write(unsigned char dat) 
void I2C_Write(unsigned char data) // hao viet
{
   

   /*SCL1=1;
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
   return dat; */
   SCL1=1;
   SDA1=1;
   unsigned char a;
   for(int i=0;i<8;i++)
   {
     a=data&0x80;
     if(a==0x80)
       SDAOUT=1;
     else
       SDAOUT=0;
     SCL=1;
     SCL=0;
     delay_us(3);
     data<<=1;
   }
   SDAOUT=0;
   SCL = 1;
   SCL = 0;
   delay_us(3);
   
}

unsigned char I2C_Read(char ack)
{
   

   /*SCL1=1;
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
   return dat;*/
   SCL1=1;
   SDA1=0;
   char rd_bit;
   unsigned char data=0x00;
   for(int i=0;i<8;i++)
   {
         
         rd_bit = SDAIN;
         data=data<<1;
         data=data|rd_bit;
         SCL = 1;
         SCL =0;
         delay_us(3); 
        
        
   }
   if(ack==0)
   {
    SCL = 1;
    delay_us(3);
    SCL = 0;
   }
   if(ack==1)
   {
     SDA1=1;
     SDAOUT = 1;
     SCL = 1;
     SCL = 0;
     delay_us(2); 
   }
   return data;
  
  
}

unsigned char I2C_ReadByteCurrent(unsigned int add)
{
  unsigned char dataread;
  I2C_Start();
  I2C_Write(0xa0);
  I2C_Write(add);
  I2C_Start();
  I2C_Write(0xa1);
  dataread = I2C_Read(1);
  I2C_Stop();
  return dataread;
}



void EEPROM_bytewrite(unsigned int addr, unsigned char val)
{
 I2C_Start(); 

 I2C_Write(0xa0); // Connect to EEPROM 
 //delay_us(4);
 I2C_Write(addr); // Request RAM address (Hight byte) 
 //delay_us(4);
 I2C_Write(val); // Write sec on RAM specified address 
 //delay_us(4);
 I2C_Stop(); // Stop i2c bus 
 
}

void EEPROM_pagewrite(unsigned int addr, unsigned char val,unsigned char val1,unsigned char val2)
{
  
 I2C_Start(); 
 I2C_Write(0xa0); // Connect to EEPROM 
 //delay_us(4);
 I2C_Write(addr); // Request RAM address (Hight byte) 
 //delay_us(4);
 I2C_Write(val); // Write sec on RAM specified address 
 //delay_us(4);
 I2C_Write(val1);
 // delay_us(4);
 I2C_Write(val2);
 //delay_us(4);
 I2C_Stop(); // Stop i2c bus 
}
 

void EEPROM_Pagewrite(unsigned int addr, unsigned char val,unsigned char number)
{
  
 I2C_Start(); 
 I2C_Write(0xa0); // Connect to EEPROM 
 //delay_us(4);
 I2C_Write(addr); // Request RAM address (Hight byte) 
 for(int i=addr;i<=number;i++)
 {
 I2C_Write(val); // Write sec on RAM specified address 
 }
 I2C_Stop(); // Stop i2c bus 
}