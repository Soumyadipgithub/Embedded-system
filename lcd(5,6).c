#include <reg51.h> 
#define dataport P2 
sbit rs = P3^0;  // Register Select 
sbit rw = P3^1;  // Read/Write 
sbit e  = P3^6;  // Enable 

void delay(unsigned int msec) { 
    while (msec--) { 
        for (int j = 0; j < 1275; j++); 
    } 
} 

void Lcd_cmd(unsigned char cmd) { 
    dataport = cmd; rs = 0; rw = 0; e = 1; delay(1); e = 0; 
} 

void Lcd_data(unsigned char data) { 
    dataport = data; rs = 1; rw = 0; e = 1; delay(1); e = 0; 
} 

void Lcd_init() { 
    Lcd_cmd(0x38); Lcd_cmd(0x0E); Lcd_cmd(0x01); Lcd_cmd(0x06); Lcd_cmd(0x80); 
    delay(1); 
} 

void main() { 
    unsigned char msg[] = "HELLO 8051"; 
    Lcd_init(); 
    for (int i = 0; msg[i]; i++) { 
        Lcd_data(msg[i]); 
        delay(200); 
    } 
    while (1); 
}