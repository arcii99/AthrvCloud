//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: recursive
#include <stdio.h>
#include <unistd.h>

void redLight(int timer);
void greenLight(int timer);
void yellowLight(int timer);

int main(void) {
    int count = 0;
    while(count <= 5) {
        printf("Round: %d\n", count);
        redLight(10);
        yellowLight(5);
        greenLight(12);
        count++;
    }
    return 0;
}

void redLight(int timer) {
    printf("Red Light\n");
    sleep(timer);
    yellowLight(5);
}

void greenLight(int timer) {
    printf("Green Light\n");
    sleep(timer);
    yellowLight(3);
}

void yellowLight(int timer) {
    if(timer == 5) {
        printf("Yellow Light for Red Light\n");
        sleep(timer);
        greenLight(12);
    } else {
        printf("Yellow Light for Green Light\n");
        sleep(timer);
        redLight(10);
    }
}