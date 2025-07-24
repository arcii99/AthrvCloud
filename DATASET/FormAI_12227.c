//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_TIME 60

struct Car {
    int id;
    int speed;
    int distance;
};

int main() {
    srand(time(NULL)); // Seed the random number generator

    struct Car cars[MAX_CARS];
    int total_distance = 0;

    // Initialize cars with random speeds
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % 20 + 40; // Speeds between 40 and 59 mph
        cars[i].distance = 0;
    }

    for (int time = 0; time < MAX_TIME; time++) {
        printf("Time: %d\n", time);

        // Move cars forward based on their speeds
        for (int i = 0; i < MAX_CARS; i++) {
            cars[i].distance += cars[i].speed;
        }

        // Check for collisions
        for (int i = 0; i < MAX_CARS; i++) {
            for (int j = 0; j < MAX_CARS; j++) {
                if (i != j && cars[i].distance == cars[j].distance) {
                    printf("COLLISION: Car %d and Car %d have collided!\n", i, j);
                    exit(1); // Exit program on collision
                }
            }
        }

        // Print out the current positions of the cars
        for (int i = 0; i < MAX_CARS; i++) {
            printf("Car %d: Speed %d, Distance %d\n", cars[i].id, cars[i].speed, cars[i].distance);
        }

        // Calculate the total distance traveled by all cars
        for (int i = 0; i < MAX_CARS; i++) {
            total_distance += cars[i].distance;
        }

        printf("Total distance traveled: %d\n", total_distance);
    }

    return 0;
}