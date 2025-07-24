//FormAI DATASET v1.0 Category: Physics simulation ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
    float x, y, vx, vy, ax, ay, t, dt, e;
    float width, height, x_wall;
    
    // Setting up initial conditions
    x = 0.0;
    y = 1.0;
    vx = 1.0;
    vy = 0.0;
    ax = 0.0;
    ay = -9.81;
    t = 0.0;
    dt = 0.01;
    e = 0.9;
    
    // Setting up the wall
    width = 5.0;      // Width of the wall
    height = 5.0;     // Height of the wall
    x_wall = 4.0;     // x-coordinate of the wall
    
    // Simulating the ball bouncing off the wall
    while (y > 0) {
        // Updating the position
        x += vx * dt;
        y += vy * dt;
        
        // Updating the velocity
        vx += ax * dt;
        vy += ay * dt;
        
        // Checking for collision with the wall
        if ((x >= x_wall) && (x <= x_wall + width) && (y <= height)) {
            vy = -e * vy;
        }
        
        // Updating the time
        t += dt;
        
        // Displaying the current state of the ball
        printf("Time: %.2f, Position: (%.2f, %.2f), Velocity: (%.2f, %.2f)\n", t, x, y, vx, vy);
    }
    
    return 0;
}