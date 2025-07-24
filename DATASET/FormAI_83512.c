//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Newton's gravitational constant

typedef struct { // structure to hold the properties of a celestial body
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} CelestialBody;

int main() {
    CelestialBody sun = {"Sun", 1.989e30, 6.9634e8, 0, 0, 0, 0, 0, 0}; // initialize the Sun
    CelestialBody earth = {"Earth", 5.972e24, 6.371e6, 1.4710e11, 0, 0, 0, 3.029e4, 0}; // initialize the Earth
    CelestialBody moon = {"Moon", 7.342e22, 1.7374e6, 1.4710e11 + 3.844e8, 0, 0, 0, 3.029e4 + 1.022e3, 0}; // initialize the Moon
    CelestialBody mars = {"Mars", 6.39e23, 3.39e6, 2.067e11, 0, 0, 0, 2.65e4, 0}; // initialize Mars

    CelestialBody bodies[] = {sun, earth, moon, mars}; // create an array of celestial bodies

    int n = sizeof(bodies) / sizeof(CelestialBody); // calculate the number of celestial bodies

    double t = 0; // initialize time
    double dt = 3600; // set time step to one hour

    while (1) { // simulation loop

        // print the positions of the celestial bodies
        printf("Time: %g s\n", t);
        for (int i = 0; i < n; i++) {
            printf("%s:\t%g\t%g\t%g\n", bodies[i].name, bodies[i].x, bodies[i].y, bodies[i].z);
        }
        printf("\n");

        // calculate the gravitational force between every pair of celestial bodies
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double d = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * bodies[i].mass * bodies[j].mass / (d*d);
                double fx = f * dx / d;
                double fy = f * dy / d;
                double fz = f * dz / d;
                bodies[i].vx += fx / bodies[i].mass * dt;
                bodies[i].vy += fy / bodies[i].mass * dt;
                bodies[i].vz += fz / bodies[i].mass * dt;
                bodies[j].vx -= fx / bodies[j].mass * dt;
                bodies[j].vy -= fy / bodies[j].mass * dt;
                bodies[j].vz -= fz / bodies[j].mass * dt;
            }
        }

        // update the positions of the celestial bodies
        for (int i = 0; i < n; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        t += dt; // increment time

    }

    return 0;
}