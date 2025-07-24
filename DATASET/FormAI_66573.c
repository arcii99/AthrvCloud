//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
    double xs = 100; // starting x position
    double ys = 0; // starting y position
    double v = 50; // initial velocity
    double theta = 30; // launch angle in degrees
    double g = 9.81; // acceleration due to gravity in m/s^2
    double t = 0; // starting time
    double dt = 0.01; // time step
    double xe, ye; // ending x and y positions
    double x, y; // current x and y positions
    double vx, vy; // current x and y velocities
    double ax, ay; // current x and y accelerations
    
    printf("Starting Simulation...\n");
    
    while (ys >= 0) {
        ax = 0; // no acceleration in x direction
        ay = -g; // constant acceleration in y direction
        
        vx = v * cos(theta * M_PI / 180); // calculate current x velocity
        vy = v * sin(theta * M_PI / 180); // calculate current y velocity
        
        x = xs + vx * t + 0.5 * ax * pow(t, 2); // calculate current x position
        y = ys + vy * t + 0.5 * ay * pow(t, 2); // calculate current y position
        
        if (y < 0) {
            ye = 0; // projectile hit the ground
            xe = xs + vx * ((-1)*ys/vy) ; // calculate x position at ground level
        } else {
            ye = y; // projectile still in air
            xe = x; // projectile still in air
        }
        
        printf("Time: %0.2f s | X: %0.2f m | Y: %0.2f m\n", t, xe, ye); // print current stats
        
        t += dt; // increase time step
    }
    
    printf("Simulation Complete.\n");

    return 0;
}