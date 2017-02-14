#ifndef BQ32000_H_
#define BQ32000_H_

void delay_us(unsigned long t);
void I2C_Start(void);
void I2C_Stop(void);
unsigned char I2C_Write(unsigned char dat);
unsigned char I2C_Read(char ack);
void rtc_write(unsigned char add, unsigned char dat);
unsigned char rtc_read(unsigned char add);
void writebq(void);
void readbq(void);
void Calib_1Hz(void);


#endif
