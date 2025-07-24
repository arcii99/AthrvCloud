//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double mass;
} Body;

Body bodies[] = {
    // x     y     z    vx   vy   vz    mass
    { 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 5.97219e24 },
    { 0.0, 6371000.0, 0.0,  7900.0, 0.0, 0.0, 1000.0 }
};

const int num_bodies = sizeof(bodies) / sizeof(Body);

void print_state() {
    for (int i = 0; i < num_bodies; i++) {
        Body b = bodies[i];
        printf("Body %d: x=%e, y=%e, z=%e\n", i+1, b.x, b.y, b.z);
    }
}

double distance(Body a, Body b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double force(Body a, Body b) {
    double dist = distance(a, b);
    return G * a.mass * b.mass / (dist * dist);
}

void update_velocities() {
    for (int i = 0; i < num_bodies; i++) {
        Body a = bodies[i];
        double fx = 0.0, fy = 0.0, fz = 0.0;
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            Body b = bodies[j];
            double f = force(a, b);
            double dx = a.x - b.x;
            double dy = a.y - b.y;
            double dz = a.z - b.z;
            double dist = distance(a, b);
            fx -= f * dx / dist;
            fy -= f * dy / dist;
            fz -= f * dz / dist;
        }
        double ax = fx / a.mass;
        double ay = fy / a.mass;
        double az = fz / a.mass;
        a.vx += ax;
        a.vy += ay;
        a.vz += az;
    }
}

void update_positions() {
    for (int i = 0; i < num_bodies; i++) {
        Body b = bodies[i];
        b.x += b.vx;
        b.y += b.vy;
        b.z += b.vz;
    }
}

int main() {
    printf("Initial State:\n");
    print_state();

    // Update state over time
    for (int step = 1; step <= 100; step++) {
        printf("\nStep %d:\n", step);
        update_velocities();
        update_positions();
        print_state();
    }

    return 0;
}