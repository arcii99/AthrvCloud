//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

struct planet {
    char name[30];
    double mass; // In kilograms
    double x, y; // Position of planet
    double vx, vy; // Velocity of planet
    double fx, fy; // Forces acting on planet
};

int main() {
    int num_planets = 3;
    double dt = 86400.0; // Time step: 1 day in seconds

    struct planet planets[num_planets];

    // Initializing the planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97e24;
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].fx = 0.0;
    planets[0].fy = 0.0;

    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.39e23;
    planets[1].x = 227.9e9;
    planets[1].y = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = 24.1e3;
    planets[1].fx = 0.0;
    planets[1].fy = 0.0;

    strcpy(planets[2].name, "Jupiter");
    planets[2].mass = 1.898e27;
    planets[2].x = 778.3e9;
    planets[2].y = 0.0;
    planets[2].vx = 0.0;
    planets[2].vy = 13.1e3;
    planets[2].fx = 0.0;
    planets[2].fy = 0.0;

    // Simulating the motion of planets
    int t;
    for (t = 0; t < 365; t++) {
        int i, j;
        double dx, dy, r, f;

        // Reset forces acting on planets
        for (i = 0; i < num_planets; i++) {
            planets[i].fx = 0.0;
            planets[i].fy = 0.0;
        }

        // Compute forces acting on each planet
        for (i = 0; i < num_planets; i++) {
            for (j = 0; j < num_planets; j++) {
                if (i == j) continue;

                dx = planets[j].x - planets[i].x;
                dy = planets[j].y - planets[i].y;
                r = sqrt(dx*dx + dy*dy);

                f = G * planets[i].mass * planets[j].mass / (r*r);
                f /= planets[i].mass;

                planets[i].fx += f * dx / r;
                planets[i].fy += f * dy / r;
            }
        }

        // Update positions and velocities of each planet
        for (i = 0; i < num_planets; i++) {
            planets[i].vx += planets[i].fx * dt;
            planets[i].vy += planets[i].fy * dt;

            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }

        // Print the new positions of the planets after 1 day
        printf("Day %d:\n", t+1);
        for (i = 0; i < num_planets; i++) {
            printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y);
        }
        printf("\n");
    }

    return 0;
}