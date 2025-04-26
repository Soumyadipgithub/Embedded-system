#include <reg51.h>

void delay(int time) {
    int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++) {
        }
    }
}

void main() {
    int rot_angle[] = {0x08, 0x04, 0x02, 0x01};
    int i;
    while (1) {
        for (i = 0; i < 4; i++) {
            P1 = rot_angle[i];
            delay(100);
        }
    }
}
