#include "mbed.h"
#include "uLCD_4DGL.h"
#define sample 128

Serial pc(USBTX, USBRX);
AnalogOut Aout(DAC0_OUT);
//uLCD_4DGL uLCD(D1, D0, D2);
InterruptIn btn(SW3);
EventQueue queue1(32 * EVENTS_EVENT_SIZE);

float output[sample];
float output_tmp;

void pc_print() {
    for (int i = 0; i < sample; i++) {
        output[i] = output_tmp;
        wait(1.0/128.0);
    }
    for (int i = 0; i < sample; i++) {
        pc.printf("%1.3f\r\n", output[i]);
    }
}

void btn_fall() {
    queue1.call(&pc_print);
}

int main() {
    Thread thread1(osPriorityNormal);
    thread1.start(callback(&queue1, &EventQueue::dispatch_forever));
    btn.fall(&btn_fall);

    /*uLCD.printf("107061144\n");
    for (int y = 32; y < 96; y++) {
        uLCD.line(32, y , 96, y, WHITE);
    }*/

    while (true) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 100; j++) {
                Aout = 0;
                output_tmp = 0;
                wait_us((10 - i) * 100);
                Aout = 1;
                output_tmp = 1;
                wait_us(i * 100);
            }
        }
    }
}