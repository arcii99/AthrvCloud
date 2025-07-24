//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11    // gravitational constant

typedef struct {
    double x, y;
    double vx, vy;
    double ax, ay;
    double mass;
} Body;

void update_velocity(Body *b1, Body *b2, double dt) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dist = sqrt(dx*dx + dy*dy);
    double f = G * b1->mass * b2->mass / (dist * dist);
    double fx = f * dx / dist;
    double fy = f * dy / dist;
    b1->vx += fx / b1->mass * dt;
    b1->vy += fy / b1->mass * dt;
    b2->vx -= fx / b2->mass * dt;
    b2->vy -= fy / b2->mass * dt;
}

void update_position(Body *b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

void update_acceleration(Body *b, double ax, double ay) {
    b->ax = ax;
    b->ay = ay;
}

int main() {
    Body planet1 = {1.0, 0.0, 0.0, 7000.0, 0.0, 0.0, 5.97e24};
    Body planet2 = {-1.0, 0.0, 0.0, -7000.0, 0.0, 0.0, 5.97e24};
    Body planet3 = {0.0, 1.0, -5000.0, 0.0, 0.0, 0.0, 1.0e12};
    Body planet4 = {0.0, -1.0, 5000.0, 0.0, 0.0, 0.0, 1.0e12};
    Body bodies[] = {planet1, planet2, planet3, planet4};
    int num_bodies = sizeof(bodies) / sizeof(Body);
    double dt = 0.01;

    while (1) {
        for (int i = 0; i < num_bodies; i++) {
            Body *b = &bodies[i];
            double ax = 0.0;
            double ay = 0.0;
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    Body *b2 = &bodies[j];
                    update_velocity(b, b2, dt);
                }
            }
            update_position(b, dt);
            update_acceleration(b, ax, ay);
        }
        printf("Planet 1: x=%lf, y=%lf\n", planet1.x, planet1.y);
        printf("Planet 2: x=%lf, y=%lf\n", planet2.x, planet2.y);
        printf("Planet 3: x=%lf, y=%lf\n", planet3.x, planet3.y);
        printf("Planet 4: x=%lf, y=%lf\n", planet4.x, planet4.y);
    }

    return 0;
}