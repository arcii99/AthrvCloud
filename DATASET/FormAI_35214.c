//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTERSECTION_COUNT 4

int main() {
    srand(time(NULL)); // Seed the random number generator

    int intersection[INTERSECTION_COUNT] = {0, 0, 0, 0}; // Each index represents a intersection
    int car_count = 0;
    int cycles = 0;

    while (cycles < 10) { // Set a limit for simulation
        printf("Cycle %d:\n", cycles + 1);

        // Randomly generate new cars at each intersection
        for (int i = 0; i < INTERSECTION_COUNT; i++) {
            int cars = rand() % 5; // Generate between 0-4 cars
            car_count += cars; // Increment overall car count
            intersection[i] += cars; // Increment intersection car count
            printf("Intersection %d: %d new cars\n", i + 1, cars);
        }

        // Simulate cars moving through intersections
        for (int i = 0; i < INTERSECTION_COUNT; i++) {
            if (intersection[i] > 0) {
                int outgoing_intersection = (i + 1) % INTERSECTION_COUNT; // Determine next intersection for car
                int cars_moving = rand() % (intersection[i] + 1); // Randomly determine amount of cars moving
                intersection[i] -= cars_moving; // Decrement current intersection car count
                intersection[outgoing_intersection] += cars_moving; // Increment outoing intersection car count
                printf("%d cars moved from Intersection %d to Intersection %d\n", cars_moving, i + 1, outgoing_intersection + 1);
            }
        }

        // Output current intersection car counts
        printf("Intersection Car Counts: ");
        for (int i = 0; i < INTERSECTION_COUNT; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");

        // Output overall car count
        printf("Total Cars: %d\n\n", car_count);

        cycles++; // Increment cycle count
    }

    return 0;
}