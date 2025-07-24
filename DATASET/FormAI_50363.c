//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11         // gravitational constant

typedef struct {
    double x;                // x-coordinate
    double y;                // y-coordinate
    double vx;               // x-velocity
    double vy;               // y-velocity
    double ax;               // x-acceleration
    double ay;               // y-acceleration
    double mass;             // mass
} Body;

void update_acceleration(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        double ax = 0.0;
        double ay = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx * dx + dy * dy);
                double f = G * bodies[i].mass * bodies[j].mass / (r * r);
                ax += f * dx / r;
                ay += f * dy / r;
            }
        }
        bodies[i].ax = ax;
        bodies[i].ay = ay;
    }
}

void update_velocity(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;
    }
}

void update_position(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

int main() {
    Body bodies[] = {
        {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0},    // body 1
        {-1.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.0}   // body 2
    };
    int n = sizeof(bodies) / sizeof(Body);
    double dt = 0.01;
    int timesteps = 100;
    for (int t = 0; t < timesteps; t++) {
        update_acceleration(bodies, n);
        update_velocity(bodies, n, dt);
        update_position(bodies, n, dt);
        printf("t = %d\n", t);
        for (int i = 0; i < n; i++) {
            printf("%d: (%lf, %lf)\n", i + 1, bodies[i].x, bodies[i].y);
        }
    }
    return 0;
}