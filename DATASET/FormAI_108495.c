//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main() {
    int redLight = 0;
    int yellowLight = 0;
    int greenLight = 1;

    printf("Welcome to the wackiest Traffic Light Controller ever!\n");

    while (1) {
        int time = (rand() % 10) + 1; // random time from 1-10 seconds
        printf("\nGreen light for %d seconds\n", time);
        greenLight = 1;
        yellowLight = 0;
        redLight = 0;
        sleep(time);

        time = (rand() % 10) + 1; // random time from 1-10 seconds
        printf("\nYellow light for %d seconds\n", time);
        greenLight = 0;
        yellowLight = 1;
        redLight = 0;
        sleep(time);

        time = (rand() % 10) + 1; // random time from 1-10 seconds
        printf("\nRed light for %d seconds\n", time);
        greenLight = 0;
        yellowLight = 0;
        redLight = 1;
        sleep(time);

        printf("\nThe lights are malfunctioning! Every light is blinking!\n");
        greenLight = 1;
        yellowLight = 1;
        redLight = 1;
        sleep(5);
    }

    return 0;
}