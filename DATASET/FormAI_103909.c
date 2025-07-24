//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67430e-11   // Gravitational constant

typedef struct {
    double x, y;  // Position
    double vx, vy;  // Velocity
    double mass;  // Mass
} Body;

Body bodies[] = {  // Sample bodies
    {0, 0, 0, 0, 5.97e24},
    {6378000, 0, 0, 7700, 1},
    {6478000, 0, 0, 7000, 1000},
    {6478000, 0, 0, 7000, 10},
    {6478000, 0, 0, 7000, 0.1}
};
const int N_BODIES = sizeof(bodies) / sizeof(bodies[0]);

void calculate_forces(Body *bodies, double dt) {
    for (int i = 0; i < N_BODIES; i++) {
        Body *b1 = &bodies[i];
        double fx = 0, fy = 0;  // Total forces
        for (int j = 0; j < N_BODIES; j++) {
            if (i == j) continue;
            Body *b2 = &bodies[j];
            double dx = b2->x - b1->x;
            double dy = b2->y - b1->y;
            double dist = sqrt(dx * dx + dy * dy);
            double f = GRAV_CONST * (b1->mass * b2->mass) / (dist * dist);
            fx += f * dx / dist;
            fy += f * dy / dist;
        }
        // Update velocity
        b1->vx += fx / b1->mass * dt;
        b1->vy += fy / b1->mass * dt;
    }
}

void update_positions(Body *bodies, double dt) {
    for (int i = 0; i < N_BODIES; i++) {
        Body *b = &bodies[i];
        b->x += b->vx * dt;
        b->y += b->vy * dt;
    }
}

int main() {
    double dt = 1;  // Time step
    int n_steps = 1000;  // Number of steps
    for (int i = 0; i < N_BODIES; i++) {
        printf("Body %d: mass = %.2e, velocity = (%.2e, %.2e)\n", i, bodies[i].mass, bodies[i].vx, bodies[i].vy);
    }
    for (int i = 0; i < n_steps; i++) {
        calculate_forces(bodies, dt);
        update_positions(bodies, dt);
    }
    for (int i = 0; i < N_BODIES; i++) {
        printf("Body %d: position = (%.2f, %.2f)\n", i, bodies[i].x, bodies[i].y);
    }
    return 0;
}