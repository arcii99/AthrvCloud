//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: careful
#include <stdio.h>
#include <math.h>

#define G 6.67e-11   // gravitational constant

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double mass; // mass
} Planet;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_acceleration(Planet* p1, Planet* p2) {
    double d = distance(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);
    double f = G * p1->mass * p2->mass / (d*d);
    double fx = f * (p2->x - p1->x) / d;
    double fy = f * (p2->y - p1->y) / d;
    double fz = f * (p2->z - p1->z) / d;
    p1->ax += fx / p1->mass;
    p1->ay += fy / p1->mass;
    p1->az += fz / p1->mass;
    p2->ax -= fx / p2->mass;
    p2->ay -= fy / p2->mass;
    p2->az -= fz / p2->mass;
}

void update_velocity(Planet* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
}

void update_position(Planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    Planet planets[] = {
        {1.0e11, 0, 0, 0, 3.0e4, 0, 0, 0, 0, 5.97e24},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1.99e30},
        {0, 1.5e11, 0, -3.0e4, 0, 0, 0, 0, 0, 5.97e24}
    };
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    double dt = 60 * 60 * 24; // time step (seconds)

    for (int i = 0; i < num_planets; i++) {
        for (int j = i + 1; j < num_planets; j++) {
            update_acceleration(&planets[i], &planets[j]);
        }
    }

    for (int i = 0; i < num_planets; i++) {
        update_velocity(&planets[i], dt);
    }

    for (int i = 0; i < num_planets; i++) {
        update_position(&planets[i], dt);
        printf("Planet %d: (%f, %f, %f)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}