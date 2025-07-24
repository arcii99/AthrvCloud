//FormAI DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81  // acceleration due to gravity

int main() {
    double time = 0.0;  // simulation time in seconds
    double dt = 0.01;  // time step in seconds
    double x = 0.0;  // object's horizontal position in meters
    double y = 5.0;  // object's vertical position in meters
    double vx = 10.0;  // object's horizontal velocity in m/s
    double vy = 0.0;  // object's vertical velocity in m/s
    double ax = 0.0;  // object's horizontal acceleration in m/s^2
    double ay = -GRAVITY;  // object's vertical acceleration in m/s^2
    double mass = 1.0;  // object's mass in kilograms
    
    while (y >= 0.0) {  // simulation loop until the object hits the ground
        // calculate forces on the object
        double fx = 0.0;  // no horizontal forces
        double fy = mass * ay;  // gravity is the only vertical force
        
        // calculate horizontal and vertical acceleration of the object
        ax = fx / mass;
        ay = fy / mass;
        
        // update horizontal and vertical velocity of the object using Euler's method
        vx += ax * dt;
        vy += ay * dt;
        
        // update horizontal and vertical position of the object using Euler's method
        x += vx * dt;
        y += vy * dt;
        
        // output the object's position and velocity at this time step
        printf("Time: %.2f s, Position: (%.2f, %.2f) m, Velocity: (%.2f, %.2f) m/s\n", time, x, y, vx, vy);
        
        // update simulation time
        time += dt;
    }
    
    // output the time when the object hit the ground
    printf("The object hit the ground at %.2f s\n", time);
    
    return 0;
}