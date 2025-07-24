//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 4
#define NUM_CARS 20

int main() {
    int lanes[NUM_LANES][NUM_CARS];
    int i, j;

    // Initialize lanes with 0s (no car present)
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < NUM_CARS; j++) {
            lanes[i][j] = 0;
        }
    }

    // Randomly place cars on the lanes
    srand(time(NULL));
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < NUM_CARS; j++) {
            int rand_num = rand() % 2;
            lanes[i][j] = rand_num;
        }
    }

    // Print out the current state of the lanes
    printf("Current traffic flow simulation:\n\n");
    for (i = 0; i < NUM_LANES; i++) {
        printf("Lane %d: ", i+1);
        for (j = 0; j < NUM_CARS; j++) {
            if (lanes[i][j] == 0) {
                printf(". ");
            } else {
                printf("C ");
            }
        }
        printf("\n");
    }

    // Simulate movement of cars in the lanes
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < NUM_CARS; j++) {
            if (lanes[i][j] == 1 && lanes[i][(j+1)%NUM_CARS] == 0) {
                lanes[i][j] = 0;
                lanes[i][(j+1)%NUM_CARS] = 1;
            }
        }
    }

    // Print out the updated state of the lanes
    printf("\n\nUpdated traffic flow simulation:\n\n");
    for (i = 0; i < NUM_LANES; i++) {
        printf("Lane %d: ", i+1);
        for (j = 0; j < NUM_CARS; j++) {
            if (lanes[i][j] == 0) {
                printf(". ");
            } else {
                printf("C ");
            }
        }
        printf("\n");
    }

    return 0;
}