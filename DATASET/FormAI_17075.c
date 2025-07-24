//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void greenLightOn() {
    printf("Green Light: ON\n");
}
void greenLightOff() {
    printf("Green Light: OFF\n");
}
void yellowLightOn() {
    printf("Yellow Light: ON\n");
}
void yellowLightOff() {
    printf("Yellow Light: OFF\n");
}
void redLightOn() {
    printf("Red Light: ON\n");
}
void redLightOff() {
    printf("Red Light: OFF\n");
}

int main() {
    int timer = 0; // timer for each light
    int cycle = 1; // cycle for the traffic light system
    srand(time(NULL)); // seed for random function
    while (cycle <= 3) { // simulating 3 cycles
        printf("-----------------------\n");
        printf("      Cycle: %d\n", cycle);
        printf("-----------------------\n");
        for (int i = 0; i < 3; i++) { // for 3 lights
            printf("\nLight: %d\n", i+1);
            switch (i) {
                case 0: // green light
                    greenLightOn();
                    yellowLightOff();
                    redLightOff();
                    timer = rand() % 6 + 5; // random timer between 5 and 10 seconds
                    break;
                case 1: // yellow light
                    greenLightOff();
                    yellowLightOn();
                    redLightOff();
                    timer = 3; // fixed timer for yellow light
                    break;
                case 2: // red light
                    greenLightOff();
                    yellowLightOff();
                    redLightOn();
                    timer = rand() % 6 + 5; // random timer between 5 and 10 seconds
                    break;
            }
            for (int j = timer; j > 0; j--) { // timer countdown
                printf("Time left: %d\n", j);
                sleep(1); // delay for 1 second
            }
            cycle++; // increment cycle
        }
    }
    return 0;
}