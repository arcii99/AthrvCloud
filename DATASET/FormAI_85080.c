//FormAI DATASET v1.0 Category: Physics simulation ; Style: happy
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // gravity acceleration in m/s^2
#define TIME_STEP 0.1 // time step in seconds
#define FLOOR_HEIGHT 0 // height of the floor in meters
#define BALL_RADIUS 0.1 // radius of the ball in meters
#define BALL_MASS 0.5 // mass of the ball in kilograms
#define BOUNCE_COEFFICIENT 0.8 // coefficient of restitution of the ball

int main() {
    double velocity = 0; // initial velocity of the ball
    double height = 1; // initial height of the ball in meters
    double time = 0; // current simulation time in seconds
    
    while (height > FLOOR_HEIGHT + BALL_RADIUS) {
        double acceleration = -GRAVITY; // acceleration due to gravity in m/s^2
        double force = BALL_MASS * acceleration; // force acting on the ball in newtons
        
        // Update velocity and position using Euler's method
        velocity += force / BALL_MASS * TIME_STEP;
        height += velocity * TIME_STEP;
        
        // Check for collision with the floor
        if (height < FLOOR_HEIGHT + BALL_RADIUS) {
            // Calculate bounce velocity using the coefficient of restitution
            velocity = -BOUNCE_COEFFICIENT * velocity;
            height = FLOOR_HEIGHT + BALL_RADIUS;
        }
        
        // Print current simulation time and height of the ball
        printf("Time: %.1f s, Height: %.2f m\n", time, height);
        
        // Increment simulation time
        time += TIME_STEP;
    }
    
    return 0;
}