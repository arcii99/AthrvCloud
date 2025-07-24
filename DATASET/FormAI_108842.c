//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.6743e-11 // Gravitational constant
#define MASS_MIN 1e10 // Minimum planet mass
#define MASS_MAX 1e20 // Maximum planet mass
#define POS_MIN -1e12 // Minimum position
#define POS_MAX 1e12 // Maximum position
#define VEL_MIN -1e4 // Minimum velocity
#define VEL_MAX 1e4 // Maximum velocity
#define DT 0.01 // Time step

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} planet;

void simulate(planet *planets, int n) {
    int i, j;
    double dx, dy, dz, r, f;

    // Calculate gravitational forces and update velocities
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            dx = planets[j].x - planets[i].x;
            dy = planets[j].y - planets[i].y;
            dz = planets[j].z - planets[i].z;
            r = sqrt(dx*dx + dy*dy + dz*dz);
            f = G * planets[i].mass * planets[j].mass / (r*r*r);
            planets[i].vx += f * dx / planets[i].mass * DT;
            planets[i].vy += f * dy / planets[i].mass * DT;
            planets[i].vz += f * dz / planets[i].mass * DT;
            planets[j].vx -= f * dx / planets[j].mass * DT;
            planets[j].vy -= f * dy / planets[j].mass * DT;
            planets[j].vz -= f * dz / planets[j].mass * DT;
        }
    }

    // Update positions
    for (i = 0; i < n; i++) {
        planets[i].x += planets[i].vx * DT;
        planets[i].y += planets[i].vy * DT;
        planets[i].z += planets[i].vz * DT;
    }
}

int main() {
    srand(time(NULL));
    int i, n = 10;
    planet planets[n];

    // Randomly generate planets
    for (i = 0; i < n; i++) {
        planets[i].mass = rand() * (MASS_MAX - MASS_MIN) / RAND_MAX + MASS_MIN;
        planets[i].x = rand() * (POS_MAX - POS_MIN) / RAND_MAX + POS_MIN;
        planets[i].y = rand() * (POS_MAX - POS_MIN) / RAND_MAX + POS_MIN;
        planets[i].z = rand() * (POS_MAX - POS_MIN) / RAND_MAX + POS_MIN;
        planets[i].vx = rand() * (VEL_MAX - VEL_MIN) / RAND_MAX + VEL_MIN;
        planets[i].vy = rand() * (VEL_MAX - VEL_MIN) / RAND_MAX + VEL_MIN;
        planets[i].vz = rand() * (VEL_MAX - VEL_MIN) / RAND_MAX + VEL_MIN;
    }

    // Main simulation loop
    for (i = 0; i < 10000; i++) {
        simulate(planets, n);
    }

    // Print final positions
    for (i = 0; i < n; i++) {
        printf("Planet %d: (%f, %f, %f)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}