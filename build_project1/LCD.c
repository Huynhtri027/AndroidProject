#include "LCD.h"
#include "string.h"
 
#define RS     P2_out->_bit.b0    
#define EN     P2_out->_bit.b1   

#define DATA_4 P2_out->_bit.b2
#define DATA_5 P2_out->_bit.b3
#define DATA_6 P2_out->_bit.b4
#define DATA_7 P2_out->_bit.b5

void lcd_init()
{
P2_dir->_bit.b0 =1; //
P2_dir->_bit.b1 =1;
P2_dir->_bit.b2 =1;  
P2_dir->_bit.b3	=1;
P2_dir->_bit.b4	=1;
P2_dir->_bit.b5	=1;

  delay(100);
  RS=0;              // che do gui lenh
  set_data_lsb(0x03);
  enable();
  enable();
  enable();
  set_data_lsb(0x02);
  enable();
    put_cmd (0x28);    //cd 4bit,2dong,5x7
    put_cmd (0x0C);     //bat hien thi,tat con tro
    put_cmd (0x06);    //* entry mode set, increment & scroll left
    clear();
}


//********************delay************************
void delay(unsigned long int t)
{
  unsigned long int i=0;
  for(i=0;i<t;i++)
  	__delay_cycles(1000);
}
//********************LCD Funtion***********************
//********************tao xung*******************************************
void enable()
{
 EN=1;
 __delay_cycles(10);
 EN=0;
 __delay_cycles(10);
}
//**********convert data-->send to Pin of microcontrol****************************
void set_data_lsb(uchar data)  //ham gui byte data thap
{
  unsigned char convert=0;

  convert=data&0x01;
  if(convert==0x01)DATA_4=1;
     else DATA_4=0;
  convert=data&0x02;
  if(convert==0x02)DATA_5=1;
     else DATA_5=0;
  convert=data&0x04;
  if(convert==0x04)DATA_6=1;
     else DATA_6=0;
  convert=data&0x08;
  if(convert==0x08)DATA_7=1;
     else DATA_7=0;
}

void set_data_msb(uchar data)  //ham gui byte data cao
{
  unsigned char convert=0;

  convert=data&0x10;
  if(convert==0x10)DATA_4=1;
     else DATA_4=0;
  convert=data&0x20;
  if(convert==0x20)DATA_5=1;
     else DATA_5=0;
  convert=data&0x40;
  if(convert==0x40)DATA_6=1;
     else DATA_6=0;
  convert=data&0x80;
  if(convert==0x80)DATA_7=1;
     else DATA_7=0;
}

//************************HAM GUI LENH******************************************
void put_cmd(uchar cmd)
{
  RS=0;  //chon thanh ghi lenh
  set_data_msb(cmd);
  enable();
  set_data_lsb(cmd);
  enable();
  
}
//**************************************
void clear()
{
	put_cmd(0x01);
	delay(2);
}
//**************************ham gui data*************************************

void lcd_putc(char c)
{
    switch(c)
    {
        case '\f':
            clear();
            break;
        case '\n':
            lcd_gotoxy(0,1);
            break;
        default:
            RS=1;
  	    set_data_msb(c);
  	    enable();
  	    set_data_lsb(c);
 	    enable();
            break;
    }
}

void lcd_puts(const char* s)
{
    while(*s){
        lcd_putc(*s++);
    }
}

//****************HTLCD************************************************

//****************************ham khoi tao lcd*************************

//***************************************
void lcd_gotoxy(uchar col,uchar row)
{
    unsigned char address;

    if(row!=0)
        address=0x40;
    else
        address=0;

    address += col;
    put_cmd(0x80|address);
    delay(2);     // wait for LCD
}
//************************************************

  void lcd_2line (const char* s1 , const char* s2)
{
    clear();
    lcd_puts (s1);
    lcd_gotoxy (0,1);
    lcd_puts (s2);
}
//************************************************
void lcd_number (unsigned long val, char dec, uchar neg)
{
    char i, j, digit,k;
    long total;
    long temp;
    for (i = 0, total = val; total > 0;i++) // count number
        total /= 10;
        total = i;
    
    if (neg !=0 )
      lcd_putc ('-');
    
    if ((total - dec) <=0)	// if total < dec put 0.xxx
        lcd_putc('0');
    else
    {      
    
      for (i=0; i< (total-dec); i++)
      {
        temp = 1;
        for (j=1;j<(total-i);j++)
            temp *=10;
        digit = (val/temp)%10;
        lcd_putc(digit + 0x30);
      }
    }
    if (dec > 0)
    {
      lcd_putc('.');
      if ( (dec - total)> 0)	// ex: val = 55; dec = 3 put 0.055
      {
        for ( i = 0; i < (dec-total);i++)
          lcd_putc('0');
        k = 0;
      }
      else
        k = total - dec;
      for (i=k; i< total; i++)
      {
       temp = 1;
       for (j=1;j<(total-i);j++)
           temp *=10;
       digit = (val/temp)%10;
       lcd_putc(digit + 0x30);
      }
    }    
}
//************************************************
void lcd_shift2r (const char* s1,const char* s2)
{
	lcd_2line (s1,s2);
	delay(500);
	for(int i=0;i<15;i++)
		{
		put_cmd(0x1C);
		delay(500);
		}
}
//************************************************
void lcd_rt(const char *s, int line)
{
  int i,len=strlen(s);
    lcd_gotoxy(16,line); 
    for (i=0;i<15+len;i++)
    {
      if(i<len)
      lcd_putc(s[i]);
      put_cmd(0x18);
      if(i==25)
        lcd_gotoxy(16,line); 
      delay(300);
    } 
    clear();
}
//************************************************
void lcd2so(unsigned char x)
{
  lcd_putc((x/10)+48);
  lcd_putc((x%10)+48);
}
//************************************************
void CustomCharacterStore()
{
unsigned char CharacterArray[2][8] = {{6,9,9,6,0,0,0,0},
                                      {0,14,21,23,17,14,0,0}};
 

unsigned char i=0,j=0;
        //send_cmd(0x48);       //Load the location where we want to store
        //delayms(1);               // Delay of 1millisec
 
        /**Store the custom character patterns in CGRAM area**/
                                                  
        while(j<=2) //edit
        {
            put_cmd(0x40 + (j*8));
            delay(2);
                for(i=0;i<=7;i++)
                {
                    lcd_putc(CharacterArray[j][i]);
                    delay(2);
                }
                j++;
        }
}
//************************************************
void contro(uchar ccol,uchar crow)
{
  lcd_gotoxy(ccol,crow);
  put_cmd(0x0f);
  delay(2);
}

void xcontro()
{
  put_cmd(0x0c);
  delay(2);
}