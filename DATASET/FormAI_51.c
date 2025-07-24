//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11    // Gravitational constant

typedef struct {
    double x, y;        // Position
    double vx, vy;      // Velocity
    double ax, ay;      // Acceleration
    double m;           // Mass
} body;

void update_acc(body *b, body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        if (b == &bodies[i]) continue;

        double dx = bodies[i].x - b->x;
        double dy = bodies[i].y - b->y;
        double d = sqrt(dx*dx + dy*dy);
        double f = G * b->m * bodies[i].m / (d*d);
        b->ax += f / b->m * dx / d;
        b->ay += f / b->m * dy / d;
    }
}

void update_vel_pos(body *b, double dt) {
    b->vx += b->ax * dt;
    b->vy += b->ay * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

void simulate(body *bodies, int n, double t, double dt) {
    for (double time = 0; time < t; time += dt) {
        for (int i = 0; i < n; i++) {
            update_acc(&bodies[i], bodies, n);
        }
        for (int i = 0; i < n; i++) {
            update_vel_pos(&bodies[i], dt);
        }
    }
}

int main() {
    // Body initialization
    body bodies[] = {
        {0, 0, 0, 0, 0, 1e5},
        {0, 10, 100, 0, 1, 1},
        {10, 0, 0, 100, 1, 1},
        {0, -10, -100, 0, 1, 1},
        {-10, 0, 0, -100, 1, 1}
    };
    int n = sizeof(bodies) / sizeof(body);

    simulate(bodies, n, 10, 0.001);

    // Print final positions
    for (int i = 0; i < n; i++) {
        printf("Body %d: (%f, %f)\n", i, bodies[i].x, bodies[i].y);
    }

    return 0;
}