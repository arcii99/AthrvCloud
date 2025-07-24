//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 50
#define MAX_SPEED 5
#define NUM_CARS 10
#define MAX_TIME 100
#define EMPTY ' '
#define CAR 'X'

int main()
{
    char road[ROAD_LENGTH] = {EMPTY};
    int positions[NUM_CARS] = {0};
    int speeds[NUM_CARS] = {0};

    srand(time(NULL));

    // initialize the positions and speeds of the cars randomly
    for (int i = 0; i < NUM_CARS; i++) {
        positions[i] = i * (ROAD_LENGTH / NUM_CARS);
        speeds[i] = rand() % MAX_SPEED + 1;
    }

    // start the simulation
    for (int t = 0; t < MAX_TIME; t++) {
        // update the positions of the cars
        for (int i = 0; i < NUM_CARS; i++) {
            positions[i] += speeds[i];

            // check for collisions
            if (positions[i] >= ROAD_LENGTH) {
                positions[i] = ROAD_LENGTH - 1;
                speeds[i] = 0;
            } else {
                for (int j = 0; j < NUM_CARS; j++) {
                    if (i != j && positions[i] == positions[j]) {
                        speeds[i] = speeds[j] = 0;
                    }
                }
            }
        }

        // update the state of the road
        for (int i = 0; i < ROAD_LENGTH; i++) {
            road[i] = EMPTY;
        }
        for (int i = 0; i < NUM_CARS; i++) {
            road[positions[i]] = CAR;
        }

        // print the state of the road
        printf("%3d ", t);
        for (int i = 0; i < ROAD_LENGTH; i++) {
            printf("%c", road[i]);
        }
        printf("\n");
    }

    return 0;
}