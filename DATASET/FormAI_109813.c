//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
/* Remote Control Vehicle Simulation Program */

#include <stdio.h>
#include <stdlib.h>

// Define vehicle structure
typedef struct {
    int x, y; // Vehicle position
    int speed; // Vehicle speed
    int direction; // Vehicle direction
} vehicle;

// Function to move vehicle position
void moveVehicle(vehicle *v) {
    switch(v->direction) {
        case 0: // Move up
            v->y += v->speed;
            break;
        case 1: // Move right
            v->x += v->speed;
            break;
        case 2: // Move down
            v->y -= v->speed;
            break;
        case 3: // Move left
            v->x -= v->speed;
            break;
        default:
            printf("Invalid direction.\n");
    }
}

int main() {
    // Initialize vehicle
    vehicle v1 = {0, 0, 5, 1};

    // Simulation loop
    int i;
    for(i = 0; i < 10; i++) {
        printf("Vehicle position: (%d, %d)\n", v1.x, v1.y);
        moveVehicle(&v1);
    }

    return 0;
}