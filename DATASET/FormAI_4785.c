//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initializing variables
    int direction;
    srand(time(0)); // Seed for random number generation

    printf("Welcome! Initializing paranoid C Robot control program...\n\n");

    // Main control loop
    for (int i = 1; i <= 50; i++) {

        // Generating random direction
        direction = rand() % 4;

        // Switch case for direction
        switch (direction) {

            case 0:
                printf("Move Forward!\n");
                break;

            case 1:
                printf("Move Backward!\n");
                break;

            case 2:
                printf("Turn Left!\n");
                break;

            case 3:
                printf("Move Right!\n");
                break;
        } 

        // Generating random delay
        int delay = rand() % 4 + 1;

        // Pausing for random delay
        printf("Pausing for %d seconds...\n\n", delay);
        sleep(delay); // Delay execution by delay seconds
    }

    printf("Paranoid C Robot control program execution complete!\n");

    return 0;
}