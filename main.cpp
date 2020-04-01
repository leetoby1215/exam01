#include "mbed.h"
#include "uLCD_4DGL.h"
#define freq 1000

Serial pc(USBTX, USBRX);
AnalogOut Aout(DAC0_OUT);
uLCD_4DGL uLCD(D1, D0, D2);

int main() {
    uLCD.printf("107061144\n");
    for (int y = 20; y < 40; y++) {
        uLCD.line(20, y, 40, y, WHITE);
    }
    while (true) {
        /*for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 100; j++) {
                Aout = 0;
                wait_us((10 - i) * 100);
                Aout = 0.5;
                wait_us(i * 100);
            }
        }*/
            for(float i=0; i<2; i+=0.05 ){
                Aout = 0.5 + 0.5*sin(i*3.14159);
                wait(0.001);
            }
    }
}