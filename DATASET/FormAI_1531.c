//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); //seed random number generator with current time
    int greenTime = rand() % 6 + 10; //randomly generate a green light time between 10-15 seconds
    int yellowTime = rand() % 3 + 3; //randomly generate a yellow light time between 3-5 seconds
    int redTime = 20 - (greenTime + yellowTime); //calculate the red light time based on the green and yellow light times

    printf("Welcome to the unique traffic light controller!\n");
    printf("Today's green light will last for %d seconds.\n", greenTime);
    printf("The yellow light will be on for %d seconds.\n", yellowTime);
    printf("And the red light will last for %d seconds.\n", redTime);

    while (1) { //infinite loop

        printf("Green light! Go!\n");
        for (int i = 0; i < greenTime; i++) { //count down the green light time
            printf("%d...\n", greenTime - i);
            sleep(1); //wait one second
        }

        printf("Yellow light! Slow down!\n");
        for (int i = 0; i < yellowTime; i++) { //count down the yellow light time
            printf("%d...\n", yellowTime - i);
            sleep(1); //wait one second
        }

        printf("Red light! Stop!\n");
        for (int i = 0; i < redTime; i++) { //count down the red light time
            printf("%d...\n", redTime - i);
            sleep(1); //wait one second
        }

        printf("Switching lights...\n\n");
        greenTime = rand() % 6 + 10; //generate new times for the next cycle
        yellowTime = rand() % 3 + 3;
        redTime = 20 - (greenTime + yellowTime);
    }
    return 0;
}