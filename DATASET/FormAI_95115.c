//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant
#define DT 0.1 // Time step

typedef struct {
    double x, y;
    double vx, vy;
    double ax, ay;
    double mass;
} Body;

void update_acc(Body *bodies, int n) {
    int i, j;
    double dx, dy, dist, f;

    for (i = 0; i < n; i++) {
        bodies[i].ax = bodies[i].ay = 0.0;
        for (j = 0; j < n; j++) {
            if (i == j) continue;

            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dist = sqrt(dx*dx + dy*dy);
            f = G * bodies[i].mass * bodies[j].mass / (dist*dist);

            bodies[i].ax += f * dx / dist / bodies[i].mass;
            bodies[i].ay += f * dy / dist / bodies[i].mass;
        }
    }
}

void update_vel_pos(Body *bodies, int n, double dt) {
    int i;

    for (i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;

        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

int main() {
    Body bodies[] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}, // Central body
        {10.0, 0.0, 0.0, 30.0, 0.0, 0.0, 0.01}, // Small body in orbit
        {20, 0, 0, -15, 0, 0, 0.01} // Small body in opposite orbit
    };
    int n_bodies = sizeof(bodies) / sizeof(*bodies);

    double t;
    for (t = 0; t < 50; t += DT) {
        update_acc(bodies, n_bodies);
        update_vel_pos(bodies, n_bodies, DT);

        printf("%.1f: (%.3f, %.3f)\n", t, bodies[1].x, bodies[1].y);
    }

    return 0;
}