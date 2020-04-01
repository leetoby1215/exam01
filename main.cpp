#include "mbed.h"
#include "uLCD_4DGL.h"
#define freq 1000

Serial pc(USBTX, USBRX);
AnalogOut Aout(D7);
//uLCD_4DGL uLCD(D1, D0, D2);

int main() {
    while (1) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 100; j++) {
                Aout = 0;
                wait_us((10 - i) * 100);
                Aout = 0.5;
                wait_us(i * 100);
            }
        }
    }
    uLCD.printf("107061144\n");
    for (int y = 20; y < 40; y++) {
        uLCD.line(20, y, 40, y, WHITE);
    }
}