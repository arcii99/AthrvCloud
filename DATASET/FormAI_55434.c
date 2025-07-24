//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

typedef struct {
    double x, y;
    double vx, vy;
    double ax, ay;
    double mass;
} Body;

int main() {
    // create an array of 4 bodies
    Body bodies[4] = {
        {0, 0, 0, 0, 0, 0, 5.972e24}, // earth
        {150e9, 0, 0, 30000, 0, 0, 1.989e30}, // sun
        {0, 400e6, -29000, 0, 0, 0, 7.35e22}, // moon
        {-200e9, 0, 0, -25000, 0, 0, 2.2e14} // rogue planet
    };

    // set the simulation parameters
    double timestep = 3600;
    double duration = 31556926 * 2; // 2 years
    int nsteps = (int) (duration / timestep);
    int nbodies = sizeof(bodies) / sizeof(bodies[0]);

    // run the simulation
    for (int step = 0; step < nsteps; step++) {
        // calculate the acceleration of each body
        for (int i = 0; i < nbodies; i++) {
            double ax = 0, ay = 0;
            for (int j = 0; j < nbodies; j++) {
                if (i == j) continue;
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dist = sqrt(dx*dx + dy*dy);
                double force = G * bodies[i].mass * bodies[j].mass / (dist*dist);
                ax += force * dx / dist / bodies[i].mass;
                ay += force * dy / dist / bodies[i].mass;
            }
            bodies[i].ax = ax;
            bodies[i].ay = ay;
        }
        // update the velocity and position of each body
        for (int i = 0; i < nbodies; i++) {
            bodies[i].vx += bodies[i].ax * timestep;
            bodies[i].vy += bodies[i].ay * timestep;
            bodies[i].x += bodies[i].vx * timestep;
            bodies[i].y += bodies[i].vy * timestep;
        }
    }

    // print the final positions of the bodies
    for (int i = 0; i < nbodies; i++) {
        printf("Body %d: x=%f y=%f\n", i, bodies[i].x, bodies[i].y);
    }

    return 0;
}