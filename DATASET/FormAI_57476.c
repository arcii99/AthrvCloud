//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for the directions of the vehicle
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

// define a struct for the vehicle's location and direction
typedef struct {
    int x;
    int y;
    int direction;
} Vehicle;

// create a function to generate a random direction for the vehicle
int randomDirection() {
    int directions[] = {FORWARD, BACKWARD, LEFT, RIGHT};
    int randomIndex = rand() % 4;
    return directions[randomIndex];
}

// create a function to move the vehicle in its current direction
void moveVehicle(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case FORWARD:
            vehicle->y += 1;
            break;
        case BACKWARD:
            vehicle->y -= 1;
            break;
        case LEFT:
            vehicle->x -= 1;
            break;
        case RIGHT:
            vehicle->x += 1;
            break;
        default:
            printf("Invalid direction!\n");
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // initialize the vehicle's starting location and direction
    Vehicle vehicle = {0, 0, randomDirection()};
    
    // move the vehicle 10 times and print out its new location after each move
    for (int i = 0; i < 10; i++) {
        moveVehicle(&vehicle);
        printf("Vehicle moved to location (%d, %d)\n", vehicle.x, vehicle.y);
    }
    
    return 0;
}