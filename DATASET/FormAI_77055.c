//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main() {
    // Define variables
    double x = 0.0; // position of the ball
    double y = 10.0; // initial height of the ball
    double vy = 0.0; // initial vertical velocity
    double t = 0.0; // time elapsed
    double dt = 0.01; // time step size
    double g = -9.81; // acceleration due to gravity
    double elasticity = 0.8; // coefficient of elasticity (bounciness)
    int num_bounces = 0; // number of bounces
    
    // Simulation loop
    while (y > 0.0) {
        // Update time and position
        t += dt;
        x = 5.0 * t;
        y = 10.0 + vy * t + 0.5 * g * pow(t, 2);
        
        // Check for collision with ground
        if (y <= 0.0) {
            // Compute new velocity after bounce
            vy *= -elasticity;
            num_bounces++;
            printf("Bounce %d: %.3f seconds\n", num_bounces, t);
        }
        
        // Print current position
        printf("Time: %.3f seconds, Position: (%.3f, %.3f)\n", t, x, y);
    }
    
    return 0;
}