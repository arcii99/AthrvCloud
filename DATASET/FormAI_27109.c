//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_SIZE 20
#define MAX_SPEED 5
#define CAR_DENSITY 0.2
#define MAX_TIME 100

typedef struct {
    int x, y;
    int speed;
} car;

int main() {
    srand(time(NULL)); // Seed for random number generation
    // Initialize the road
    int road[ROAD_SIZE] = {0};
    for (int i = 0; i < ROAD_SIZE * CAR_DENSITY; i++) {
        road[rand() % ROAD_SIZE] = rand() % MAX_SPEED + 1; // Assign random speeds to random cars
    }
    // Simulation loop
    for (int t = 0; t < MAX_TIME; t++) {
        // Print the state of the road
        printf("Timestep %d:\n", t);
        for (int i = 0; i < ROAD_SIZE; i++) {
            if (road[i] == 0) {
                printf("- ");
            } else {
                printf("%d ", road[i]);
            }
        }
        printf("\n");
        // Update the cars
        for (int i = ROAD_SIZE - 2; i >= 0; i--) {
            if (road[i] != 0) {
                car c = {i, road[i], road[i]};
                for (int j = i + 1; j < ROAD_SIZE; j++) {
                    if (road[j] != 0) {
                        break;
                    }
                    // Accelerate
                    if (c.speed < MAX_SPEED && c.speed < road[j]) {
                        c.speed++;
                    }
                    // Decelerate
                    if (c.speed >= j - i) {
                        c.speed = j - i - 1;
                    }
                    // Random slow down
                    if (rand() % 10 == 0 && c.speed > 0) { 
                        c.speed--;
                    }
                }
                road[i + c.speed] = c.speed;
                road[i] = 0;
            }
        }
    }
    return 0;
}