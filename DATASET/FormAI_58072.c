//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant

typedef struct {
    double x, y;
    double vx, vy;
    double mass;
} Body;

void update_positions(Body* bodies, int size, double dt) {
    int i, j;
    for (i = 0; i < size; i++) {
        Body* b1 = &bodies[i];
        double Fx = 0.0, Fy = 0.0;
        for (j = 0; j < size; j++) {
            if (i != j) {
                Body* b2 = &bodies[j];
                double dx = b2->x - b1->x;
                double dy = b2->y - b1->y;
                double distance = sqrt(dx * dx + dy * dy);
                double force = G * b1->mass * b2->mass / (distance * distance);
                Fx += force * dx / distance;
                Fy += force * dy / distance;
            }
        }
        b1->vx += Fx * dt / b1->mass;
        b1->vy += Fy * dt / b1->mass;
        b1->x += b1->vx * dt;
        b1->y += b1->vy * dt;
    }
}

int main() {
    Body bodies[] = {
        {0.0, 0.0, 0.0, 0.0, 5.9736e+24}, // Earth
        {384400000.0, 0.0, 0.0, -1022.0, 7.3420e+22} // Moon
    };
    int size = sizeof(bodies) / sizeof(Body);
    double dt = 60.0; // timestep
    int steps = 86400 * 30; // simulation length (30 days)

    int i;
    for (i = 0; i < steps; i++) {
        update_positions(bodies, size, dt);
    }

    printf("Earth's position: (%.2f, %.2f)\n", bodies[0].x, bodies[0].y);
    printf("Moon's position: (%.2f, %.2f)\n", bodies[1].x, bodies[1].y);

    return 0;
}