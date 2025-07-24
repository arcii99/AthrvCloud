//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define constants for the size of the simulated remote control vehicle
#define VEHICLE_LENGTH 10 // meters
#define VEHICLE_WIDTH 5 // meters

// Define structure for the simulated vehicle
typedef struct {
    double x_pos; // Vehicle's x-coordinate position in the world
    double y_pos; // Vehicle's y-coordinate position in the world
    double speed; // Vehicle's speed in meters per second
    double direction; // Vehicle's direction in degrees (0 is North)
} Vehicle;

// Function to move the vehicle according to its current speed and direction
void move_vehicle(Vehicle *v, double time_elapsed) {
    double x_movement = v->speed * time_elapsed * sin(v->direction);
    double y_movement = v->speed * time_elapsed * cos(v->direction);
    v->x_pos += x_movement;
    v->y_pos += y_movement;
}

// Function to print the current position and speed of the vehicle
void print_vehicle_status(Vehicle *v) {
    printf("Vehicle position: (%.2f, %.2f)\n", v->x_pos, v->y_pos);
    printf("Vehicle speed: %.2fm/s\n", v->speed);
}

int main() {
    // Initialize the vehicle
    Vehicle my_vehicle;
    my_vehicle.x_pos = 0.0;
    my_vehicle.y_pos = 0.0;
    my_vehicle.speed = 5.0; // 5 meters per second
    my_vehicle.direction = 0.0; // Start heading North
    
    // Move the vehicle for 10 seconds and print its status after each second
    double time_elapsed = 0.0;
    while (time_elapsed <= 10.0) {
        move_vehicle(&my_vehicle, 1.0);
        print_vehicle_status(&my_vehicle);
        time_elapsed += 1.0;
    }
    
    return 0;
}