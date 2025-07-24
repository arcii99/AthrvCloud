//FormAI DATASET v1.0 Category: Physics simulation ; Style: creative
// This is a physics simulation of a bouncing ball on a springy surface using C programming language.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.8 // acceleration due to gravity in m/s²
#define MASS 0.2 // mass of the ball in kg
#define SPRING_CONSTANT 500 // spring constant in N/m
#define DAMPING_FACTOR 0.5 // damping factor in Ns/m

int main() {
    // Initial conditions
    double height = 1.0; // initial height of the ball in meters
    double velocity = 0.0; // initial velocity of the ball in m/s
    double time = 0.0; // initial time in seconds
    double dt = 0.001; // time step in seconds
    
    // Simulation parameters
    double position = height; // initial position of the ball
    double acceleration = -GRAVITY; // initial acceleration due to gravity
    double force = 0.0; // initial force from the spring and damping
    
    // Simulation loop
    while (time < 10.0) { // simulate for 10 seconds
        // Compute new position, velocity, and acceleration
        position += velocity * dt;
        velocity += acceleration * dt;
        acceleration = (force - MASS * GRAVITY) / MASS;
        
        // Check if ball hits ground
        if (position <= 0.0) {
            // Reverse velocity and reduce by damping factor
            velocity = -velocity * DAMPING_FACTOR;
            position = 0.0;
        }
        
        // Compute new force from spring and damping
        force = -SPRING_CONSTANT * position - DAMPING_FACTOR * velocity;
        
        // Print time and position
        printf("Time: %lf s, Position: %lf m\n", time, position);
        
        // Increment time
        time += dt;
    }
    
    return 0;
}