//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11  // gravitational constant

struct body {
    double mass;
    double x, y;  // position
    double vx, vy;  // velocity
    double fx, fy;  // force
};

int main() {
    int num_bodies = 2;
    struct body bodies[num_bodies];

    bodies[0].mass = 5.97e24;  // mass of Earth
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;

    bodies[1].mass = 7.34e22;  // mass of Moon
    bodies[1].x = 3.84e8;  // distance from Earth
    bodies[1].y = 0;
    bodies[1].vx = 0;
    bodies[1].vy = 1023;  // speed

    double dt = 1;  // time step
    double t = 0;

    while (1) {
        // calculate force on each body
        for (int i = 0; i < num_bodies; i++) {
            double fx = 0;
            double fy = 0;

            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;

                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx*dx + dy*dy);

                double f = G * bodies[i].mass * bodies[j].mass / (r*r);

                fx += f * dx / r;
                fy += f * dy / r;
            }

            bodies[i].fx = fx;
            bodies[i].fy = fy;
        }

        // update position and velocity of each body
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;

            bodies[i].vx += bodies[i].fx / bodies[i].mass * dt;
            bodies[i].vy += bodies[i].fy / bodies[i].mass * dt;
        }

        t += dt;

        // print current position of each body
        for (int i = 0; i < num_bodies; i++) {
            printf("Body %d: position = (%.2f, %.2f)\n", i+1, bodies[i].x, bodies[i].y);
        }

        printf("Time = %.2f\n", t);
    }

    return 0;
}