//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the joyful world of physics simulations!\n");
    printf("In this program, we will simulate the motion of a bouncing ball.\n");
    printf("Let's get started!\n");
    
    // Constants
    const double g = 9.81; // acceleration due to gravity
    const double dt = 0.01; // time step
    
    // Initial conditions
    double x = 0; // initial position
    double y = 10; // initial height
    double v = 0; // initial velocity
    
    // Simulation loop
    for (int i = 0; i < 1000; i++)
    {
        // Update position and velocity
        x += v*dt;
        y -= v*dt - 0.5*g*dt*dt;
        v -= g*dt;
        
        // Check for collision with ground
        if (y <= 0)
        {
            printf("Bounce!\n");
            // Calculate rebound velocity using coefficient of restitution
            v *= -0.8;
            // Add some randomness to the rebound direction
            v += (rand()/(double)RAND_MAX - 0.5)*2;
            // Add a little bit of energy loss due to friction
            v *= 0.95;
            // Make sure the ball doesn't sink into the ground
            y = 0;
        }
        
        // Print current position and velocity
        printf("time = %.2f, position = (%.2f, %.2f), velocity = %.2f\n", i*dt, x, y, v);
    }
    
    printf("Simulation complete! Thanks for bouncing with us!\n");
    
    return 0;
}