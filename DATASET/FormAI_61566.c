//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define TIMESTEP 900 // simulation timestep in seconds
#define SCALE 1e16 // scaling factor for distances and masses

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} Body;

int main() {
    const int num_bodies = 3; // number of bodies
    const double timestep = TIMESTEP / SCALE; // timestep scaled
    Body bodies[num_bodies];

    // body 1 - sun
    bodies[0].x = 0.0; bodies[0].y = 0.0; bodies[0].z = 0.0; // position
    bodies[0].vx = 0.0; bodies[0].vy = 0.0; bodies[0].vz = 0.0; // velocity
    bodies[0].mass = 1.989e30 / SCALE; // mass scaled

    // body 2 - earth
    bodies[1].x = 147e9 / SCALE; bodies[1].y = 0.0; bodies[1].z = 0.0; // position
    bodies[1].vx = 0.0; bodies[1].vy = 30.29e3 / SCALE; bodies[1].vz = 0.0; // velocity
    bodies[1].mass = 5.97e24 / SCALE; // mass scaled

    // body 3 - moon
    bodies[2].x = 147e9 / SCALE; bodies[2].y = 0.0; bodies[2].z = 0.0; // position
    bodies[2].vx = 0.0; bodies[2].vy = 31.09e3 / SCALE; bodies[2].vz = 0.0; // velocity
    bodies[2].mass = 7.35e22 / SCALE; // mass scaled

    for(int i = 0; i < num_bodies; ++i) {
        printf("Body %d\n", i + 1);
        printf("Position: x=%.2f y=%.2f z=%.2f\n", bodies[i].x, bodies[i].y, bodies[i].z);
        printf("Velocity: vx=%.2f vy=%.2f vz=%.2f\n", bodies[i].vx, bodies[i].vy, bodies[i].vz);
        printf("Mass: %.2f\n\n", bodies[i].mass * SCALE);
    }

    // simulation loop
    for(int t = 0; t < 365 * 24 * 60 * 60 / TIMESTEP; ++t) {
        // compute forces
        for(int i = 0; i < num_bodies; ++i) {
            double fx = 0.0, fy = 0.0, fz = 0.0;
            for(int j = 0; j < num_bodies; ++j) {
                if(i == j) continue;
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double dist = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * bodies[i].mass * bodies[j].mass / (dist * dist * dist);
                fx += f * dx;
                fy += f * dy;
                fz += f * dz;
            }
            bodies[i].vx += timestep * fx / bodies[i].mass;
            bodies[i].vy += timestep * fy / bodies[i].mass;
            bodies[i].vz += timestep * fz / bodies[i].mass;
        }

        // update positions
        for(int i = 0; i < num_bodies; ++i) {
            bodies[i].x += timestep * bodies[i].vx;
            bodies[i].y += timestep * bodies[i].vy;
            bodies[i].z += timestep * bodies[i].vz;
        }
    }

    for(int i = 0; i < num_bodies; ++i) {
        printf("Body %d end state\n", i + 1);
        printf("Position: x=%.2f y=%.2f z=%.2f\n", bodies[i].x * SCALE, bodies[i].y * SCALE, bodies[i].z * SCALE);
        printf("Velocity: vx=%.2f vy=%.2f vz=%.2f\n", bodies[i].vx * SCALE, bodies[i].vy * SCALE, bodies[i].vz * SCALE);
        printf("Mass: %.2f\n\n", bodies[i].mass * SCALE);
    }

    return 0;
}