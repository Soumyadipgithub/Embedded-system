#include <reg51.h>

#define LCD P2
sbit RS = P3^0; sbit RW = P3^1; sbit EN = P3^2;
sbit R1 = P1^0; sbit R2 = P1^1; sbit R3 = P1^2; sbit R4 = P1^3;
sbit C1 = P1^4; sbit C2 = P1^5; sbit C3 = P1^6;

void delay_ms(unsigned int ms) { while(ms--) for(int i = 0; i < 1275; i++); }
void lcd_cmd(unsigned char cmd) { LCD = cmd; RS = 0; RW = 0; EN = 1; delay_ms(2); EN = 0; }
void lcd_data(unsigned char dat) { LCD = dat; RS = 1; RW = 0; EN = 1; delay_ms(2); EN = 0; }
void lcd_init() { lcd_cmd(0x38); lcd_cmd(0x0C); lcd_cmd(0x06); lcd_cmd(0x01); lcd_cmd(0x80); }
void lcd_print(char *str) { while(*str) lcd_data(*str++); }

char read_keypad() {
    R1 = R2 = R3 = R4 = 1; C1 = C2 = C3 = 1;
    if (R1 == 0) { if (C1 == 0) return '1'; if (C2 == 0) return '2'; if (C3 == 0) return '3'; }
    if (R2 == 0) { if (C1 == 0) return '4'; if (C2 == 0) return '5'; if (C3 == 0) return '6'; }
    if (R3 == 0) { if (C1 == 0) return '7'; if (C2 == 0) return '8'; if (C3 == 0) return '9'; }
    if (R4 == 0) { if (C1 == 0) return '*'; if (C2 == 0) return '0'; if (C3 == 0) return '#'; }
    return 0;
}

void main() {
    lcd_init();
    while(1) {
        char key = read_keypad();
        delay_ms(300); // Debounce delay
        lcd_cmd(0x01); // Clear LCD
        lcd_cmd(0x80); // Set cursor to beginning
        lcd_print("SOUMYADIP");
        while(read_keypad()); // Wait until key is released
    }
}
