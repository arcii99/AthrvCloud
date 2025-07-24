//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11

struct body {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double mass;
};

int main(int argc, char **argv) {
    const int n = 3;
    struct body bodies[n];

    // Set up the Sun
    bodies[0].mass = 1.989e30;
    bodies[0].x = 0.0;
    bodies[0].y = 0.0;
    bodies[0].z = 0.0;
    bodies[0].vx = 0.0;
    bodies[0].vy = 0.0;
    bodies[0].vz = 0.0;

    // Set up the Earth
    bodies[1].mass = 5.972e24;
    bodies[1].x = 1.496e11;
    bodies[1].y = 0.0;
    bodies[1].z = 0.0;
    bodies[1].vx = 0.0;
    bodies[1].vy = 2.978e4;
    bodies[1].vz = 0.0;

    // Set up the Moon
    bodies[2].mass = 7.342e22;
    bodies[2].x = 1.496e11 + 3.844e8;
    bodies[2].y = 0.0;
    bodies[2].z = 0.0;
    bodies[2].vx = 0.0;
    bodies[2].vy = 2.978e4 + 1.022e3;
    bodies[2].vz = 0.0;

    const double dt = 60.0;
    for (int step = 0; ; ++step) {
        // Compute forces
        for (int i = 0; i < n; ++i) {
            double fx = 0.0;
            double fy = 0.0;
            double fz = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                const double dx = bodies[j].x - bodies[i].x;
                const double dy = bodies[j].y - bodies[i].y;
                const double dz = bodies[j].z - bodies[i].z;
                const double r = sqrt(dx*dx + dy*dy + dz*dz);
                const double f = G * bodies[i].mass * bodies[j].mass / (r * r);
                fx += f * dx / r;
                fy += f * dy / r;
                fz += f * dz / r;
            }
            const double ax = fx / bodies[i].mass;
            const double ay = fy / bodies[i].mass;
            const double az = fz / bodies[i].mass;
            bodies[i].vx += ax * dt;
            bodies[i].vy += ay * dt;
            bodies[i].vz += az * dt;
        }

        // Update positions
        for (int i = 0; i < n; ++i) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        // Output results
        if (step % 100 == 0) {
            printf("%d ", step);
            for (int i = 0; i < n; ++i) {
                printf("%g %g %g ", bodies[i].x, bodies[i].y, bodies[i].z);
            }
            printf("\n");
        }
    }

    return 0;
}