//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>
#define G 6.6743e-11

struct planet // Defining a structure for each planet
{
    double x, y, z; // Position components
    double vx, vy, vz; // Velocity components
    double mass; // Mass of the planet
};

void calculate_forces(struct planet p1, struct planet p2, double *fx, double *fy, double *fz) // Function to calculate the forces between two planets
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1.mass * p2.mass / (r*r);
    *fx = f*dx/r;
    *fy = f*dy/r; 
    *fz = f*dz/r;
}

int main() 
{
    struct planet sun = {0, 0, 0, 0, 0, 0, 1.989e30}; // Defining the sun
    struct planet earth = {1.4959e11, 0, 0, 0, 29800, 0, 5.972e24}; // Defining the earth
    double fx, fy, fz;
    int i;
    double dt = 1.0; // Time step size
    for (i = 0; i < 365*24*60*60/dt; i++) // Loop for 1 year of simulation
    {
        calculate_forces(sun, earth, &fx, &fy, &fz); // Calculating the forces between the sun and the earth
        double ax = fx/earth.mass;
        double ay = fy/earth.mass;
        double az = fz/earth.mass;
        earth.vx += ax*dt;
        earth.vy += ay*dt;
        earth.vz += az*dt;
        earth.x += earth.vx*dt;
        earth.y += earth.vy*dt;
        earth.z += earth.vz*dt;
    }
    printf("The position of the earth after 1 year of simulation is (%f, %f, %f) meters from the sun.", earth.x, earth.y, earth.z);
    return 0;
}