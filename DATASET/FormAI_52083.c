//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define MAX_CARS 10
#define SIM_TIME 60 // seconds
#define CAR_LENGTH 3 // meters
#define CAR_SPEED 15 // meters per second
#define FOLLOW_DISTANCE 5 // meters
#define SIM_TICK 1 // seconds

int main() {
    int tick;
    int total_cars = 0;
    int cars_per_lane[NUM_LANES] = {0};
    double distance_per_tick = CAR_SPEED * SIM_TICK;
    double current_space;
    srand(time(0)); // seed the random generator with current time

    for (tick = 0; tick < SIM_TIME; tick += SIM_TICK) {
        printf("============== TICK %d ==============\n", tick);

        // spawn new cars with a random delay
        if (total_cars < MAX_CARS) {
            for (int i = 0; i < NUM_LANES; i++) {
                if (cars_per_lane[i] < MAX_CARS / NUM_LANES) {
                    double random_delay = (double)rand() / (double)RAND_MAX * 5; // max delay of 5 seconds
                    if (random_delay < SIM_TICK) {
                        cars_per_lane[i]++;
                        total_cars++;
                        printf("New car spawned in lane %d\n", i+1);
                    }
                }
            }
        }

        // move existing cars
        for (int i = 0; i < NUM_LANES; i++) {
            for (int j = 0; j < cars_per_lane[i]; j++) {
                current_space = j * FOLLOW_DISTANCE + (SIM_TIME - tick) * CAR_SPEED;
                if (current_space > CAR_LENGTH) {
                    printf("Car in lane %d, position %d moved forward\n", i+1, j+1);
                }
            }
        }
    }

    return 0;
}