//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define NUM_LANES 3
#define NUM_CARS 10

int main(void) {
    // initialize variables
    int lane[NUM_LANES][NUM_CARS] = {0};
    int car_positions[NUM_CARS] = {0};
    int car_speeds[NUM_CARS] = {1, 1, 2, 2, 3, 4, 4, 4, 5, 5};
    int tick = 0;

    // run simulation for 100 ticks
    while (tick < 100) {
        // update car positions
        for (int i = 0; i < NUM_CARS; i++) {
            // check if car can move
            if (car_positions[i] + car_speeds[i] < NUM_LANES) {
                // move car
                lane[car_positions[i]][i] = 0;
                car_positions[i] += car_speeds[i];
                lane[car_positions[i]][i] = 1;
            } else {
                // car has reached end of lane
                lane[car_positions[i]][i] = 0;
                car_positions[i] = 0;
                lane[car_positions[i]][i] = 1;
            }
        }

        // print current traffic flow
        printf("Tick %d:\n", tick);
        for (int i = 0; i < NUM_LANES; i++) {
            for (int j = 0; j < NUM_CARS; j++) {
                if (lane[i][j] == 1) {
                    printf("C");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
        printf("\n");

        // increment tick counter
        tick++;
    }
    return 0;
}