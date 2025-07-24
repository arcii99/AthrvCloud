//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // Acceleration due to gravity in m/s^2
#define TIME_STEP 0.01 // Time Step in seconds

int main() {
    double mass = 0.1; // Mass of the object in kg
    double k = 0.02; // Drag coefficient
    double initial_height = 5.0; // Initial height of the object in meters
    double initial_velocity = 0.0; // Initial velocity of the object in m/s
    double position = initial_height; // Starting position of the object
    
    double acceleration, velocity;
    int time = 0; // Current time in seconds
    
    while (position > 0) { // Loop until the object hits the ground
        acceleration = GRAVITY - (k/mass) * pow(initial_velocity, 2); // Calculate acceleration
        velocity = initial_velocity + acceleration * TIME_STEP; // Calculate velocity
        position = position + velocity * TIME_STEP; // Calculate position
        
        printf("Time: %d seconds\n", time);
        printf("Height: %.2f meters\n", position);
        printf("Velocity: %.2f m/s\n", velocity);
        printf("--------------------\n");
        
        initial_velocity = velocity; // Update initial velocity for next iteration
        time++; // Increment time counter
    }
    
    printf("Object hit the ground at %d seconds.\n", time);
    
    return 0;
}