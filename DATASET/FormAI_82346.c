//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
    // Define constant variables
    const double G = 6.67e-11;   // Gravitational constant
    const double dt = 1e-5;      // Time step
    const int num_steps = 10000; // Number of time steps
    
    // Define initial variables
    double m1 = 5.97e24; // Mass of Earth
    double m2 = 7.34e22; // Mass of Moon
    double r = 3.84e8;   // Distance between Earth and Moon
    double vx = 0;       // Initial x velocity
    double vy = 1022;    // Initial y velocity, Moon's circular velocity
    double x1 = 0;       // Initial x position of Earth
    double x2 = r;       // Initial x position of Moon
    double y1 = 0;       // Initial y position of Earth
    double y2 = 0;       // Initial y position of Moon
    
    // Define variables for simulation
    double ax1, ay1, ax2, ay2, dx, dy, d, f;
    int i;
    
    // Loop through each time step
    for (i = 0; i < num_steps; i++) {
        // Compute distance between Earth and Moon
        dx = x2 - x1;
        dy = y2 - y1;
        d = sqrt(dx*dx + dy*dy);
        
        // Compute force between Earth and Moon
        f = G*m1*m2/(d*d);
        
        // Compute acceleration of Earth and Moon
        ax1 = f/m1 * dx/d;
        ay1 = f/m1 * dy/d;
        ax2 = -f/m2 * dx/d;
        ay2 = -f/m2 * dy/d;
        
        // Update velocities of Earth and Moon
        vx += ax2*dt;
        vy += ay2*dt;
        
        // Update positions of Earth and Moon
        x1 += vx*dt;
        x2 += vx*dt;
        y1 += vy*dt;
        y2 += vy*dt;
        
        // Print x and y positions of Earth and Moon
        printf("Time: %f seconds, Earth Position: (%f, %f), Moon Position: (%f, %f)\n", i*dt, x1, y1, x2, y2);
    }
    
    return 0;
}