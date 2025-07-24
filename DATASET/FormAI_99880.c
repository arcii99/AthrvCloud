//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <math.h>

#define G 6.67e-11  // Gravitational constant

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Body;

void update_velocity(Body* b1, Body* b2, double dt) {
    double distance = sqrt(pow(b2->x - b1->x, 2) + pow(b2->y - b1->y, 2));
    double force = G * b1->mass * b2->mass / pow(distance, 2);
    double theta = atan2(b2->y - b1->y, b2->x - b1->x);
    double fx = force * cos(theta);
    double fy = force * sin(theta);
    b1->vx += fx / b1->mass * dt;
    b1->vy += fy / b1->mass * dt;
    b2->vx -= fx / b2->mass * dt;
    b2->vy -= fy / b2->mass * dt;
}

void update_position(Body* b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

void print_body(Body* b) {
    printf("Mass: %lf\tPosition: (%lf, %lf)\tVelocity: (%lf, %lf)\n",
           b->mass, b->x, b->y, b->vx, b->vy);
}

int main() {
    Body sun = {1.989e30, 0, 0, 0, 0};
    Body earth = {5.972e24, 1.5e11, 0, 0, 2.9783e4};
    double dt = 1e3;  // Time step in seconds
    for (int i = 0; i < 365; i++) {
        update_velocity(&sun, &earth, dt);
        update_position(&earth, dt);
        print_body(&earth);
    }
    return 0;
}