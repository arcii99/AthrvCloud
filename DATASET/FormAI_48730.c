//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS_PER_LANE 10
#define NUM_LANES 3

int main(void) {
    int lanes[NUM_LANES][MAX_CARS_PER_LANE] = {0};
    int num_cars[NUM_LANES] = {0};
    int i, j, k;

    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        // Add new car to a random lane
        if (rand() % 2 == 0) {
            for (j = 0; j < NUM_LANES && num_cars[j] == MAX_CARS_PER_LANE; j++) {}
            if (j == NUM_LANES) {
                printf("No space for new car.\n");
            } else {
                lanes[j][num_cars[j]++] = 1;
            }
        }

        // Update each car's position
        for (j = 0; j < NUM_LANES; j++) {
            for (k = 0; k < num_cars[j]; k++) {
                if (k == 0) {
                    lanes[j][k] = 0;
                } else if (lanes[j][k - 1] == 0) {
                    lanes[j][k - 1] = 1;
                    lanes[j][k] = 0;
                }
            }
        }

        // Print current state of the traffic
        for (j = 0; j < NUM_LANES; j++) {
            printf("Lane %d: ", j);
            for (k = 0; k < num_cars[j]; k++) {
                printf("%c", lanes[j][k] ? '*' : '-');
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}