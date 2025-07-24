//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define planetary constants
#define G 6.67408E-11 // gravitational constant
#define M_EARTH 5.972E24 // mass of Earth
#define R_EARTH 6371E3 // radius of Earth

// Define struct for planet
typedef struct {
    double mass; // mass of planet
    double x; // x position of planet
    double y; // y position of planet
    double vx; // x velocity of planet
    double vy; // y velocity of planet
} Planet;

// Function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate gravitational force between two planets
double force(Planet p1, Planet p2) {
    return (G * p1.mass * p2.mass) / pow(distance(p1, p2), 2);
}

// Function to calculate acceleration of planet due to gravitational force
double acceleration(double f, double m) {
    return f / m;
}

// Function to simulate motion of planets due to gravity
void simulate(int num_planets, Planet *planets, int timesteps, double dt) {
    int i, j, k;
    double f, a;

    // Iterate over timesteps
    for (i = 0; i < timesteps; i++) {
        // Iterate over each planet
        for (j = 0; j < num_planets; j++) {
            // Calculate net force on planet from other planets
            f = 0;
            for (k = 0; k < num_planets; k++) {
                if (k != j) {
                    f += force(planets[j], planets[k]);
                }
            }

            // Calculate acceleration of planet due to net force
            a = acceleration(f, planets[j].mass);

            // Calculate new velocity and position of planet
            planets[j].vx += a * dt;
            planets[j].vy += a * dt;
            planets[j].x += planets[j].vx * dt;
            planets[j].y += planets[j].vy * dt;

            // Check if planet is inside Earth and reset position and velocity if it is
            if (distance(planets[j], (Planet) {M_EARTH, 0, 0, 0, 0}) < R_EARTH) {
                planets[j].x = 0;
                planets[j].y = R_EARTH;
                planets[j].vx = 0;
                planets[j].vy = 0;
            }
        }
    }
}

int main() {
    // Define initial conditions
    Planet planets[] = {
        {5.972E24, 0, 0, 0, 0}, // Earth
        {1000, 1E8, 0, 0, 100} // test planet
    };
    int num_planets = 2;
    int timesteps = 1000;
    double dt = 3600;

    // Simulate motion of planets due to gravity
    simulate(num_planets, planets, timesteps, dt);

    // Print final positions of planets
    int i;
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.2f, %.2f)\n", i+1, planets[i].x, planets[i].y);
    }

    return 0;
}