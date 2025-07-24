//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    int num_cars = rand() % 100 + 1; // generate a random number of cars between 1 and 100
    printf("Number of cars on the road: %d\n", num_cars);

    int *car_speeds = (int *) malloc(num_cars * sizeof(int));
    for (int i = 0; i < num_cars; i++) {
        car_speeds[i] = rand() % 60 + 10; // generate a random car speed between 10 and 70 km/h
    }

    int time_passed = 0;
    while (time_passed < 60) { // simulate 1 minute of traffic flow
        // calculate distance traveled by each car in this time step
        int *dist_traveled = (int *) malloc(num_cars * sizeof(int));
        for (int i = 0; i < num_cars; i++) {
            dist_traveled[i] = car_speeds[i] * time_passed / 60; // distance = speed * time
        }

        // check for collisions
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (dist_traveled[j] - dist_traveled[i] <= 2) { // collision if distance <= 2 meters
                    printf("Collision between car %d and car %d at time %d seconds\n", i, j, time_passed);
                }
            }
        }

        free(dist_traveled); // free memory allocated for distance traveled array

        time_passed++;
    }

    free(car_speeds); // free memory allocated for car speed array

    return 0;
}