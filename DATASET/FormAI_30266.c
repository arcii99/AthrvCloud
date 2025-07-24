//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
    srand(time(NULL)); // seed for random number generation
    int state = RED; // initial state is red

    while (true) { // infinite loop to simulate traffic flow
        
        // Switch statement to handle traffic light changes
        switch (state) {
            case RED:
                printf("Traffic light is red.\n");
                printf("Waiting...\n");
                sleep(5); // wait for 5 seconds before changing
                state = GREEN;
                break;
            case YELLOW:
                printf("Traffic light is yellow.\n");
                printf("Prepare to stop...\n");
                sleep(2); // wait for 2 seconds before changing
                state = RED;
                break;
            case GREEN:
                printf("Traffic light is green.\n");
                printf("Proceed with caution...\n");
                sleep(10); // wait for 10 seconds before changing
                int random = rand() % 100; // generate random number between 0 and 99
                if (random < 20) { // 20% chance for yellow light
                    state = YELLOW;
                } else {
                    state = RED;
                }
                break;
        }
    }
    return 0;
}