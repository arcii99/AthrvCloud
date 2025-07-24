//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for the simulation
#define BOX_SIZE 10
#define MAX_TIME 10000
#define NUMBER_OF_VEHICLES 3

// define a struct for the vehicle properties
typedef struct Vehicle {
    int id;
    int x;
    int y;
    int on;
} Vehicle;

// define function to randomly generate initial position for vehicles
void generate_random_positions(Vehicle *vehicles) {
    int i;
    for (i = 0; i < NUMBER_OF_VEHICLES; i++) {
        vehicles[i].x = rand() % BOX_SIZE;
        vehicles[i].y = rand() % BOX_SIZE;
        vehicles[i].on = 1;
    }
}

// define function to check if all vehicles are off
int all_vehicles_off(Vehicle *vehicles) {
    int i;
    for (i = 0; i < NUMBER_OF_VEHICLES; i++) {
        if (vehicles[i].on == 1) {
            return 0;
        }
    }
    return 1;
}

// define main function
int main() {
    srand(time(0));

    // initialize vehicles with random positions
    Vehicle vehicles[NUMBER_OF_VEHICLES];
    generate_random_positions(vehicles);

    // simulate remote control vehicles
    int time = 0;
    while (time < MAX_TIME && !all_vehicles_off(vehicles)) {
        int i;
        for (i = 0; i < NUMBER_OF_VEHICLES; i++) {
            if (vehicles[i].on == 1) {
                printf("Vehicle %d position: (%d,%d)\n", vehicles[i].id, vehicles[i].x, vehicles[i].y);

                // randomly move vehicle in x or y direction
                if (rand() % 2 == 0) {
                    if (rand() % 2 == 0) {
                        vehicles[i].x = (vehicles[i].x + 1) % BOX_SIZE;
                    } else {
                        vehicles[i].x = (vehicles[i].x - 1 + BOX_SIZE) % BOX_SIZE;
                    }
                } else {
                    if (rand() % 2 == 0) {
                        vehicles[i].y = (vehicles[i].y + 1) % BOX_SIZE;
                    } else {
                        vehicles[i].y = (vehicles[i].y - 1 + BOX_SIZE) % BOX_SIZE;
                    }
                }

                // randomly turn off vehicle
                if (rand() % 2 == 0) {
                    vehicles[i].on = 0;
                    printf("Vehicle %d turned off\n", vehicles[i].id);
                }
            }
        }
        time++;
    }
    printf("Simulation ended\n");

    return 0;
}