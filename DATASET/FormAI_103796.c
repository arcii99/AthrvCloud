//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Seed the random number generator with the current time
    
    int green = 30 + rand() % 31; //Random time between 30-60 seconds for green light
    int yellow = 3; //Always 3 seconds for yellow light
    int red = 60 - green; //Calculate remaining time for red light
    
    while (1) { //Loop indefinitely
        printf("Green Light for %d seconds\n", green);
        for (int i = green; i > 0; i--) { //Count down for green light
            printf("%d\n", i);
            sleep(1);
        }
        printf("Yellow Light for %d seconds\n", yellow); //Yellow light for 3 seconds
        sleep(yellow);
        printf("Red Light for %d seconds\n", red);
        for (int i = red; i > 0; i--) { //Count down for red light
            printf("%d\n", i);
            sleep(1);
        }
        printf("\n");
        green = 30 + rand() % 31; //Random time for next green light
        red = 60 - green; //Calculate new red light time
    }
    return 0;
}