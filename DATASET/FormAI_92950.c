//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define DELTA_T 1 // time step
#define NUM_PLANETS 4 // number of planets

typedef struct {
    char name[20];
    double mass;
    double x, y, z; // position
    double vx, vy, vz; // velocity
} Planet;

int main() {
    Planet planets[NUM_PLANETS] = {
        {"Earth", 5.97e24, 0, 0, 0, 0, 0, 0},
        {"Moon", 7.34e22, 3.84e8, 0, 0, 0, 1022, 0},
        {"Mars", 6.39e23, 2.28e11, 0, 0, 0, 0, 24130},
        {"Jupiter", 1.9e27, 7.78e11, 0, 0, 0, 0, 13052}
    };

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s position: (%.2e, %.2e, %.2e)\n", 
            planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    for (int i = 0; i < 1000; i++) { // simulate for 1000 time steps
        for (int j = 0; j < NUM_PLANETS; j++) {
            double ax = 0, ay = 0, az = 0; // acceleration
            for (int k = 0; k < NUM_PLANETS; k++) {
                if (j == k) continue;
                double dx = planets[k].x - planets[j].x;
                double dy = planets[k].y - planets[j].y;
                double dz = planets[k].z - planets[j].z;
                double d = sqrt(dx * dx + dy * dy + dz * dz); // distance
                double f = G * planets[j].mass * planets[k].mass / (d * d); // force
                ax += f * dx / d / planets[j].mass;
                ay += f * dy / d / planets[j].mass;
                az += f * dz / d / planets[j].mass;
            }
            planets[j].vx += ax * DELTA_T;
            planets[j].vy += ay * DELTA_T;
            planets[j].vz += az * DELTA_T;
            planets[j].x += planets[j].vx * DELTA_T;
            planets[j].y += planets[j].vy * DELTA_T;
            planets[j].z += planets[j].vz * DELTA_T;
        }
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s position: (%.2e, %.2e, %.2e)\n", 
            planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}