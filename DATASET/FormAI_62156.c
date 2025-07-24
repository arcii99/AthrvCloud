//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 60
#define DISTANCE 300
#define TIME_STEP 1
#define SIMULATION_TIME 600

void move_car(int *pos, int *speed, int *acceleration) {
    *pos = *pos + *speed * TIME_STEP + (*acceleration * TIME_STEP * TIME_STEP) / 2;
    *speed = *speed + *acceleration * TIME_STEP;
}

int main() {
    int cars[MAX_CARS];
    int speeds[MAX_CARS];
    int accelerations[MAX_CARS];
    int positions[MAX_CARS];

    // Set the initial positions and velocities of the cars
    srand(time(NULL));
    for (int i = 0; i < MAX_CARS; i++) {
        positions[i] = rand() % DISTANCE;
        speeds[i] = rand() % MAX_SPEED;
        accelerations[i] = rand() % 2 == 0 ? -1 : 1;
    }

    // Simulate the traffic flow
    for (int t = 0; t < SIMULATION_TIME; t += TIME_STEP) {
        // Print the current state of the traffic flow
        printf("Time: %d\n", t);
        for (int i = 0; i < MAX_CARS; i++) {
            for (int j = 0; j < positions[i]; j++) {
                printf(" ");
            }
            printf("=");
            for (int j = positions[i] + 1; j < DISTANCE; j++) {
                printf(" ");
            }
            printf("\n");
        }

        // Calculate the new positions and velocities of the cars
        for (int i = 0; i < MAX_CARS; i++) {
            int dist = positions[(i + 1) % MAX_CARS] - positions[i];
            int speed_diff = speeds[(i + 1) % MAX_CARS] - speeds[i];
            if (dist < 0) {
                dist += DISTANCE;
            }
            if (speed_diff < 0) {
                speed_diff += MAX_SPEED;
            }

            if (dist > 10 * speeds[i]) {
                accelerations[i] = 1;
            }
            else if (dist < 10 * speeds[i]) {
                accelerations[i] = -1;
            }
            else {
                accelerations[i] = 0;
            }

            if (speed_diff < -5) {
                accelerations[i] = -1;
            }
            else if (speed_diff > 5) {
                accelerations[i] = 1;
            }

            move_car(&positions[i], &speeds[i], &accelerations[i]);
            if (positions[i] > DISTANCE) {
                positions[i] -= DISTANCE;
            }
        }
    }

    return 0;
}