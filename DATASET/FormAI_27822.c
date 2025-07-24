//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11   // Gravitational constant

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} Body;

double dist(Body a, Body b) {
    double x = b.position[0] - a.position[0];
    double y = b.position[1] - a.position[1];
    double z = b.position[2] - a.position[2];
    return sqrt(x * x + y * y + z * z);
}

void calculate_force(Body a, Body b, double *force) {
    double d = dist(a, b);
    double f = G * a.mass * b.mass / (d * d);
    force[0] += f * (b.position[0] - a.position[0]) / d;
    force[1] += f * (b.position[1] - a.position[1]) / d;
    force[2] += f * (b.position[2] - a.position[2]) / d;
}

void update_velocity(Body *a, double *force, double dt) {
    a->velocity[0] += force[0] * dt / a->mass;
    a->velocity[1] += force[1] * dt / a->mass;
    a->velocity[2] += force[2] * dt / a->mass;
}

void update_position(Body *a, double dt) {
    a->position[0] += a->velocity[0] * dt;
    a->position[1] += a->velocity[1] * dt;
    a->position[2] += a->velocity[2] * dt;
}

int main(void) {
    Body planet1 = {5.972e24, {0, 0, 0}, {0, 0, 0}};   // Earth
    Body planet2 = {6.39e23, {384400000, 0, 0}, {0, 1022, 0}};   // Moon
    double dt = 1;   // Time step in seconds

    for (int i = 0; i < 365 * 24; i++) {
        double force1[3] = {0};
        double force2[3] = {0};

        calculate_force(planet1, planet2, force1);
        calculate_force(planet2, planet1, force2);

        update_velocity(&planet1, force1, dt);
        update_velocity(&planet2, force2, dt);

        update_position(&planet1, dt);
        update_position(&planet2, dt);

        printf("Day %d:\n", i + 1);
        printf("Earth: (%.2f, %.2f, %.2f)\n", planet1.position[0], planet1.position[1], planet1.position[2]);
        printf("Moon: (%.2f, %.2f, %.2f)\n", planet2.position[0], planet2.position[1], planet2.position[2]);
    }

    return 0;
}