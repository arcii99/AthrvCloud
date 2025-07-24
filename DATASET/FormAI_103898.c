//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: creative
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double mass;
} Planet;

// G: gravitational constant
const double G = 6.6743e-11;

void update_planet(Planet *p, double dt, Planet planets[]) {
    double ax = 0, ay = 0, az = 0;

    for (int i = 0; i < NUM_PLANETS; i++) {
        if (p == &planets[i]) {
            continue;  // skip this planet
        }

        // calculate distance between two planets
        double dx = planets[i].x - p->x;
        double dy = planets[i].y - p->y;
        double dz = planets[i].z - p->z;
        double dist = sqrt(dx*dx + dy*dy + dz*dz);

        // calculate gravitational force
        double f = G * p->mass * planets[i].mass / (dist*dist);

        // calculate acceleration
        ax += f * dx / dist / p->mass;
        ay += f * dy / dist / p->mass;
        az += f * dz / dist / p->mass;
    }

    // update velocity and position
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->vz += az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    Planet planets[NUM_PLANETS];

    // set initial conditions for planets
    planets[0] = (Planet) { .x = 0, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .mass = 1.989e30 };  // the sun
    planets[1] = (Planet) { .x = 1.4710e11, .y = 0, .z = 0, .vx = 0, .vy = 3.0287e4, .vz = 0, .mass = 5.97e24 };  // earth
    planets[2] = (Planet) { .x = 0, .y = 5.7909e10, .z = 0, .vx = -4.7374e4, .vy = 0, .vz = 0, .mass = 3.31e23 };  // venus
    planets[3] = (Planet) { .x = 2.2794e11, .y = 0, .z = 0, .vx = 0, .vy = 2.4077e4, .vz = 0, .mass = 6.39e23 };  // mars
    planets[4] = (Planet) { .x = 0, .y = 1.0821e11, .z = 0, .vx = -3.0287e4, .vy = 0, .vz = 0, .mass = 4.87e24 };  // mercury
    planets[5] = (Planet) { .x = 0, .y = 1.4960e11, .z = 0, .vx = -2.9783e4, .vy = 0, .vz = 0, .mass = 1.90e27 };  // jupiter
    planets[6] = (Planet) { .x = 0, .y = 2.9925e11, .z = 0, .vx = -2.1028e4, .vy = 0, .vz = 0, .mass = 5.68e26 };  // saturn
    planets[7] = (Planet) { .x = 0, .y = 4.4983e11, .z = 0, .vx = -1.4795e4, .vy = 0, .vz = 0, .mass = 8.68e25 };  // uranus

    const int num_steps = 10000;
    const double dt = 3600;  // 1 hour

    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < NUM_PLANETS; i++) {
            update_planet(&planets[i], dt, planets);
        }

        // print out the positions of the planets
        printf("Step %d\n", step);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: x=%.2f y=%.2f z=%.2f\n", i, planets[i].x, planets[i].y, planets[i].z);
        }
        printf("\n");
    }

    return 0;
}