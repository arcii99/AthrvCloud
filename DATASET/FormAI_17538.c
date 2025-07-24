//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Initialize random seed
    int hour = rand() % 24, minute = rand() % 60, second = rand() % 60; //Generate random time
    int color = rand() % 3; //Generate random color

    printf("Current time: %02d:%02d:%02d\n", hour, minute, second); //Print current time

    switch(color) { //Choose traffic light color based on random number
        case 0:
            printf("Red light!\n");
            printf("STOP!\n");
            break;
        case 1:
            printf("Yellow light!\n");
            printf("Be ready!\n");
            break;
        case 2:
            printf("Green light!\n");
            printf("GO!\n");
            break;
        default:
            printf("Error: Invalid color.\n");
    }

    return 0;
}