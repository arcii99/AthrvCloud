//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define MASS_SUN 1.989e30 // mass of the sun
#define RADIUS_SUN 696340000 // radius of the sun
#define AU 149597870700 // astronomical unit

typedef struct {
    double x, y; // position of planet
    double vx, vy; // velocity of planet
    double ax, ay; // acceleration of planet
    double mass; // mass of planet
    double radius; // radius of planet
} planet_t;

int main() {
    planet_t sun = {
        .x = 0, .y = 0,
        .vx = 0, .vy = 0,
        .ax = 0, .ay = 0,
        .mass = MASS_SUN,
        .radius = RADIUS_SUN
    };
    planet_t earth = {
        .x = AU, .y = 0,
        .vx = 0, .vy = 29783,
        .ax = 0, .ay = 0,
        .mass = 5.972e24,
        .radius = 6371000
    };
    planet_t mars = {
        .x = AU * 1.52, .y = 0,
        .vx = 0, .vy = 24130,
        .ax = 0, .ay = 0,
        .mass = 6.39e23,
        .radius = 3389500
    };
    planet_t planets[] = { sun, earth, mars };
    const int num_planets = sizeof(planets) / sizeof(planet_t);

    double t = 0; // time elapsed
    const double dt = 60 * 60 * 24; // time step (1 day)
    const double end_time = 2 * 365.25 * 24 * 60 * 60; // end time (2 years)

    // Simulation loop
    while (t < end_time) {
        // Calculate gravitational force on each planet
        for (int i = 0; i < num_planets; i++) {
            double fx = 0, fy = 0;
            for (int j = 0; j < num_planets; j++) {
                if (j != i) {
                    const double dx = planets[j].x - planets[i].x;
                    const double dy = planets[j].y - planets[i].y;
                    const double r = sqrt(dx*dx + dy*dy);
                    const double f = G * planets[i].mass * planets[j].mass / (r*r);
                    fx += f * dx / r;
                    fy += f * dy / r;
                }
            }
            planets[i].ax = fx / planets[i].mass;
            planets[i].ay = fy / planets[i].mass;
        }

        // Update position and velocity of each planet
        for (int i = 0; i < num_planets; i++) {
            planets[i].vx += planets[i].ax * dt;
            planets[i].vy += planets[i].ay * dt;
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }

        // Print positions of planets (for visualization)
        printf("Time: %.2f days\n", t / (60 * 60 * 24));
        for (int i = 0; i < num_planets; i++) {
            printf("%s: (%.2f, %.2f)\n", i == 0 ? "Sun" : i == 1 ? "Earth" : "Mars", planets[i].x / AU, planets[i].y / AU);
        }
        printf("\n");

        t += dt;
    }

    return 0;
}