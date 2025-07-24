//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

// Constants
#define G 6.6743e-11  // gravitational constant

// Structures
typedef struct {
    double x, y, z;  // position vector components
    double vx, vy, vz;  // velocity vector components
    double ax, ay, az;  // acceleration vector components
    double mass;  // mass of the planet
} Planet;

// Function prototypes
void update_position(Planet *p, double dt);
void update_velocity(Planet *p, double dt);
void update_acceleration(Planet *p, Planet *others, int num_others);

int main() {
    // Initialization
    const double dt = 3600;  // time step in seconds
    const int num_iterations = 1000;  // number of iterations
    const int num_planets = 4;
    Planet planets[num_planets];

    // Planet information
    Planet earth = { .x = 0, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .mass = 5.97e24 };
    Planet mars = { .x = 227.9e9, .y = 0, .z = 0, .vx = 0, .vy = 24.077e3, .vz = 0, .mass = 6.39e23 };
    Planet venus = { .x = 0, .y = 108.2e9, .z = 0, .vx = -35.03e3, .vy = 0, .vz = 0, .mass = 4.87e24 };
    Planet mercury = { .x = 0, .y = 0, .z = 46e9, .vx = 58.98e3, .vy = 0, .vz = 0, .mass = 3.30e23 };
    planets[0] = earth;
    planets[1] = mars;
    planets[2] = venus;
    planets[3] = mercury;

    for (int i = 0; i < num_iterations; i++) {
        // Update acceleration of each planet
        for (int j = 0; j < num_planets; j++) {
            update_acceleration(&planets[j], planets, num_planets);
        }

        // Update positions and velocities of each planet
        for (int j = 0; j < num_planets; j++) {
            update_position(&planets[j], dt);
            update_velocity(&planets[j], dt);
        }
    }

    // Print final positions of each planet
    for (int j = 0; j < num_planets; j++) {
        Planet p = planets[j];
        printf("Planet #%d: x=%e y=%e z=%e\n", j+1, p.x, p.y, p.z);
    }

    return 0;
}

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void update_velocity(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_acceleration(Planet *p, Planet *others, int num_others) {
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
    for (int i = 0; i < num_others; i++) {
        if (p != &others[i]) {
            double dx = others[i].x - p->x;
            double dy = others[i].y - p->y;
            double dz = others[i].z - p->z;
            double r = sqrt(dx*dx + dy*dy + dz*dz);
            double f = G * p->mass * others[i].mass / (r*r);
            p->ax += f * dx / r / p->mass;
            p->ay += f * dy / r / p->mass;
            p->az += f * dz / r / p->mass;
        }
    }
}