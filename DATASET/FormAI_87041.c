//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CYCLES 10
#define GREEN_LIGHT_TIME 30
#define YELLOW_LIGHT_TIME 5
#define RED_LIGHT_TIME 25

enum TrafficColor {
    GREEN,
    YELLOW,
    RED
};

int main() {
    srand(time(NULL)); // Seed the random number generator

    int cycleCount = 0;
    enum TrafficColor currentColor = GREEN;
    int remainingTime = GREEN_LIGHT_TIME;

    printf("Traffic light controller has started.\n");

    while(cycleCount < MAX_CYCLES) {
        printf("Cycle number: %d\n", cycleCount + 1);
        printf("Current color: ");

        // Print out the current color
        switch(currentColor) {
            case GREEN:
                printf("Green\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case RED:
                printf("Red\n");
                break;
        }

        // Decrement the remaining time and change the state if necessary
        remainingTime -= 1;
        if(remainingTime == 0) {
            switch(currentColor) {
                case GREEN:
                    currentColor = YELLOW;
                    remainingTime = YELLOW_LIGHT_TIME;
                    break;
                case YELLOW:
                    currentColor = RED;
                    remainingTime = RED_LIGHT_TIME;
                    break;
                case RED:
                    currentColor = GREEN;
                    remainingTime = GREEN_LIGHT_TIME;
                    break;
            }
        }

        // Print out the remaining time
        printf("Time left: %d\n\n", remainingTime);

        // Wait for a random amount of time
        int waitTime = rand() % 4 + 1; // Wait between 1-4 seconds
        sleep(waitTime);
        
        // Increment the cycle count
        cycleCount += 1;
    }

    printf("Traffic light controller has ended.\n");

    return 0;
}