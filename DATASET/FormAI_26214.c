//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define G 6.674e-11   // Gravitational constant
#define DT 86400   // Time step in seconds (1 day)
#define YEARS 100   // Number of years to simulate
#define N 3   // Number of planets

typedef struct {
    double x;   // x position
    double y;   // y position
    double z;   // z position
    double vx;   // x velocity
    double vy;   // y velocity
    double vz;   // z velocity
    double mass;   // mass
} Planet;

int main() {
    Planet planets[N];

    // Initialize planets
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].z = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].vz = 0.0;
    planets[0].mass = 1.989e30;   // Sun

    planets[1].x = 1.496e11;
    planets[1].y = 0.0;
    planets[1].z = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = 2.978e4;
    planets[1].vz = 0.0;
    planets[1].mass = 5.972e24;   // Earth

    planets[2].x = 2.279e11;
    planets[2].y = 0.0;
    planets[2].z = 0.0;
    planets[2].vx = 0.0;
    planets[2].vy = 2.413e4;
    planets[2].vz = 0.0;
    planets[2].mass = 6.39e23;   // Mars

    // Simulation loop
    for (int year = 0; year < YEARS; year++) {

        // Calculate gravitational force between all pairs of planets
        double fx[N], fy[N], fz[N];
        for (int i = 0; i < N; i++) {
            fx[i] = 0.0;
            fy[i] = 0.0;
            fz[i] = 0.0;
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double dx = planets[j].x - planets[i].x;
                    double dy = planets[j].y - planets[i].y;
                    double dz = planets[j].z - planets[i].z;
                    double r = sqrt(dx*dx + dy*dy + dz*dz);
                    double f = G * planets[i].mass * planets[j].mass / (r*r);
                    fx[i] += f * dx / r;
                    fy[i] += f * dy / r;
                    fz[i] += f * dz / r;
                }
            }
        }

        // Update positions and velocities of all planets
        for (int i = 0; i < N; i++) {
            double ax = fx[i] / planets[i].mass;
            double ay = fy[i] / planets[i].mass;
            double az = fz[i] / planets[i].mass;
            planets[i].vx += ax * DT;
            planets[i].vy += ay * DT;
            planets[i].vz += az * DT;
            planets[i].x += planets[i].vx * DT;
            planets[i].y += planets[i].vy * DT;
            planets[i].z += planets[i].vz * DT;
        }

        // Print positions and velocities of all planets
        printf("Year %d:\n", year+1);
        for (int i = 0; i < N; i++) {
            printf("Planet %d: x = %.2e m, y = %.2e m, z = %.2e m, vx = %.2e m/s, vy = %.2e m/s, vz = %.2e m/s\n",
            i+1, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
        }
    }

    return 0;
}