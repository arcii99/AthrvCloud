//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_TICKS 100

int main() {
    int traffic[MAX_TICKS]; // array to store number of cars per tick
    int tick; // current tick of simulation
    int num_cars; // current number of cars
    int i; // loop counter

    // initialize simulation
    srand(time(NULL)); // seed the random number generator
    traffic[0] = rand() % MAX_CARS + 1; // randomly set the initial number of cars
    tick = 1;

    // run simulation
    while (tick < MAX_TICKS) {
        // determine if a car will enter or leave the traffic
        if (rand() % 2 == 0) {
            num_cars = traffic[tick - 1] + 1; // a car enters the traffic
        } else {
            num_cars = traffic[tick - 1] - 1; // a car leaves the traffic
        }

        // check if number of cars exceeds maximum capacity
        if (num_cars > MAX_CARS) {
            num_cars = MAX_CARS;
        }

        // check if number of cars is less than minimum capacity
        if (num_cars < 0) {
            num_cars = 0;
        }

        traffic[tick] = num_cars; // save the number of cars for the current tick
        tick++; // move to the next tick
    }

    // print the results
    printf("Traffic flow simulation\n");
    printf("Tick\tNumber of cars\n");
    for (i = 0; i < MAX_TICKS; i++) {
        printf("%d\t%d\n", i, traffic[i]);
    }

    return 0;
}