//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 50
#define MIN_SPEED 10
#define MAX_ITERATIONS 100

struct car {
    int speed;
    int position;
};

int main() {
    srand(time(NULL));
    struct car cars[MAX_CARS];
    int num_cars = rand() % MAX_CARS + 1;
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        cars[i].position = i == 0 ? 0 : cars[i-1].position + 1 + cars[i-1].speed;
    }
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        for (int i = num_cars-1; i >= 0; i--) {
            if (cars[i].position + cars[i].speed >= cars[i+1].position) {
                // collision!
                cars[i].speed = 0;
            } else {
                cars[i].position += cars[i].speed;
                cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
            }
        }
        iteration++;
    }
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d final position: %d\n", i, cars[i].position);
    }
    return 0;
}