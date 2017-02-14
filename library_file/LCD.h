//*******************dinh nghia bit************************
#ifndef _LCD_INIT_H
#define _LCD_INIT_H

typedef unsigned char uchar;
union reg
{    unsigned char _byte;            //khai bao 1byte
     struct bit 
       {                    //dinh nghia bit trong byte vua khai bao
       unsigned char b0:1; //bit 0 trong byte
       unsigned char b1:1; //bit 1 trong byte
       unsigned char b2:1; //bit 2 trong byte
       unsigned char b3:1; //bit 3 trong byte
       unsigned char b4:1; //bit 4 trong byte
       unsigned char b5:1; //bit 5 trong byte
       unsigned char b6:1; //bit 6 trong byte
       unsigned char b7:1; //bit 7 trong byte
       } _bit;
    
};  
union reg* P1_sel=(union reg*)0x26;
union reg* P1_dir=(union reg*)0x22;  //khai bao dia chi o nho
union reg* P1_out=(union reg*)0x21;
union reg* P1_int=(union reg*)0x20;

union reg* P2_dir=(union reg*)0x2a;  //khai bao dia chi o nho
union reg* P2_out=(union reg*)0x29;
//union reg* P2_sel=(union reg*)0x2e;
union reg* P2_int=(union reg*)0x28;

union reg* P3_dir=(union reg*)0x1a;  //khai bao dia chi o nho
union reg* P3_out=(union reg*)0x19;
union reg* P3_in=(union reg*)0x18;

union reg* P4_dir=(union reg*)0x1e;  //khai bao dia chi o nho
union reg* P4_out=(union reg*)0x1d;
union reg* P4_in=(union reg*)0x1c;

union reg* P5_dir=(union reg*)0x32;  //khai bao dia chi o nho
union reg* P5_out=(union reg*)0x31;
union reg* P5_in=(union reg*)0x30;

union reg* P6_dir=(union reg*)0x36;  //khai bao dia chi o nho
union reg* P6_out=(union reg*)0x35;
union reg* P6_in=(union reg*)0x34;

union reg* P7_dir=(union reg*)0x3c;  //khai bao dia chi o nho
union reg* P7_out=(union reg*)0x3a;
union reg* P7_int=(union reg*)0x38;

union reg* P8_dir=(union reg*)0x3d;  //khai bao dia chi o nho
union reg* P8_out=(union reg*)0x3b;
union reg* P8_in=(union reg*)0x39;

union reg* P9_dir=(union reg*)0x0c;  //khai bao dia chi o nho
union reg* P9_out=(union reg*)0x0a;
union reg* P9_in=(union reg*)0x08;

union reg* P10_dir=(union reg*)0x0d;  //khai bao dia chi o nho
union reg* P10_out=(union reg*)0x0b;
union reg* P10_in=(union reg*)0x09;
//**************************define Pin_LCD*******************



//********************delay************************
void delay(unsigned long int t);

//********************LCD Funtion***********************
//********************tao xung*******************************************
void enable();

//**********convert data-->send to Pin of microcontrol****************************
void set_data_lsb(uchar);  //ham gui byte data thap


void set_data_msb(uchar);  //ham gui byte data cao

//************************HAM GUI LENH******************************************
void put_cmd(uchar cmd);

//**************************ham gui data*************************************
void lcd_putc(char);


void lcd_puts(const char *);

//****************HTLCD************************************************

//****************************ham khoi tao lcd*************************
void lcd_init();

//************************************************
void clear();
//************************
void lcd_number (unsigned long, char, uchar);
//***************************************
void lcd_shift2r (const char*,const char*);
//**********************************************
void lcd_2line (const char*, const char*);
//**********************************************
void lcd_gotoxy(uchar, uchar);
//**********************************************
void lcd_rt(const char*,int);
//*********************************************
void lcd2so(unsigned char);

//*********************************************
void CustomCharacterStore();
//********************************************
void contro(uchar,uchar);
void xcontro();
#endif 