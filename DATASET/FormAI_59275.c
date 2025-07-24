//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <math.h>

int main() {
    
    // Constants
    const double G = 6.67430e-11; // Newton's gravitational constant
    const double M = 5.9722e24;   // Mass of Earth
    const double DT = 1.0;        // Time step in seconds
    const double R = 6371e3;      // Radius of Earth
    
    // Variables
    double x = 0, y = R;          // Initial position of the object
    double vx = 820, vy = 0;      // Initial velocity of the object
    double ax, ay;                // Acceleration of the object
    double fx, fy;                // Force acting on the object
    
    // Simulation
    while (1) {
        
        // Compute the force
        fx = -G * M * x / pow(sqrt(x*x + y*y), 3);
        fy = -G * M * y / pow(sqrt(x*x + y*y), 3);
        
        // Compute the acceleration
        ax = fx / M;
        ay = fy / M;
        
        // Compute the velocity
        vx += ax * DT;
        vy += ay * DT;
        
        // Compute the position
        x += vx * DT;
        y += vy * DT;
        
        // Check if the object hits the ground
        if (y < R) {
            printf("The object has landed!\n");
            break;
        }
        
        // Print the position of the object
        printf("x: %lf m, y: %lf m\n", x, y);
    }
    
    return 0;
}