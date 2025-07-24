//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 60

int main() {
    int cars[MAX_CARS], current_time, total_cars, i;
    srand(time(NULL));

    // Initializing cars on road
    for(i = 0; i < MAX_CARS; i++) {
        cars[i] = rand() % 5 + 1;
    }

    // Simulation of traffic flow for MAX_TIME minutes
    for(current_time = 1; current_time <= MAX_TIME; current_time++) {
        total_cars = 0;
        printf("Time - %d minutes\n", current_time);

        // Counting total cars on road
        for(i = 0; i < MAX_CARS; i++) {
            total_cars += cars[i];
        }

        // Displaying traffic flow information
        printf("Total cars on road - %d\n", total_cars);
        printf("Average speed - %d km/hr\n", rand() % 50 + 10);

        // Moving cars forward as per speed limit
        for(i = 0; i < MAX_CARS; i++) {
            if(cars[i]) {
                cars[i] -= rand() % 5 + 1;
                if(cars[i] < 0) cars[i] = 0;
            }
        }
        printf("\n");
    }

    return 0;
}