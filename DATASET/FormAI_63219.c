//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <math.h>

#define GRAV_CONSTANT 6.6743e-11 // the gravitational constant

typedef struct {
    double x, y; // position of the planet
    double vx, vy; // velocity of the planet
    double mass; // mass of the planet
} planet;

/**
 * Computes the distance between two planets.
 */
double distance(planet* a, planet* b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    return sqrt(dx*dx + dy*dy);
}

/**
 * Calculates the force on `a` due to `b`.
 */
double force(planet* a, planet* b) {
    double dist = distance(a, b);
    return GRAV_CONSTANT * a->mass * b->mass / (dist*dist);
}

/**
 * Updates the velocities and positions of two planets `a` and `b`,
 * based on the gravitational forces between them.
 */
void update(planet* a, planet* b, double dt) {
    double f = force(a, b);
    double theta = atan2(b->y - a->y, b->x - a->x);
    double ax = f * cos(theta) / a->mass;
    double ay = f * sin(theta) / a->mass;
    double bx = f * cos(theta + M_PI) / b->mass;
    double by = f * sin(theta + M_PI) / b->mass;
    a->vx += ax * dt;
    a->vy += ay * dt;
    b->vx += bx * dt;
    b->vy += by * dt;
    a->x += a->vx * dt;
    a->y += a->vy * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

/**
 * Runs a simulation for `n` time steps of duration `dt`,
 * with an array of `num_planets` planets.
 */
void simulate(int n, double dt, int num_planets, planet* planets) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < num_planets; j++) {
            for (int k = 0; k < num_planets; k++) {
                if (j != k) {
                    update(&planets[j], &planets[k], dt);
                }
            }
        }
    }
}

int main() {
    planet planets[] = {
        {0, 0, 0, 0, 5.97e24}, // Earth
        {384400000, 0, 0, 1022, 7.35e22} // Moon
    };
    simulate(100, 1000, 2, planets);
    return 0;
}