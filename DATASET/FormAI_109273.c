//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11 // Gravitational constant
#define DT 3600 // Time step
#define MAX_STEPS 87600 // Maximum number of time steps to run (1 year)

typedef struct {
    double mass; // in kg
    double radius; // in m
    double x; // x position in m
    double y; // y position in m
    double z; // z position in m
    double vx; // velocity in x direction in m/s
    double vy; // velocity in y direction in m/s
    double vz; // velocity in z direction in m/s
} Body;

void update_positions(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * DT;
        bodies[i].y += bodies[i].vy * DT;
        bodies[i].z += bodies[i].vz * DT;
    }
}

void update_velocities(Body *bodies, int n) {
    double dx, dy, dz, r, f;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dz = bodies[j].z - bodies[i].z;
            r = sqrt(dx*dx + dy*dy + dz*dz);
            f = G * bodies[i].mass * bodies[j].mass / (r*r*r);
            bodies[i].vx += f * dx / bodies[i].mass * DT;
            bodies[i].vy += f * dy / bodies[i].mass * DT;
            bodies[i].vz += f * dz / bodies[i].mass * DT;
            bodies[j].vx -= f * dx / bodies[j].mass * DT;
            bodies[j].vy -= f * dy / bodies[j].mass * DT;
            bodies[j].vz -= f * dz / bodies[j].mass * DT;
        }
    }
}

void print_status(Body *bodies, int n, int step) {
    printf("Step %d:\n", step);
    for (int i = 0; i < n; i++) {
        printf("Body %d: mass=%g kg, radius=%g m, position=(%g,%g,%g) m, velocity=(%g,%g,%g) m/s\n", 
               i+1, bodies[i].mass, bodies[i].radius, bodies[i].x, bodies[i].y, bodies[i].z, 
               bodies[i].vx, bodies[i].vy, bodies[i].vz);
    }
}

int main() {
    Body sun = {1.989e30, 696340000, 0, 0, 0, 0, 0, 0};
    Body earth = {5.972e24, 6371000, 147095000000, 0, 0, 0, 30300, 0};
    Body moon = {7.342e22, 1737100, 147095000000 + 384400000, 0, 0, 0, 30300 + 1022, 0};
    Body mars = {6.39e23, 3389500, 0, 249230000000, 0, -24000, 0, 0};
    Body venus = {4.87e24, 6051800, -108200000000, 0, 0, 0, -35260, 0};

    Body bodies[] = {sun, earth, moon, mars, venus};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);

    for (int i = 0; i <= MAX_STEPS; i++) {
        update_positions(bodies, num_bodies);
        update_velocities(bodies, num_bodies);
        if (i % 365 == 0) {
            print_status(bodies, num_bodies, i/365);
        }
    }

    return 0;
}