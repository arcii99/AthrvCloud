//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>
#define G 6.67e-11

struct Planet {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass;
};

void update(struct Planet* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void addForce(struct Planet* p1, struct Planet* p2) {
    double dx = p2->x - p1->x, dy = p2->y - p1->y;
    double d = sqrt(dx*dx + dy*dy);
    double f = G * p1->mass * p2->mass / (d*d);
    p1->ax += f * dx / d / p1->mass;
    p1->ay += f * dy / d / p1->mass;
}

int main() {
    double dt = 0.01;
    int steps = 1000;
    struct Planet earth = {0, 0, 29.784e3, 0, 5.9736e24};
    struct Planet moon = {3.84e8, 0, 0, 1022, 7.342e22};
    for (int i = 0; i < steps; i++) {
        addForce(&earth, &moon);
        addForce(&moon, &earth);
        update(&earth, dt);
        update(&moon, dt);
        printf("%.2f %.2f\n", earth.x/1e6, earth.y/1e6);
    }
    return 0;
}