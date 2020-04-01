#include "mbed.h"
#include "uLCD_4DGL.h"

AnalogOut Aout(DAC0_OUT);
uLCD_4DGL uLCD(D1, D0, D2);

int main() {
    while (1) {

        for(float i=0; i<2; i+=0.05 ){
            Aout = 0.5 + 0.5*sin(i*3.14159);
            wait(0.001);
        }
    }
}