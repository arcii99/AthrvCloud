//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

int main() {
    srand(time(NULL)); // seed random number generator with current time

    int cars[MAX_CARS];
    int i, speed, distance;

    // initialize car positions randomly
    for (i = 0; i < MAX_CARS; i++) {
        cars[i] = rand() % 1000; // limit position to 1000 meters
    }

    // simulate traffic flow for 10 seconds
    for (i = 0; i <= 10; i++) {
        printf("Second %d\n", i);

        // move cars based on their speed
        for (int j = 0; j < MAX_CARS; j++) {
            speed = rand() % 100; // generate random speed between 0 and 100 km/h
            distance = speed * (i+1); // calculate distance based on speed and time
            cars[j] += distance; // update car position
            printf("Car %d: %d m\n", j, cars[j]);
        }

        printf("\n"); // add empty line for readability
    }

    return 0;
}