//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    int currentLight = GREEN; // Set the initial light to green.
    int timeLeft = 10; // Set the initial time left to 10 seconds.

    while(1) { // Loop forever.
        printf("\n");
        switch(currentLight) {
            case RED: 
                printf("RED\n");
                printf("TIME REMAINING: %d\n", timeLeft);
                if(timeLeft == 0) { // If the light has been red for 10 seconds, change to green.
                    currentLight = GREEN;
                    timeLeft = 10;
                }
                break;
            case YELLOW:
                printf("YELLOW\n");
                printf("TIME REMAINING: %d\n", timeLeft);               
                if(timeLeft == 0) { // If the light has been yellow for 2 seconds, change to red.
                    currentLight = RED;
                    timeLeft = 10;
                }
                break;
            case GREEN:
                printf("GREEN\n");
                printf("TIME REMAINING: %d\n", timeLeft);
                if(timeLeft == 0) { // If the light has been green for 15 seconds, change to yellow.
                    currentLight = YELLOW;
                    timeLeft = 2;
                }
                break;
        }
        timeLeft--; // Decrement the time left by 1 second.
        sleep(1); // Sleep for 1 second before continuing the loop.
    }
    return 0;
}