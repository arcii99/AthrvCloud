//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int traffic[10] = {0}; // Initialize 10-lane traffic flow
    int i, j, k; // Loop variables
    int light; // Traffic light variable
    int count = 1; // Count variable to track simulation rounds

    srand(time(NULL)); // Seed random number generator

    while(count <= 5) { // Run simulation for 5 rounds
        printf("Round %d:\n", count);

        for(i = 0; i < 10; i++) { // Generate random traffic flow for each lane
            traffic[i] = rand() % 10 + 1; // Random number between 1 and 10
        }

        printf("\n\tTraffic flow:\n");
        for(i = 0; i < 10; i++) { // Print traffic flow
            printf("\tLane %d: ", i+1);
            for(j = 0; j < traffic[i]; j++) {
                printf("#");
            }
            printf("\n");
        }

        light = rand() % 2 + 1; // Generate random traffic light

        if(light == 1) { // East-West traffic light
            printf("\n\tEast-West traffic light is green.\n");

            // Cars move from east to west
            printf("\n\tCars moving from east to west: \n");
            for(i = 0; i < traffic[0]; i++) {
                printf("\t#");
                traffic[0]--;
            }
            printf("\n");

            // Cars move from west to east
            printf("\n\tCars moving from west to east: \n");
            for(i = 9; i >= 0; i--) {
                for(j = 0; j < traffic[i]; j++) {
                    printf("\t");
                }
                while(traffic[i] > 0) {
                    printf("#");
                    traffic[i]--;
                }
                printf("\n");
            }
        } else { // North-South traffic light
            printf("\n\tNorth-South traffic light is green.\n");

            // Cars move from north to south
            printf("\n\tCars moving from north to south: \n");
            for(i = 0; i < traffic[1]; i++) {
                printf("\t#");
                traffic[1]--;
            }
            printf("\n");

            // Cars move from south to north
            printf("\n\tCars moving from south to north: \n");
            for(i = 8; i >= 2; i--) {
                for(j = 0; j < traffic[i]; j++) {
                    printf("\t");
                }
                while(traffic[i] > 0) {
                    printf("#");
                    traffic[i]--;
                }
                printf("\n");
            }
        }

        count++; // Increment simulation round
    }

    return 0;
}