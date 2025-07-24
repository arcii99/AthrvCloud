//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

struct planet {
    double x, y; // Position
    double vx, vy; // Velocity
    double ax, ay; // Acceleration
    double mass; // Mass
};

int main() {
    int num_planets = 3;
    struct planet planets[num_planets];

    // Initialize planets
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].ax = 0;
    planets[0].ay = 0;
    planets[0].mass = 5.97e24; // Mass of Earth

    planets[1].x = 4e7;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = -29500;
    planets[1].ax = 0;
    planets[1].ay = 0;
    planets[1].mass = 7.34e22; // Mass of Moon

    planets[2].x = 8e7;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = -24310;
    planets[2].ax = 0;
    planets[2].ay = 0;
    planets[2].mass = 3.3e23; // Mass of Mars

    double t = 0; // Time
    double dt = 0.01; // Time step

    while (1) {
        // Compute accelerations
        for (int i = 0; i < num_planets; i++) {
            planets[i].ax = 0;
            planets[i].ay = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    double dx = planets[j].x - planets[i].x;
                    double dy = planets[j].y - planets[i].y;
                    double d = sqrt(dx*dx + dy*dy);
                    double f = G * planets[i].mass * planets[j].mass / (d*d);
                    planets[i].ax += f / planets[i].mass * dx / d;
                    planets[i].ay += f / planets[i].mass * dy / d;
                }
            }
        }

        // Update velocities and positions using Euler's method
        for (int i = 0; i < num_planets; i++) {
            planets[i].vx += planets[i].ax * dt;
            planets[i].vy += planets[i].ay * dt;
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }

        // Print time and positions
        printf("Time: %f\n", t);
        for (int i = 0; i < num_planets; i++) {
            printf("Planet %d: (%f, %f)\n", i, planets[i].x, planets[i].y);
        }
        printf("\n");

        t += dt;
    }

    return 0;
}