//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67428e-11

typedef struct {
    double x, y;
    double vx, vy;
    double mass;
} Body;

void update_positions(Body *bodies, double dt, int count);
void update_velocities(Body *bodies, double dt, int count);

int main() {
    const int num_bodies = 3;
    Body bodies[num_bodies];

    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[0].mass = 1.9891e30;

    bodies[1].x = 384400000;
    bodies[1].y = 0;
    bodies[1].vx = 0;
    bodies[1].vy = 1023;
    bodies[1].mass = 5.9722e24;

    bodies[2].x = 149600000000;
    bodies[2].y = 0;
    bodies[2].vx = 0;
    bodies[2].vy = 29.78e3;
    bodies[2].mass = 1.9891e30;

    const double dt = 60 * 60 * 24; // 1 day
    const int num_steps = 365 * 10; // 10 years

    for (int i = 0; i < num_steps; ++i) {
        update_positions(bodies, dt, num_bodies);
        update_velocities(bodies, dt, num_bodies);
    }

    printf("Final positions:\n");
    for (int i = 0; i < num_bodies; ++i) {
        printf("Body %d: x=%f y=%f\n", i, bodies[i].x, bodies[i].y);
    }

    return 0;
}

void update_positions(Body *bodies, double dt, int count) {
    for (int i = 0; i < count; ++i) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

void update_velocities(Body *bodies, double dt, int count) {
    for (int i = 0; i < count; ++i) {
        double ax = 0;
        double ay = 0;

        for (int j = 0; j < count; ++j) {
            if (i == j) continue;

            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dist = sqrt(dx*dx + dy*dy);
            double f = G * bodies[i].mass * bodies[j].mass / (dist*dist);
            ax += f * dx / dist;
            ay += f * dy / dist;
        }

        bodies[i].vx += ax * dt;
        bodies[i].vy += ay * dt;
    }
}