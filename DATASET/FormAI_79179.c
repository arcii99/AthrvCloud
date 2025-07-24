//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define struct for remote control vehicle
typedef struct Vehicle {
    int x_pos; // X position of vehicle
    int y_pos; // Y position of vehicle
    bool is_on; // Determines if vehicle is on or off
    bool is_moving_forward; // Determines if vehicle is moving forward or backward
} Vehicle;

// Function to turn the vehicle on or off
void toggle_vehicle(Vehicle *vehicle) {
    if (vehicle->is_on) {
        printf("Vehicle is now off.\n");
        vehicle->is_on = false;
    } else {
        printf("Vehicle is now on.\n");
        vehicle->is_on = true;
    }
}

// Function to move vehicle forward or backward
void move_vehicle(Vehicle *vehicle) {
    if (vehicle->is_on) {
        if (vehicle->is_moving_forward) {
            vehicle->x_pos++;
            printf("Vehicle moved forward to (%d, %d)\n", vehicle->x_pos, vehicle->y_pos);
        } else {
            vehicle->x_pos--;
            printf("Vehicle moved backward to (%d, %d)\n", vehicle->x_pos, vehicle->y_pos);
        }
    } else {
        printf("Vehicle must be turned on to move.\n");
    }
}

// Function to randomly toggle the vehicle on or off
void randomly_toggle_vehicle(Vehicle *vehicle) {
    srand(time(NULL)); // Seed random number generator
    int probability = rand() % 2; // Generate random number
    if (probability == 1) {
        toggle_vehicle(vehicle);
    }
}

// Function to randomly move the vehicle forward or backward
void randomly_move_vehicle(Vehicle *vehicle) {
    srand(time(NULL)); // Seed random number generator
    int probability = rand() % 2; // Generate random number
    if (probability == 1) {
        vehicle->is_moving_forward = !vehicle->is_moving_forward; // Toggle direction of movement
        move_vehicle(vehicle);
    }
}

int main() {
    // Create a new vehicle
    Vehicle my_vehicle;
    my_vehicle.x_pos = 0;
    my_vehicle.y_pos = 0;
    my_vehicle.is_on = false;
    my_vehicle.is_moving_forward = true;

    // Toggle vehicle on
    toggle_vehicle(&my_vehicle);

    // Randomly toggle vehicle and move it for 10 iterations
    for (int i = 0; i < 10; i++) {
        randomly_toggle_vehicle(&my_vehicle);
        randomly_move_vehicle(&my_vehicle);
    }

    return 0;
}