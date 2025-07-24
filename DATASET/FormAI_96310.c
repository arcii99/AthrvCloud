//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: modular
#include <stdio.h>
#include <math.h>

#define G 6.67 * pow(10, -11) // gravitational constant
#define MASS_EARTH 5.97 * pow(10, 24) // mass of earth
#define RADIUS_EARTH 6.37 * pow(10, 6) // radius of earth
#define DELTA_T 60 // time step

// function to calculate distance between two points in 3D space
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

// function to calculate the acceleration of an object due to gravity from another object
double acceleration(double mass, double x1, double y1, double z1, double x2, double y2, double z2) {
    double r = distance(x1, y1, z1, x2, y2, z2);
    return (G * mass) / pow(r, 2);
}

int main() {
    double x[2] = {0, RADIUS_EARTH + 408000}; // initial x positions of objects
    double y[2] = {0, 0}; // initial y positions of objects
    double z[2] = {0, 0}; // initial z positions of objects
    double vx[2] = {0, 1022}; // initial x velocities of objects
    double vy[2] = {0, 0}; // initial y velocities of objects
    double vz[2] = {0, 0}; // initial z velocities of objects
    double ax[2] = {0, 0}; // initial x accelerations of objects
    double ay[2] = {0, 0}; // initial y accelerations of objects
    double az[2] = {0, 0}; // initial z accelerations of objects
    
    for (int i = 0; i < 1000; i++) { // run simulation for 1000 time steps
        // calculate the x, y, and z components of acceleration for each object
        ax[0] = acceleration(MASS_EARTH, x[0], y[0], z[0], x[1], y[1], z[1]) * (x[1] - x[0]) / distance(x[0], y[0], z[0], x[1], y[1], z[1]);
        ay[0] = acceleration(MASS_EARTH, x[0], y[0], z[0], x[1], y[1], z[1]) * (y[1] - y[0]) / distance(x[0], y[0], z[0], x[1], y[1], z[1]);
        az[0] = acceleration(MASS_EARTH, x[0], y[0], z[0], x[1], y[1], z[1]) * (z[1] - z[0]) / distance(x[0], y[0], z[0], x[1], y[1], z[1]);
        ax[1] = acceleration(MASS_EARTH, x[1], y[1], z[1], x[0], y[0], z[0]) * (x[0] - x[1]) / distance(x[0], y[0], z[0], x[1], y[1], z[1]);
        ay[1] = acceleration(MASS_EARTH, x[1], y[1], z[1], x[0], y[0], z[0]) * (y[0] - y[1]) / distance(x[0], y[0], z[0], x[1], y[1], z[1]);
        az[1] = acceleration(MASS_EARTH, x[1], y[1], z[1], x[0], y[0], z[0]) * (z[0] - z[1]) / distance(x[0], y[0], z[0], x[1], y[1], z[1]);
        
        // update the x, y, and z components of velocity for each object using the calculated accelerations
        vx[0] += ax[0] * DELTA_T;
        vy[0] += ay[0] * DELTA_T;
        vz[0] += az[0] * DELTA_T;
        vx[1] += ax[1] * DELTA_T;
        vy[1] += ay[1] * DELTA_T;
        vz[1] += az[1] * DELTA_T;

        // update the x, y, and z components of position for each object using the updated velocities
        x[0] += vx[0] * DELTA_T;
        y[0] += vy[0] * DELTA_T;
        z[0] += vz[0] * DELTA_T;
        x[1] += vx[1] * DELTA_T;
        y[1] += vy[1] * DELTA_T;
        z[1] += vz[1] * DELTA_T;
        
        printf("Time Step %d: Object 1 position: (%f, %f, %f), Object 2 position: (%f, %f, %f)\n", i+1, x[0], y[0], z[0], x[1], y[1], z[1]);
    }
    
    return 0;
}