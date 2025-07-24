//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARS 10

// Struct for Car
typedef struct car {
    int position;
    int speed;
} Car;

int main() {
    Car cars[NUM_CARS];

    // Initialize each car's position and speed randomly
    for(int i = 0; i < NUM_CARS; i++) {
        cars[i].position = rand() % 100;
        cars[i].speed = rand() % 20;
    }

    // Update car positions based on speed
    while(cars[NUM_CARS-1].position < 1000) {
        // Move each car forward based on its speed
        for(int i = 0; i < NUM_CARS; i++) {
            int nextPos = cars[i].position + cars[i].speed;

            // Check if next position would cause a collision
            if(i != NUM_CARS-1 && nextPos >= cars[i+1].position) {
                cars[i].speed = cars[i+1].speed;
            }

            // Check if car would go off the end of the road
            if(nextPos >= 1000) {
                nextPos = 1000;
                cars[i].speed = 0;
            }

            cars[i].position = nextPos;
        }

        // Print current car positions
        for(int i = 0; i < NUM_CARS; i++) {
            printf("Car %d at position %d\n", i, cars[i].position);
        }
        printf("\n");
    }

    return 0;
}