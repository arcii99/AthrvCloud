//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize variables
    int green = 0;
    int yellow = 0;
    int red = 0;
    int state = 0;
    int i = 0;
    srand(time(NULL)); //set seed for random number generator

    //run traffic light controller loop
    while (i < 10) {
        printf("State %d: ", i+1);
        switch (state) {
            case 0: //green light
                green = 1;
                yellow = 0;
                red = 0;
                printf("GREEN LIGHT\n");
                break;
            case 1: //yellow light
                green = 0;
                yellow = 1;
                red = 0;
                printf("YELLOW LIGHT\n");
                break;
            case 2: //red light
                green = 0;
                yellow = 0;
                red = 1;
                printf("RED LIGHT\n");
                break;
            default:
                printf("ERROR: Invalid state\n");
                exit(1);
        }

        state = (state + 1) % 3; //update state
        int time = rand() % 5 + 1; //generate random wait time
        printf("Waiting %d seconds...\n", time);
        sleep(time); //wait for random amount of time
        i++; //increment iteration count
    }

    return 0;
}