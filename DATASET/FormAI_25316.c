//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define G 6.674 * pow(10, -11)
#define TIMESTEP 0.001
#define STEPS 100000
#define NUM_PLANETS 2

// Define struct for Planet
typedef struct {
    char name[20];
    double mass;
    double radius;
    double x, y;
    double vx, vy;
} Planet;

// Function to generate random double between min and max 
double random_double(double min, double max) {
    double scale = rand() / (double) RAND_MAX;
    return min + scale * (max - min);
}

int main() {
    // Seed random generator
    srand(time(NULL));

    // Initialize planets
    Planet planets[NUM_PLANETS];
    sprintf(planets[0].name, "Planet 1");
    sprintf(planets[1].name, "Planet 2");
    planets[0].mass = random_double(1.0, 10.0);
    planets[1].mass = random_double(1.0, 10.0);
    planets[0].radius = random_double(0.1, 1.0);
    planets[1].radius = random_double(0.1, 1.0);
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[1].x = random_double(1.0, 10.0);
    planets[1].y = random_double(1.0, 10.0);
    planets[0].vx = random_double(-1.0, 1.0);
    planets[0].vy = random_double(-1.0, 1.0);
    planets[1].vx = random_double(-1.0, 1.0);
    planets[1].vy = random_double(-1.0, 1.0);

    // Loop through simulation steps
    for (int i = 0; i < STEPS; i++) {
        // Calculate distance and force between planets
        double dx = planets[1].x - planets[0].x;
        double dy = planets[1].y - planets[0].y;
        double r = sqrt(pow(dx, 2) + pow(dy, 2));
        double force = G * planets[0].mass * planets[1].mass / pow(r, 2);

        // Calculate acceleration and update velocities
        double ax = force / planets[0].mass * dx / r;
        double ay = force / planets[0].mass * dy / r;
        planets[0].vx += ax * TIMESTEP;
        planets[0].vy += ay * TIMESTEP;
        planets[1].vx -= ax * TIMESTEP;
        planets[1].vy -= ay * TIMESTEP;

        // Update positions
        planets[0].x += planets[0].vx * TIMESTEP;
        planets[0].y += planets[0].vy * TIMESTEP;
        planets[1].x += planets[1].vx * TIMESTEP;
        planets[1].y += planets[1].vy * TIMESTEP;

        // Print out planet positions
        printf("Step %d:\n", i);
        for (int j = 0; j < NUM_PLANETS; j++) {
            printf("  %s: (%f, %f)\n", planets[j].name, planets[j].x, planets[j].y);
        }
    }

    return 0;
}