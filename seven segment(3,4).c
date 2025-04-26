#include <reg51.h>

// Segment patterns for digits 0-9 (common anode: 0 = ON, 1 = OFF)
unsigned char segment_code[] = {
    0xC0, // 0 => 1100 0000
    0xF9, // 1 => 1111 1001
    0xA4, // 2 => 1010 0100
    0xB0, // 3 => 1011 0000
    0x99, // 4 => 1001 1001
    0x92, // 5 => 1001 0010
    0x82, // 6 => 1000 0010
    0xF8, // 7 => 1111 1000
    0x80, // 8 => 1000 0000
    0x90  // 9 => 1001 0000
};

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++); // 1ms delay (approx for 12MHz clock)
}

void main() {
    unsigned char i;
    while (1) {
        for (i = 0; i < 10; i++) {
            P1 = segment_code[i]; // Send pattern to Port 1
            delay_ms(500);        // Wait for 0.5 sec
        }
    }
}
