//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define TIME_STEP 100 // Time step of the simulation in seconds

typedef struct {
    double x, y, z; // Position of the planet
    double vx, vy, vz; // Velocity of the planet
    double mass; // Mass of the planet
} Planet;

void update_velocity(Planet *p1, Planet *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);

    double force = G * p1->mass * p2->mass / (distance*distance);
    double fx = force * dx / distance;
    double fy = force * dy / distance;
    double fz = force * dz / distance;

    p1->vx -= fx / p1->mass * TIME_STEP;
    p1->vy -= fy / p1->mass * TIME_STEP;
    p1->vz -= fz / p1->mass * TIME_STEP;

    p2->vx += fx / p2->mass * TIME_STEP;
    p2->vy += fy / p2->mass * TIME_STEP;
    p2->vz += fz / p2->mass * TIME_STEP;
}

void update_position(Planet *p) {
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
    p->z += p->vz * TIME_STEP;
}

int main() {
    Planet planets[3] = {
        {.x = 1e11, .y = 0, .z = 0, .vx = 0, .vy = 30e3, .vz = 0, .mass = 1e24},
        {.x = 0, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .mass = 5.97e24},
        {.x = -1e11, .y = 0, .z = 0, .vx = 0, .vy = -30e3, .vz = 0, .mass = 1e24},
    };

    int time = 0;
    while (time < 86400 * 365 * 2) { // 2 years
        // Update velocities of all pairs of planets
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 3; j++) {
                update_velocity(&planets[i], &planets[j]);
            }
        }

        // Update positions of all planets
        for (int i = 0; i < 3; i++) {
            update_position(&planets[i]);
        }

        time += TIME_STEP;
    }

    // Print final positions of all planets
    for (int i = 0; i < 3; i++) {
        printf("Planet %d: %f %f %f\n", i, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}