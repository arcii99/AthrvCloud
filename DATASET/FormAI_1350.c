//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#define G 6.67408e-11

struct Body {
    double x, y, z;
    double vx, vy, vz;
    double m;
};
typedef struct Body Body;

void update_velocities(Body* a, Body* b, double dt) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    double dz = a->z - b->z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * a->m * b->m / (dist*dist);
    double f1 = force / a->m;
    double f2 = force / b->m;
    a->vx -= f1 * dx / dist * dt;
    a->vy -= f1 * dy / dist * dt;
    a->vz -= f1 * dz / dist * dt;
    b->vx += f2 * dx / dist * dt;
    b->vy += f2 * dy / dist * dt;
    b->vz += f2 * dz / dist * dt;
}

void update_positions(Body* body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

void simulate(Body* bodies, int n, double dt, int steps) {
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                update_velocities(&bodies[i], &bodies[j], dt);
            }
        }
        for (int i = 0; i < n; i++) {
            update_positions(&bodies[i], dt);
        }
    }
}

int main() {
    Body bodies[] = {
        {0, 0, 0, 0, 0, 0, 1.989e30}, // sun
        {0, -1.48e11, 0, 3e4, 0, 0, 5.97e24}, // earth
        {0, 0, 2.28e11, -2.9e4, 0, 0, 6.39e23}, // mars
        {0, 1.08e11, 0, -5.5e4, 0, 0, 3.3e23}, // mercery
        {0, 0, -1.45e11, -4.8e4, 0, 0, 4.87e24}, // venus
        {0, 0, 7.78e11, 3e4, 0, 0, 1.9e27}, // jupitor
        {0, 0, 1.43e12, 2.4e4, 0, 0, 5.68e26} // saturn
    };
    int n = sizeof(bodies) / sizeof(Body);
    double dt = 86400; // one day in seconds
    int steps = 365; // one year
    simulate(bodies, n, dt, steps);

    printf("Simulated solar system after one year:\n");
    for (int i = 0; i < n; i++) {
        printf("Body %d: x=%.2f y=%.2f z=%.2f\n", i+1, bodies[i].x, bodies[i].y, bodies[i].z);
    }
    return 0;
}