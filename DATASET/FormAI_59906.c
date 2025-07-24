//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants representing the number of vehicles and time steps
#define NUM_VEHICLES 100
#define NUM_TIME_STEPS 10

// Enumeration for the direction of the vehicles
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

// Structure representing a vehicle
typedef struct {
    int id;
    Direction dir;
    int x;
    int y;
} Vehicle;

// Function to generate a random direction
Direction random_direction() {
    return rand() % 4;
}

// Function to move a vehicle in a given direction
void move_vehicle(Vehicle* v) {
    switch (v->dir) {
        case NORTH:
            v->y--;
            break;
        case EAST:
            v->x++;
            break;
        case SOUTH:
            v->y++;
            break;
        case WEST:
            v->x--;
            break;
    }
}

int main() {
    srand(time(NULL));

    // Initialize the vehicles
    Vehicle vehicles[NUM_VEHICLES];
    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle v = {
            .id = i,
            .dir = random_direction(),
            .x = rand() % 10,
            .y = rand() % 10
        };
        vehicles[i] = v;
    }

    // Simulate the traffic flow for NUM_TIME_STEPS time steps
    for (int t = 0; t < NUM_TIME_STEPS; t++) {
        printf("Time step %d:\n", t);

        // Move each vehicle in its current direction
        for (int i = 0; i < NUM_VEHICLES; i++) {
            move_vehicle(&vehicles[i]);
        }

        // Print the current location of each vehicle
        for (int i = 0; i < NUM_VEHICLES; i++) {
            printf("Vehicle %d: (%d, %d)\n", vehicles[i].id, vehicles[i].x, vehicles[i].y);
        }

        printf("\n");
    }

    return 0;
}