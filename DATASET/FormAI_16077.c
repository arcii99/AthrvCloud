//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light states
enum traffic_light_states {
    RED,
    YELLOW,
    GREEN
};

int main() {
    srand(time(0)); // Initialize random seed

    int time_remaining = 0; // Initialize time remaining
    int current_state = GREEN; // Initialize current state to green

    int i;
    for(i = 1; i <= 100; i++) { // Loop 100 times
        printf("\nIteration %d:\n", i);

        if(time_remaining == 0) { // If time remaining is zero
            switch(current_state) {
                case RED:
                    printf("The light is now green.\n");
                    current_state = GREEN;
                    time_remaining = rand() % 6 + 5; // Random number from 5 to 10 seconds
                    break;
                case YELLOW:
                    printf("The light is now red.\n");
                    current_state = RED;
                    time_remaining = rand() % 2 + 3; // Random number from 3 to 4 seconds
                    break;
                case GREEN:
                    printf("The light is now yellow.\n");
                    current_state = YELLOW;
                    time_remaining = 2; // Two seconds for yellow light
                    break;
            }
        }

        printf("%d seconds remaining in %s light.\n", time_remaining, current_state == RED ? "red" : current_state == YELLOW ? "yellow" : "green");

        time_remaining--;
    }

    return 0;
}