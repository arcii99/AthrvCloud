//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 50
#define MAX_SPEED 5
#define NUM_CARS 10

struct Car {
    int pos;
    int speed;
};

void simulate(struct Car *cars) {
    int timer = 0;
    while (timer < 100) {
        for (int i = 0; i < NUM_CARS; i++) {
            if (i == 0) {
                if (cars[i].pos > ROAD_LENGTH) {
                    cars[i].pos = 0;
                }
                continue;
            }
            // check distance from previous car
            int prev_pos = cars[i-1].pos;
            int pos_diff = prev_pos - cars[i].pos;
            if (pos_diff <= 0) {
                // too close, slow down
                cars[i].speed--;
            } else if (cars[i].speed < MAX_SPEED) {
                // not too close and not at max speed, speed up
                cars[i].speed++;
            }
            // move car based on speed
            cars[i].pos += cars[i].speed;
            if (cars[i].pos > ROAD_LENGTH) {
                // reset car to beginning of road when it reaches end
                cars[i].pos = 0;
            }
        }
        // print current positions
        printf("At time %d\n", timer);
        for (int i = 0; i < NUM_CARS; i++) {
            printf("Car %d position: %d\n", i, cars[i].pos);
        }
        printf("\n");
        timer++;
    }
}

int main() {
    // initialize random seed
    srand(time(NULL));
    // initialize cars
    struct Car cars[NUM_CARS];
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].pos = rand() % ROAD_LENGTH;
        cars[i].speed = rand() % MAX_SPEED + 1;
    }
    // run simulation
    simulate(cars);
    return 0;
}