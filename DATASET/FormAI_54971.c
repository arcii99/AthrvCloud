//FormAI DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define PI 3.141592654

int main() {
    double mass = 1.0; // mass of the body
    double radius = 1.0; // radius of the body
    double density = 1.0; // density of the body
    double G = 6.67430e-11; // gravitational constant
    double timestep = 0.001; // simulation timestep
    int iterations = 10000; // number of iterations to simulate

    double x = 0.0, y = 10.0, vx = 3.0, vy = 0.0; // initial position and velocity of the body

    double fx, fy, ax, ay; // forces and accelerations

    double distance, force; // variables used in force calculation

    double fx_total, fy_total; // total forces

    for (int i = 0; i < iterations; i++) {
        fx_total = fy_total = 0.0;

        // calculate gravitational forces on the body
        for (double angle = 0.0; angle < 2.0 * PI; angle += PI / 1000.0) {
            double dx = cos(angle) * radius;
            double dy = sin(angle) * radius;
            distance = sqrt((x + dx) * (x + dx) + (y + dy) * (y + dy));
            force = G * mass * density * 2.0 * PI * radius * dx / distance / distance / distance;
            fx = force * dx / distance;
            fy = force * dy / distance;
            fx_total += fx;
            fy_total += fy;
        }

        // calculate acceleration and velocity
        ax = fx_total / mass;
        ay = fy_total / mass;
        vx += ax * timestep;
        vy += ay * timestep;

        // update position
        x += vx * timestep;
        y += vy * timestep;

        // print position for every 1000th iteration
        if (i % 1000 == 0) {
            printf("Iteration %d: (%f, %f)\n", i, x, y);
        }
    }

    return 0;
}