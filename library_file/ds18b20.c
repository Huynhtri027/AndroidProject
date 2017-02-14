#include "msp430fg4618.h"
#include "ds18b20.h"
//typedef unsigned char uchar; // co lcd thi bo hang nay
typedef unsigned int  uint;

#define DQ1 P7OUT |= BIT2
#define DQ0 P7OUT &= ~BIT2

/*******************************************

********************************************/
uchar Init_18B20(void)
{
    uchar Error;

    _DINT();
    DQ0;
    __delay_cycles(500);
    DQ1;
    __delay_cycles(55);
    P7DIR &=~ BIT2;
    _NOP();
    if(P7IN & BIT2)
    {
        Error = 1;
        P7DIR |= BIT2;
    }
    else
    {
        Error = 0;
        P7DIR |= BIT2;
        DQ1;
    }
    _EINT();

    __delay_cycles(400);

    return Error;
}
/*******************************************

********************************************/
void Write_18B20(uchar wdata)
{
    uchar i;

    _DINT();
    for(i = 0; i < 8;i++)
    {
        DQ0;
        __delay_cycles(6);
        if(wdata & 0X01)    DQ1;
        else                DQ0;
        wdata >>= 1;
        __delay_cycles(50);
        DQ1;
        __delay_cycles(10);
    }
    _EINT();
}
/*******************************************

********************************************/
uchar Read_18B20(void)
{
    uchar i;
    uchar temp = 0;

    _DINT();
    for(i = 0;i < 8;i++)
    {
        temp >>= 1;
        DQ0;
        __delay_cycles(6);
        DQ1;
        __delay_cycles(8);
        P7DIR &= ~BIT2;
        _NOP();
        if(P7IN & BIT2)   temp |= 0x80;
        __delay_cycles(45);
        P7DIR |= BIT2;
        DQ1;
        __delay_cycles(10);
    }
    _EINT();

    return  temp;
}

/*******************************************

********************************************/
void Skip(void)
{
    Write_18B20(0xcc);
}
/*******************************************
chuyen doi
********************************************/
void Convert(void)
{
    Write_18B20(0x44);
}
/*******************************************

********************************************/
void Read_SP(void)
{
    Write_18B20(0xbe);
}
/*******************************************
ham doc gia tri nhiet do
********************************************/
uint ReadTemp(void)
{
    uchar temp_low;
    uint  temp;

    temp_low = Read_18B20();
    temp = Read_18B20();
    temp = (temp<<8) | temp_low;

    return  temp;
}
/*******************************************
ham lay gia trij nhiet do da chuyen doi
********************************************/
uint Do1Convert(void)
{
    uchar i;

    do
    {
        i = Init_18B20();
    }
    while(i);
    Skip();
    Convert();
    for(i = 20;i > 0;i--)
        __delay_cycles(1000);
    do
    {
        i = Init_18B20();
    }
    while(i);
    Skip();
    Read_SP();
    return ReadTemp();
}
