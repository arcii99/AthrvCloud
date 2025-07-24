//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11  // gravitational constant

typedef struct {
    double x, y, z;   // position
    double vx, vy, vz; // velocity
    double mass;       // mass
} planet;

int main(int argc, char **argv) {
    planet planets[] = {
        {0, 0, 0, 0, 0, 0, 5.972e24},  // Earth
        {0, 384400e3, 0, 1022, 0, 0, 7.3477e22},  // Moon
        {-77850000000, 0, 0, 0, -31000, 0, 1.898e27},  // Jupiter
        {0, -151450000000, 0, -23704, 0, 0, 5.683e26}   // Saturn
    };
    int num_planets = sizeof(planets) / sizeof(planet);

    double dt = 3600;            // time step (in seconds)
    int num_steps = 24 * 365;    // number of time steps
    int i, j, k;

    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < num_planets; j++) {
            double ax = 0, ay = 0, az = 0;
            for (k = 0; k < num_planets; k++) {
                if (j != k) {
                    double dx = planets[k].x - planets[j].x;
                    double dy = planets[k].y - planets[j].y;
                    double dz = planets[k].z - planets[j].z;
                    double r = sqrt(dx*dx + dy*dy + dz*dz);
                    double force = G * planets[j].mass * planets[k].mass / (r*r);
                    ax += force * dx / r / planets[j].mass;
                    ay += force * dy / r / planets[j].mass;
                    az += force * dz / r / planets[j].mass;
                }
            }
            planets[j].vx += ax * dt;
            planets[j].vy += ay * dt;
            planets[j].vz += az * dt;
            planets[j].x += planets[j].vx * dt;
            planets[j].y += planets[j].vy * dt;
            planets[j].z += planets[j].vz * dt;
        }
    }

    for (i = 0; i < num_planets; i++) {
        printf("%f %f %f\n", planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}