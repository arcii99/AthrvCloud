//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define TIMESTEP 3600 // timestep in seconds
#define MAX_TIME 31536000 // maximum simulation time in seconds

#define NUM_PLANETS 3 // number of planets

struct planet {
    double mass;
    double x, y, z; // position
    double vx, vy, vz; // velocity
};

struct planet planets[NUM_PLANETS] = {
    { 5.97e24, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }, // Earth
    { 3.30e23, 1.5e11, 0.0, 0.0, 0.0, 30000.0, 0.0 }, // Jupiter
    { 6.39e23, 0.0, 3.84e8, 0.0, 1022.0, 0.0, 0.0 } // Moon
};

void compute_acceleration(int i, double ax, double ay, double az) {
    int j;
    double dx, dy, dz;
    double r, f;

    for (j = 0; j < NUM_PLANETS; j++) {
        if (i == j) {
            continue;
        }
        dx = planets[j].x - planets[i].x;
        dy = planets[j].y - planets[i].y;
        dz = planets[j].z - planets[i].z;
        r = sqrt(dx * dx + dy * dy + dz * dz);
        f = G * planets[j].mass / (r * r);
        ax += f * dx / r;
        ay += f * dy / r;
        az += f * dz / r;
    }

    planets[i].vx += ax * TIMESTEP;
    planets[i].vy += ay * TIMESTEP;
    planets[i].vz += az * TIMESTEP;
}

int main(int argc, char *argv[]) {

    double t = 0.0;
    int i;

    while (t < MAX_TIME) {
        for (i = 0; i < NUM_PLANETS; i++) {
            double ax = 0.0, ay = 0.0, az = 0.0;
            compute_acceleration(i, ax, ay, az);
            planets[i].x += planets[i].vx * TIMESTEP;
            planets[i].y += planets[i].vy * TIMESTEP;
            planets[i].z += planets[i].vz * TIMESTEP;
        }
        t += TIMESTEP;
    }

    return 0;
}