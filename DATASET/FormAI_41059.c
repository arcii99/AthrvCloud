//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_TIME 100
#define CAR_POPULATION 10
#define GAP_LIMIT 5

int main() {

    // Declare variables
    int time_step;
    int i;
    int j;

    // Set up the initial car positions
    int cars[CAR_POPULATION];
    srand(time(NULL));
    for (i=0; i<CAR_POPULATION; i++) {
        cars[i] = rand() % (GAP_LIMIT+1);
    }

    // Start the traffic flow simulation
    for (time_step=0; time_step<TOTAL_TIME; time_step++) {

        // Print the current positions of the cars
        printf("Time Step %d: ", time_step);
        for (i=0; i<CAR_POPULATION; i++) {
            printf("%d ", cars[i]);
        }
        printf("\n");

        // Update the car positions
        for (i=0; i<CAR_POPULATION; i++) {
            if (cars[i] == GAP_LIMIT) {
                // Car is at maximum position, does not move
                continue;
            }
            for (j=i+1; j<CAR_POPULATION; j++) {
                if (cars[j] - cars[i] <= GAP_LIMIT) {
                    // Car has to slow down due to traffic
                    break;
                }
            }
            cars[i] += (j-i-1);
        }
    }

    return 0;
}