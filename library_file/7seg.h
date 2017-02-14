#ifndef led7doan_H_
#define led7doan_H_
void hienthi(unsigned char led0);
void hienthidoset(unsigned char led1,unsigned char led2);
void demxuong(unsigned int dv,unsigned int c,unsigned int number);
void demlen(unsigned int dv,unsigned int c,unsigned int number);
void hienthirealtime(unsigned char ngay, unsigned char thang, unsigned char nam);

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

union reg* P7_dir=(union reg*)0x3c;  //khai bao dia chi o nho
union reg* P7_out=(union reg*)0x3a;
union reg* P7_int=(union reg*)0x38;



#endif