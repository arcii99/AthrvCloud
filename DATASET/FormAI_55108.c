//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
/* This program simulates a bouncing ball with some basic physics. */

#include <stdio.h>
#include <stdlib.h>

#define GRAVITY 9.81 // Acceleration due to gravity in m/s^2
#define MAX_HEIGHT 20.0 // Maximum height of the ball in meters
#define TIME_STEP 0.01 // Time step for physics calculations in seconds
#define INITIAL_VELOCITY 10.0 // Initial velocity of the ball in m/s
#define BOUNCINESS 0.8 // Coefficient of restitution for bounces
#define EPSILON 0.001 // Small value used to check for near-zero velocities

int main() {
    double position = 0.0; // Position of the ball
    double velocity = INITIAL_VELOCITY; // Velocity of the ball
    double time = 0.0; // Current time in seconds
    
    // Loop until the ball stops bouncing or reaches maximum height
    while (position > 0.0 || velocity > EPSILON) {
        // Calculate the net force on the ball
        double net_force = -GRAVITY;
        if (position < EPSILON && velocity < EPSILON) {
            net_force = 0.0; // Ball has come to rest
        }
        
        // Calculate the acceleration of the ball
        double acceleration = net_force / 1.0; // Mass of ball assumed to be 1kg
        
        // Update the velocity and position of the ball
        velocity += acceleration * TIME_STEP;
        position += velocity * TIME_STEP;
        
        // Check for bounces
        if (position < EPSILON && velocity < EPSILON) {
            // Calculate the bounce velocity
            velocity *= -BOUNCINESS;
            
            // Check for maximum height
            if (velocity > EPSILON && -velocity*velocity / (2.0*GRAVITY) + position > MAX_HEIGHT) {
                velocity *= -BOUNCINESS; // Ball won't reach maximum height on next bounce
            }
        }
        
        // Increment the time
        time += TIME_STEP;
        
        // Print the current state of the ball
        printf("Time: %.2f s, Position: %.2f m, Velocity: %.2f m/s\n", time, position, velocity);
    }
    
    return 0;
}