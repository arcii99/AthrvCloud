//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROADS 4
#define LANES 2
#define CARS 50

int road[ROADS][LANES][CARS]; // The road matrix

void generateCars() {
    srand(time(NULL)); // Initialize random seed

    for (int i = 0; i < ROADS; i++) {
        for (int j = 0; j < LANES; j++) {
            for (int k = 0; k < CARS; k++) {
                road[i][j][k] = rand() % 2; // Generate either 0 or 1 for no car or a car
            }
        }
    }
}

void printRoad() {
    for (int i = 0; i < ROADS; i++) {
        printf("Road %d:\n", i);
        for (int j = 0; j < LANES; j++) {
            for (int k = 0; k < CARS; k++) {
                printf("%d ", road[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void simulateTraffic(int time) {
    for (int t = 0; t < time; t++) {
        printf("Time: %d\n", t + 1);
        for (int i = 0; i < ROADS; i++) {
            for (int j = 0; j < LANES; j++) {
                for (int k = 0; k < CARS; k++) {
                    if (road[i][j][k]) { // If there is a car at this position
                        if (k + 1 >= CARS || road[i][j][k + 1]) { // If we have reached the end of the lane or there is a car in front of us
                            road[i][j][k] = 0; // Remove the current car
                        } else {
                            road[i][j][k + 1] = road[i][j][k]; // Move the car forward
                            road[i][j][k] = 0;
                        }
                    }
                }
            }
        }
        printRoad();
    }
}

int main() {
    generateCars();
    printRoad();
    simulateTraffic(10);
    return 0;
}