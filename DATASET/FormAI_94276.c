//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 100
#define MAX_SPEED 10

int main() {
    // create an array of cars
    int cars[MAX_CARS];

    // randomly generate initial positions and speeds for each car
    srand(time(NULL));
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = rand() % MAX_TIME;
    }

    // simulate traffic flow for MAX_TIME seconds
    for (int t = 0; t < MAX_TIME; t++) {
        // update each car's position based on its speed
        for (int i = 0; i < MAX_CARS; i++) {
            cars[i] += (rand() % MAX_SPEED) - 4;
        }

        // ensure that no two cars occupy the same position
        for (int i = 0; i < MAX_CARS; i++) {
            for (int j = i + 1; j < MAX_CARS; j++) {
                if (cars[i] == cars[j]) {
                    cars[i] += 1;
                }
            }
        }

        // print the current state of traffic flow
        printf("Time: %d\n", t);
        for (int i = 0; i < MAX_CARS; i++) {
            printf("%d\t", cars[i]);
        }
        printf("\n");
    }

    printf("Simulation complete.\n");

    return 0;
}