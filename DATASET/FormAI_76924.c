//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

#define N 5 // number of objects in the system

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass;
} Body;

int main() {

    Body bodies[N];
    double G = 1.0; // gravitational constant
    double dt = 0.01; // time step size
    int steps = 10000; // number of time steps

    // initialize the objects
    bodies[0].x = 0.0; bodies[0].y = 0.0; bodies[0].vx = 0.0; bodies[0].vy = 0.0; bodies[0].mass = 1.0; // Sun
    bodies[1].x = 0.0; bodies[1].y = -1.0; bodies[1].vx = 0.5; bodies[1].vy = 0.0; bodies[1].mass = 0.01; // Mercury
    bodies[2].x = 1.0; bodies[2].y = 0.0; bodies[2].vx = 0.0; bodies[2].vy = 1.0; bodies[2].mass = 1.0; // Earth
    bodies[3].x = 0.0; bodies[3].y = 2.0; bodies[3].vx = -0.5; bodies[3].vy = 0.0; bodies[3].mass = 0.1; // Jupiter
    bodies[4].x = -3.0; bodies[4].y = 0.0; bodies[4].vx = 0.0; bodies[4].vy = -0.5; bodies[4].mass = 0.001; // Pluto

    // simulation loop
    for (int t = 0; t < steps; t++) {

        // calculate forces and update accelerations
        for (int i = 0; i < N; i++) {
            double ax = 0.0, ay = 0.0;
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double dx = bodies[j].x - bodies[i].x;
                    double dy = bodies[j].y - bodies[i].y;
                    double r = sqrt(dx*dx + dy*dy);
                    ax += G * bodies[j].mass / (r*r*r) * dx;
                    ay += G * bodies[j].mass / (r*r*r) * dy;
                }
            }
            bodies[i].ax = ax;
            bodies[i].ay = ay;
        }

        // update velocities and positions
        for (int i = 0; i < N; i++) {
            bodies[i].vx += bodies[i].ax * dt;
            bodies[i].vy += bodies[i].ay * dt;
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
        }
    }

    // print final positions
    printf("Final positions:\n");
    for (int i = 0; i < N; i++) {
        printf("Body %d: (%f, %f)\n", i, bodies[i].x, bodies[i].y);
    }

    return 0;
}