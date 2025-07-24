//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Intersection struct to track traffic lights and cars
struct intersection {
    int north_light; // 0 = red, 1 = green
    int east_light;  // 0 = red, 1 = green
    int cars_north;  // number of cars waiting at north light
    int cars_east;   // number of cars waiting at east light
};

// Function to update traffic lights and move cars through intersection
void update_intersection(struct intersection *i) {
    if (i->north_light == 1) {
        if (i->cars_east > 0) {
            i->cars_east--;
            printf("Car has passed through intersection from east to north.\n");
        } else {
            i->north_light = 0;
            i->east_light = 1;
            printf("Traffic light has switched from north to east.\n");
        }
    } else {
        if (i->cars_north > 0) {
            i->cars_north--;
            printf("Car has passed through intersection from north to east.\n");
        } else {
            i->north_light = 1;
            i->east_light = 0;
            printf("Traffic light has switched from east to north.\n");
        }
    }
}

int main() {
    struct intersection i = {0, 1, 0, 0}; // initialize intersection with east light green

    srand(time(NULL)); // seed random number generator with current time

    // Simulate traffic flow for 10 iterations (1 iteration = 1 minute)
    for (int j = 0; j < 10; j++) {
        // Randomly add cars to each direction with probability 0.5
        if (rand() / (double) RAND_MAX < 0.5) {
            i.cars_north++;
            printf("Car added to north queue.\n");
        }
        if (rand() / (double) RAND_MAX < 0.5) {
            i.cars_east++;
            printf("Car added to east queue.\n");
        }

        // Update the intersection
        update_intersection(&i);
    }

    return 0;
}