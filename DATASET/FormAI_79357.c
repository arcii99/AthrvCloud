//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
// A simulation of a molecule in a magnetic field

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265359
#define ELECTRON_CHARGE -1.60217662e-19
#define ELECTRON_MASS 9.10938356e-31

int main() {
    // Set up initial conditions
    srand(time(NULL));
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;
    double z = rand() / (double)RAND_MAX;
    double vx = rand() / (double)RAND_MAX * 10000;
    double vy = rand() / (double)RAND_MAX * 10000;
    double vz = rand() / (double)RAND_MAX * 10000;
    double bx = 0;
    double by = 0;
    double bz = 10;  // Magnetic field strength
    
    // Perform simulation
    double dt = 1e-9;  // Time step
    int nsteps = 1000;  // Number of steps to simulate
    
    for (int i = 0; i < nsteps; i++) {
        double fx = ELECTRON_CHARGE * (vy * bz - vz * by);
        double fy = ELECTRON_CHARGE * (vz * bx - vx * bz);
        double fz = ELECTRON_CHARGE * (vx * by - vy * bx);
        
        // Calculate new position and velocity
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        vx += fx / ELECTRON_MASS * dt;
        vy += fy / ELECTRON_MASS * dt;
        vz += fz / ELECTRON_MASS * dt;
        
        // Print out position and velocity
        printf("%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n", x, y, z, vx, vy, vz);
    }
    
    return 0;
}