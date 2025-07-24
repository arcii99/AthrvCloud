//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 5
#define MAX_LANE 5 

int main() {
    srand(time(0));

    int numberOfCars = rand() % MAX_CARS + 1;
    int speedOfCars[numberOfCars];

    for (int i = 0; i < numberOfCars; ++i) {
        speedOfCars[i] = rand() % MAX_SPEED + 1;
    }

    char road[MAX_LANE][100] = {};

    for (int i = 0; i < numberOfCars; ++i) {
        int lane = rand() % MAX_LANE + 1;
        int position = 0;
        while (road[lane][position] != '\0') {
            position++;
        }

        road[lane][position] = 'C';

        for (int j = 0; j < speedOfCars[i]; ++j) {
            if (position + j + 1 < 100) {
                road[lane][position + j + 1] = '-';
                road[lane][position + j] = '\0';
            } else {
                road[lane][position + j] = '\0';
                break;
            }
        }
    }

    for (int i = 0; i < MAX_LANE; ++i) {
        printf("Lane %d: %s\n", i, road[i]);
    }

    return 0;
}