//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Claude Shannon
#include <stdio.h> 

#define MAX_CARS 50

int main(void) {
    int cars[MAX_CARS] = {0};
    int total_cars = 0;
    int time = 0;

    // start simulation
    while (time < 60) {
        // add random number of cars to the road
        int new_cars = rand() % 10;
        for (int i = 0; i < new_cars; i++) {
            if (total_cars >= MAX_CARS) {
                printf("Traffic jam! Could not add more cars\n");
                break;
            }
            cars[total_cars++] = rand() % 5 + 1;
        }

        // move cars on the road
        for (int i = 0; i < total_cars; i++) {
            if (cars[i] <= 0) {
                continue;
            }
            int speed = rand() % 5 + 1;
            if (speed >= cars[i] && cars[i] < 5) {
                printf("Car %d speeds up to %d mph\n", i, cars[i] + 1);
                cars[i]++;
            }
            else if (cars[i] >= speed) {
                printf("Car %d slows down to %d mph\n", i, cars[i] - 1);
                cars[i]--;
            }
            else {
                printf("Car %d maintains speed at %d mph\n", i, cars[i]);
            }
        }

        // check for collisions
        for (int i = 0; i < total_cars - 1; i++) {
            if (cars[i] <= 0) {
                continue;
            }
            for (int j = i+1; j < total_cars; j++) {
                if (cars[j] <= 0) {
                    continue;
                }
                if (cars[i] == cars[j]) {
                    printf("Cars %d and %d collide!\n", i, j);
                    cars[i] = 0;
                    cars[j] = 0;
                }
            }
        }

        // increment time
        time++;

        // print current road status
        printf("Road status at time %d:\n", time);
        for (int i = 0; i < total_cars; i++) {
            if (cars[i] <= 0) {
                printf("Car %d: Crashed\n", i);
            }
            else {
                printf("Car %d: %d mph\n", i, cars[i]);
            }
        }
        printf("\n");
    }

    printf("Simulation completed!\n");
    return 0;
}