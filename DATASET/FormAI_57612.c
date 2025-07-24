//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define ACCELERATION 0.5   // meters / second^2
#define DECELERATION 1     // meters / second^2
#define MAX_SPEED 10       // meters / second
#define TURN_SPEED 5       // degrees / second

// Define a struct to represent the vehicle
typedef struct {
    double x;
    double y;
    double direction;
    double velocity;
} Vehicle;

// Define a function to simulate the vehicle's movement for a given duration
void simulate_vehicle(Vehicle* vehicle, double duration, bool accelerate, bool decelerate, bool turn_left, bool turn_right) {
    double time_elapsed = 0;
    while (time_elapsed < duration) {
        
        // Update the vehicle's velocity
        if (accelerate && vehicle->velocity < MAX_SPEED) {
            vehicle->velocity += ACCELERATION * (duration - time_elapsed);
            if (vehicle->velocity > MAX_SPEED) {
                vehicle->velocity = MAX_SPEED;
            }
        } else if (decelerate && vehicle->velocity > 0) {
            vehicle->velocity -= DECELERATION * (duration - time_elapsed);
            if (vehicle->velocity < 0) {
                vehicle->velocity = 0;
            }
        }
        
        // Update the vehicle's direction
        if (turn_left) {
            vehicle->direction -= TURN_SPEED * (duration - time_elapsed);
        } else if (turn_right) {
            vehicle->direction += TURN_SPEED * (duration - time_elapsed);
        }
        
        // Update the vehicle's position
        vehicle->x += vehicle->velocity * cos(vehicle->direction) * (duration - time_elapsed);
        vehicle->y += vehicle->velocity * sin(vehicle->direction) * (duration - time_elapsed);
        
        // Increment the time elapsed
        time_elapsed = duration;
    }
}

int main() {
    
    printf("Starting RC Vehicle Simulation...\n");
    
    // Initialize the vehicle's starting position and direction
    Vehicle vehicle = {0, 0, 0, 0};
    
    // Simulate the vehicle's movement for 10 seconds
    simulate_vehicle(&vehicle, 10, true, false, false, true);
    
    // Print the vehicle's final position and direction
    printf("Final Position: (%f, %f)\n", vehicle.x, vehicle.y);
    printf("Final Direction: %f degrees\n", vehicle.direction);
    
    printf("RC Vehicle Simulation complete.\n");
    
    return 0;
}