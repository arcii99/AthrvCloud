//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include <stdio.h>
#include <math.h>
#define G 6.673e-11 // Gravitational Constant
#define MASS_OF_SUN 1.989e+30 // Mass of Sun
#define AU 149.6e+9 // 1 Astronomical Unit
#define YEAR_LEN 365.25636 // Length of a Gregorian year in days

typedef struct {
    double x, y; // position in m
    double vx, vy; // velocity in m/s
    double ax, ay; // acceleration in m/s^2
    double mass; // mass in kg
} Body;

void update_velocity(Body *body, double dt, Body *bodies, int n) {
    double fx = 0.0, fy = 0.0;
    for (int i = 0; i < n; i++) {
        if (body != &bodies[i]) {
            double dx = bodies[i].x - body->x;
            double dy = bodies[i].y - body->y;
            double distance = sqrt(dx*dx + dy*dy);
            double force = G * body->mass * bodies[i].mass / (distance * distance);
            fx += force * dx / distance;
            fy += force * dy / distance;
        }
    }
    body->ax = fx / body->mass;
    body->ay = fy / body->mass;
    body->vx += body->ax * dt;
    body->vy += body->ay * dt;
}

void update_position(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

void simulate(double dt, Body *bodies, int n, int steps) {
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < n; i++) {
            update_velocity(&bodies[i], dt, bodies, n);
        }
        for (int i = 0; i < n; i++) {
            update_position(&bodies[i], dt);
        }
    }
}

int main() {
    // define the bodies in the Solar System
    Body sun = {0.0, 0.0, 0.0, 0.0, 0.0, MASS_OF_SUN};
    Body earth = {AU, 0.0, 0.0, 29783.0, 0.0, 5.972e+24};
    // simulate the Solar System for a year
    double dt = 60.0; // time step in seconds
    int steps = (int) (YEAR_LEN * 24 * 3600 / dt); // number of steps in a year
    Body bodies[] = {sun, earth};
    simulate(dt, bodies, 2, steps);
    // print the final positions of the planets
    printf("Final position of Sun: (%.3e, %.3e) m\n", sun.x, sun.y);
    printf("Final position of Earth: (%.3e, %.3e) m\n", earth.x, earth.y);
    return 0;
}