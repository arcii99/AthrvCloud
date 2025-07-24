//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_LANES 3
#define ROAD_LENGTH 10
#define PERCENTAGE_OF_CARS 60

int main() {
    srand(time(NULL)); // Initialize random seed

    int lane[NUM_OF_LANES][ROAD_LENGTH];
    int i, j;

    // Initialize each lane with 0s (representing an empty road)
    for (i = 0; i < NUM_OF_LANES; i++) {
        for (j = 0; j < ROAD_LENGTH; j++) {
            lane[i][j] = 0;
        }
    }

    // Add cars to the lanes randomly according to a certain percentage
    for (i = 0; i < NUM_OF_LANES; i++) {
        for (j = 0; j < ROAD_LENGTH; j++) {
            if ((rand() % 100) < PERCENTAGE_OF_CARS) { // If a random number is less than the percentage of cars
                lane[i][j] = 1; // Add a car to the lane at this spot
            }
        }
    }

    // Print out the initial state of the lanes
    for (i = 0; i < NUM_OF_LANES; i++) {
        for (j = 0; j < ROAD_LENGTH; j++) {
            printf("%d ", lane[i][j]);
        }
        printf("\n");
    }

    // Simulate cars moving forward
    int moved = 1; // flag to track if any cars have moved
    while (moved) {
        moved = 0; // reset the flag at the start of each loop

        // Move cars forward in each lane
        for (i = 0; i < NUM_OF_LANES; i++) {
            for (j = ROAD_LENGTH - 1; j >= 0; j--) { // move from right to left
                if (lane[i][j] == 1) { // if there is a car here
                    if (j < ROAD_LENGTH - 1 && lane[i][j+1] == 0) { // if there is an empty spot in front of it
                        lane[i][j+1] = 1; // move the car forward
                        lane[i][j] = 0; // empty the current spot
                        moved = 1; // set the flag to show that a car has moved
                    }
                }
            }
        }

        // Sleep for a fraction of a second to simulate real-time traffic flow
        usleep(300000);

        // Print out the state of the lanes after each move
        system("clear"); // clear the console before printing (UNIX-based systems)
        for (i = 0; i < NUM_OF_LANES; i++) {
            for (j = 0; j < ROAD_LENGTH; j++) {
                printf("%d ", lane[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}