//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define MAX_DIRECTION 4
#define GRID_SIZE 20
#define MAX_STEPS 30

// define structure for the vehicle
typedef struct {
    int x, y;
    int direction;
} rc_vehicle;

// define function prototypes
int new_direction(rc_vehicle *vehicle);
int move_forward(rc_vehicle *vehicle);
void print_grid(rc_vehicle *vehicle);

int main() {
    // initialize vehicle at random position and direction
    rc_vehicle vehicle = {rand() % GRID_SIZE, rand() % GRID_SIZE, rand() % MAX_DIRECTION};
    
    // initialize random seed
    srand(time(NULL));
    
    // simulate remote control vehicle
    for (int i = 0; i < MAX_STEPS; i++) {
        // generate new direction for the vehicle and update direction
        vehicle.direction = new_direction(&vehicle);
        
        // move vehicle forward and update position
        int steps = move_forward(&vehicle);
        vehicle.x += steps * (vehicle.direction == 0) - steps * (vehicle.direction == 2);
        vehicle.y += steps * (vehicle.direction == 1) - steps * (vehicle.direction == 3);
        
        // print grid
        print_grid(&vehicle);
    }
    
    return 0;
}

int new_direction(rc_vehicle *vehicle) {
    int direction = vehicle->direction;
    while (direction == vehicle->direction) {
        direction = rand() % MAX_DIRECTION;
    }
    return direction;
}

int move_forward(rc_vehicle *vehicle) {
    int steps = rand() % (GRID_SIZE - 1) + 1;
    printf("Vehicle moved forward %d steps in direction %d\n", steps, vehicle->direction);
    return steps;
}

void print_grid(rc_vehicle *vehicle) {
    printf("\n");
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (x == vehicle->x && y == vehicle->y) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}