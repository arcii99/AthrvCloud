//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // Universal Gravitational Constant
#define MASS 5.97e24 // Mass of earth
#define RADIUS 6.371e6 // Radius of earth

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

typedef struct Vector {
    double x;
    double y;
    double z;
} Vector;

typedef struct Body {
    Point position;
    Vector velocity;
    double mass;
} Body;

Body bodies[] = {
    {
        {0, 0, 0},
        {0, 0, 0},
        MASS // earth
    },
    {
        {100000, 0, 0},
        {0, sqrt(G * MASS / 100000), 0},
        1 // test body
    }
};

const int NUM_BODIES = sizeof(bodies) / sizeof(Body);

double distance(Point *p1, Point *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Vector force(Body *b1, Body *b2) {
    Vector f = {0, 0, 0};
    double r = distance(&b1->position, &b2->position);
    double m1 = b1->mass;
    double m2 = b2->mass;
    f.x = G * ((m1 * m2) / pow(r, 2)) * ((b2->position.x - b1->position.x) / r);
    f.y = G * ((m1 * m2) / pow(r, 2)) * ((b2->position.y - b1->position.y) / r);
    f.z = G * ((m1 * m2) / pow(r, 2)) * ((b2->position.z - b1->position.z) / r);
    return f;
}

void update_velocities_and_positions(double dt) {
    Vector forces[NUM_BODIES];
    for (int i = 0; i < NUM_BODIES; i++) {
        Body *b1 = &bodies[i];
        Vector f = {0, 0, 0};
        for (int j = 0; j < NUM_BODIES; j++) {
            if (i == j) continue;
            Body *b2 = &bodies[j];
            Vector f_d = force(b1, b2);
            f.x += f_d.x;
            f.y += f_d.y;
            f.z += f_d.z;
        }
        forces[i] = f;
    }
    for (int i = 0; i < NUM_BODIES; i++) {
        Body *b = &bodies[i];
        Vector f = forces[i];
        b->velocity.x += f.x * dt / b->mass;
        b->velocity.y += f.y * dt / b->mass;
        b->velocity.z += f.z * dt / b->mass;
        b->position.x += b->velocity.x * dt;
        b->position.y += b->velocity.y * dt;
        b->position.z += b->velocity.z * dt;
    }
}

int main() {
    double dt = 0.1;
    double total_time = 100;
    int steps = total_time / dt;
    for (int i = 0; i < steps; i++) {
        printf("Step %d:\n", i);
        for (int j = 0; j < NUM_BODIES; j++) {
            Body b = bodies[j];
            printf("   Body %d: (%.2f, %.2f, %.2f)\n", j+1, b.position.x, b.position.y, b.position.z);
        }
        update_velocities_and_positions(dt);
    }
    return 0;
}