//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 50 // length of the road
#define NUM_CARS 10 // number of cars on the road
#define CAR_LENGTH 2 // length of each car
#define MAX_SPEED 5 // maximum speed a car can travel
#define SIMULATION_STEPS 100 // number of simulation steps to run
#define SEED 42 // seed for the random generator

typedef struct {
    int position;
    int speed;
} Car;

// initialize the cars randomly on the road
void init_cars(Car *cars) {
    for (int i = 0; i < NUM_CARS; i++) {
        // generate a random position and speed for each car
        cars[i].position = rand() % (ROAD_LENGTH - CAR_LENGTH);
        cars[i].speed = rand() % MAX_SPEED;
    }
}

// simulate the movement of the cars for one step
void simulate(Car *cars) {
    // move each car a certain distance based on its speed
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].position += cars[i].speed;

        // check for collisions and adjust speeds if necessary
        for (int j = 0; j < NUM_CARS; j++) {
            if (i != j && cars[i].position < cars[j].position + CAR_LENGTH && cars[i].position + CAR_LENGTH > cars[j].position) {
                int distance = cars[j].position - cars[i].position - CAR_LENGTH;
                if (cars[i].speed >= distance) {
                    cars[i].speed = distance - 1;
                }
            }
        }

        // adjust speed based on distance to next car
        if (i < NUM_CARS - 1 && cars[i + 1].position < cars[i].position + CAR_LENGTH) {
            int distance = cars[i + 1].position - cars[i].position - CAR_LENGTH;
            if (cars[i].speed > distance) {
                cars[i].speed = distance;
            }
        }

        // bound speed by maximum speed
        if (cars[i].speed > MAX_SPEED) {
            cars[i].speed = MAX_SPEED;
        }

        // wrap around to the other end of the road if necessary
        if (cars[i].position >= ROAD_LENGTH) {
            cars[i].position -= ROAD_LENGTH;
        }
    }
}

// print the current state of the road
void print_road(Car *cars) {
    char road[ROAD_LENGTH];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '-';
    }
    for (int i = 0; i < NUM_CARS; i++) {
        for (int j = 0; j < CAR_LENGTH; j++) {
            road[(cars[i].position + j) % ROAD_LENGTH] = 'X';
        }
    }
    printf("%s\n", road);
}

int main() {
    srand(SEED);

    Car cars[NUM_CARS];
    init_cars(cars);
    
    for (int i = 0; i < SIMULATION_STEPS; i++) {
        printf("Step %d:\n", i);
        print_road(cars);
        simulate(cars);
    }
    
    return 0;
}