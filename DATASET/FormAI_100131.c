//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: accurate
#include<stdio.h>

void redLight() {
    printf("RED light is ON\n");
}

void yellowLight() {
    printf("YELLOW light is ON\n");
}

void greenLight() {
    printf("GREEN light is ON\n");
}

int main() {
    int time = 0;

    while (time < 30) {
        if (time % 10 == 0) { //switch lights every 10 seconds            
            printf("Time: %d seconds\n", time);
            redLight();
            sleep(2);
            yellowLight();
            sleep(1);
            greenLight();
            sleep(3);
        }
        time++;
    }

    return 0;
}