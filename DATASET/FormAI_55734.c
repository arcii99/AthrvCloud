//FormAI DATASET v1.0 Category: Physics simulation ; Style: excited
#include <stdio.h>
#include <math.h>

// Defining constants
#define G 6.6743e-11 // gravitational constant
#define m1 5.972e+24 // mass of Earth
#define m2 102e+3 // mass of satellite
#define r0 6.3781e+6 // radius of Earth
#define v0 7.8e+3 // initial velocity of satellite

int main() {
    // Initializing variables
    double x1, x2, y1, y2, r, F, Fx, Fy, t, dt;
    double vx = v0, vy = 0.0;
    
    // Setting time step
    dt = 0.1;
    
    // Initializing time
    t = 0.0;
    
    // Initializing position of Earth and satellite
    x1 = 0.0;
    y1 = 0.0;
    x2 = r0;
    y2 = 0.0;
    
    // Calculating distance between Earth and satellite
    r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    // Calculating gravitational force between Earth and satellite
    F = G * m1 * m2 / pow(r, 2);
    
    // Calculating components of gravitational force
    Fx = F * (x1 - x2) / r;
    Fy = F * (y1 - y2) / r;
    
    while (r >= r0) {
        // Updating position of satellite using Euler's method
        x2 += vx * dt;
        y2 += vy * dt;
        
        // Updating velocity of satellite using Euler's method
        vx -= Fx / m2 * dt;
        vy -= Fy / m2 * dt;
        
        // Updating distance between Earth and satellite
        r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        
        // Updating gravitational force between Earth and satellite
        F = G * m1 * m2 / pow(r, 2);
        
        // Updating components of gravitational force
        Fx = F * (x1 - x2) / r;
        Fy = F * (y1 - y2) / r;
        
        // Updating time
        t += dt;
    }
    
    printf("Satellite has crashed into Earth after %f seconds!\n", t);
    
    return 0;
}