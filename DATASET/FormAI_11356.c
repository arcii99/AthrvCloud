//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 200
#define CAR_LENGTH 4
#define MAX_CARS 20
#define MAX_SPEED 5

int main(void) {
    int road[ROAD_LENGTH] = {0};
    int cars[MAX_CARS];
    int speed[MAX_CARS];
    int count = 0;

    srand(time(NULL));

    // Add cars randomly to the road
    for (int i = 0; i < MAX_CARS; i++) {
        int pos = rand() % ROAD_LENGTH;
        if (road[pos] != 1) {
            road[pos] = 1;
            cars[count] = pos;
            speed[count] = (rand() % MAX_SPEED) + 1;
            count++;
        }
    }

    // Move cars on the road
    int time = 0;
    while (1) {
        // Print current state of road
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] == 1) {
                printf("|-o-|");
            } else {
                printf("     ");
            }
        }
        printf("\n");

        // Move each car
        for (int i = 0; i < count; i++) {
            int pos = cars[i];

            // Remove car from current position
            road[pos] = 0;

            // Calculate new position
            int new_pos = pos + speed[i];
            if (new_pos >= ROAD_LENGTH) {
                break;
            }

            // Check if there is a car ahead
            int j;
            for (j = new_pos; j < new_pos + CAR_LENGTH && j < ROAD_LENGTH; j++) {
                if (road[j] == 1) {
                    break;
                }
            }

            // Update speed based on distance to next car
            if (j != new_pos + CAR_LENGTH) {
                speed[i] = j - pos - CAR_LENGTH;
                if (speed[i] < 0) {
                    speed[i] = 0;
                }
            } else {
                speed[i] = (rand() % MAX_SPEED) + 1;
            }

            // Update position
            cars[i] = pos + speed[i];
            road[cars[i]] = 1;
        }

        // Check if all cars have reached the end
        int done = 1;
        for (int i = 0; i < count; i++) {
            if (cars[i] < ROAD_LENGTH - CAR_LENGTH) {
                done = 0;
                break;
            }
        }
        if (done) {
            break;
        }

        // Wait some time
        time++;
        if (time % 10 == 0) {
            printf("\033c");
        }
    }

    printf("Simulation complete!\n");

    return 0;
}