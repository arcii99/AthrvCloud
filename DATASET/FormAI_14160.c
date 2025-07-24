//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define G 6.67e-11       // Gravitational constant
#define DELTA_TIME 1000   // Time-step in milliseconds
#define NUM_PLANETS 3     // Number of planets in simulation
#define NUM_STEPS 10000   // Number of time-steps in simulation

typedef struct {
    double x;   // x-coordinate
    double y;   // y-coordinate
    double vx;  // x-velocity
    double vy;  // y-velocity
    double m;   // mass
} Planet;

void simulate(Planet planets[]) {
    int i, j, t;
    double dx, dy, d, f, ax, ay;

    // Loop over time-steps
    for (t = 0; t < NUM_STEPS; t++) {
        // Loop over pairs of planets
        for (i = 0; i < NUM_PLANETS; i++) {
            for (j = i + 1; j < NUM_PLANETS; j++) {
                // Calculate distance between planets
                dx = planets[j].x - planets[i].x;
                dy = planets[j].y - planets[i].y;
                d = sqrt(dx*dx + dy*dy);

                // Calculate force of gravity
                f = G * planets[i].m * planets[j].m / (d*d);

                // Update accelerations of planets
                ax = f * dx / (d * planets[i].m);
                ay = f * dy / (d * planets[i].m);
                planets[i].vx += ax * DELTA_TIME / 1000.0;
                planets[i].vy += ay * DELTA_TIME / 1000.0;
                planets[j].vx -= ax * DELTA_TIME / 1000.0;
                planets[j].vy -= ay * DELTA_TIME / 1000.0;
            }
        }

        // Update positions of planets
        for (i = 0; i < NUM_PLANETS; i++) {
            planets[i].x += planets[i].vx * DELTA_TIME / 1000.0;
            planets[i].y += planets[i].vy * DELTA_TIME / 1000.0;
        }

        // Print the positions of the planets
        for (i = 0; i < NUM_PLANETS; i++) {
            printf("Planet #%d: (%f, %f)\n", i+1, planets[i].x, planets[i].y);
        }
    }
}

int main() {
    // Define initial positions, velocities, and masses of planets
    Planet planets[] = {
        {0, 0, 0, 0, 5.97e24},      // Earth
        {0, 6.38e6 + 4e5, 7800, 0, 7.34e22},   // Moon
        {10e6, 0, 0, -2000, 1e22}    // Unknown planet
    };

    // Simulate the system of planets
    simulate(planets);

    return 0;
}