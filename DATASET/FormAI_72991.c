//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant

typedef struct {
    double mass;
    double x, y;
    double vx, vy;
} Body;

int main() {
    int n = 4; // Number of bodies in system
    Body b[n]; // Array of bodies
    
    // Define properties of each body
    b[0].mass = 5.97e24;
    b[0].x = 0;
    b[0].y = 0;
    b[0].vx = 0;
    b[0].vy = 0;
    
    b[1].mass = 1.99e30;
    b[1].x = 1.5e11;
    b[1].y = 0;
    b[1].vx = 0;
    b[1].vy = 3e4;
    
    b[2].mass = 6.39e23;
    b[2].x = 2.3e11;
    b[2].y = 0;
    b[2].vx = 0;
    b[2].vy = 2.4e4;
    
    b[3].mass = 3.3e23;
    b[3].x = 0;
    b[3].y = 4.1e10;
    b[3].vx = 3.5e4;
    b[3].vy = 0;
    
    double dt = 60*60; // Time step in seconds
    int steps = 24*365*10; // Number of steps to simulate
    
    // Main simulation loop
    for (int i = 0; i < steps; i++) {
        // Calculate forces on each body
        for (int j = 0; j < n; j++) {
            double fx = 0, fy = 0;
            for (int k = 0; k < n; k++) {
                if (j != k) {
                    double dx = b[k].x - b[j].x;
                    double dy = b[k].y - b[j].y;
                    double r = sqrt(dx*dx + dy*dy);
                    double f = G * b[j].mass * b[k].mass / (r*r);
                    fx += f * dx / r;
                    fy += f * dy / r;
                }
            }
            // Update velocity and position of current body
            b[j].vx += fx / b[j].mass * dt;
            b[j].vy += fy / b[j].mass * dt;
            b[j].x += b[j].vx * dt;
            b[j].y += b[j].vy * dt;
        }
    }
    
    // Print final positions of each body
    for (int i = 0; i < n; i++) {
        printf("Body %d: (%.2e, %.2e)\n", i, b[i].x, b[i].y);
    }
    
    return 0;
}