//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 80
#define NUM_LANES 3
#define MAX_SPEED 5
#define MAX_DENSITY 0.8
#define NUM_TICKS 1000

void initialize_lanes(int lanes[NUM_LANES][LANE_LENGTH]) {
    int i, j;
    
    // Set all cells to -1 (empty)
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = -1;
        }
    }
    
    // Set initial car positions and speeds
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < (int)(MAX_DENSITY * LANE_LENGTH); j++) {
            lanes[i][j] = rand() % (MAX_SPEED + 1);
        }
    }
}

void print_lanes(int lanes[NUM_LANES][LANE_LENGTH]) {
    int i, j;
    
    // Print each lane row-by-row
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            if (lanes[i][j] == -1) {
                printf("-");
            } else {
                printf("%d", lanes[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void update_lanes(int lanes[NUM_LANES][LANE_LENGTH]) {
    int i, j, k, speed, distance;

    // Copy current lane to temporary variable
    int lanes_copy[NUM_LANES][LANE_LENGTH];
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            lanes_copy[i][j] = lanes[i][j];
        }
    }

    // Update cars in each lane
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            if (lanes[i][j] != -1) {

                // Determine speed of current car
                speed = lanes[i][j];

                // Determine distance to car in front
                distance = LANE_LENGTH;
                for (k = 1; k <= speed; k++) {
                    if (lanes[(i + k) % NUM_LANES][(j + k) % LANE_LENGTH] != -1) {
                        distance = k - 1;
                        break;
                    }
                }

                // Update car's position based on distance to car in front
                if (distance > speed) {
                    lanes_copy[i][(j + speed) % LANE_LENGTH] = speed;
                    lanes_copy[i][j] = -1;
                } else {
                    lanes_copy[i][(j + distance) % LANE_LENGTH] = distance - 1;
                    lanes_copy[i][j] = -1;
                }
            }
        }
    }

    // Copy updated lane back to original variable
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = lanes_copy[i][j];
        }
    }
}

int main() {
    int lanes[NUM_LANES][LANE_LENGTH];
    int tick;

    // Seed random number generator
    srand(time(NULL));

    // Initialize lanes
    initialize_lanes(lanes);

    // Simulate traffic flow for NUM_TICKS ticks
    for (tick = 0; tick < NUM_TICKS; tick++) {
        // Print current state of lanes
        print_lanes(lanes);

        // Update lanes
        update_lanes(lanes);
    }

    return 0;
}