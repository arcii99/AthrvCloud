//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the constants
#define G 6.67430e-11 // gravitational constant
#define DT 0.1 // timestep
#define MASS_OF_EARTH 5.972e24
#define RADIUS_OF_EARTH 6.371e6

// Define the structure for a planet
typedef struct {
    double position[3]; // x, y, z position
    double velocity[3]; // velocity in x, y, z
    double mass; // mass of the planet
} Planet;

// Calculate the distance between two planets
double distance(Planet* planet1, Planet* planet2) {
    double dx = planet2->position[0] - planet1->position[0];
    double dy = planet2->position[1] - planet1->position[1];
    double dz = planet2->position[2] - planet1->position[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Calculate the gravitational force exerted on planet1 by planet2
void gravitational_force(Planet* planet1, Planet* planet2, double* force) {
    double r = distance(planet1, planet2);
    double f = G * planet1->mass * planet2->mass / (r*r);
    force[0] = f * (planet2->position[0] - planet1->position[0]) / r;
    force[1] = f * (planet2->position[1] - planet1->position[1]) / r;
    force[2] = f * (planet2->position[2] - planet1->position[2]) / r;
}

int main() {
    // Create an array of 3 planets
    Planet planets[3];

    // Define the earth
    planets[0].position[0] = 0.0;
    planets[0].position[1] = RADIUS_OF_EARTH;
    planets[0].position[2] = 0.0;
    planets[0].velocity[0] = 5000.0;
    planets[0].velocity[1] = 0.0;
    planets[0].velocity[2] = 0.0;
    planets[0].mass = MASS_OF_EARTH;

    // Define the moon
    planets[1].position[0] = 0.0;
    planets[1].position[1] = RADIUS_OF_EARTH + 384400000.0;
    planets[1].position[2] = 0.0;
    planets[1].velocity[0] = 5000.0;
    planets[1].velocity[1] = 0.0;
    planets[1].velocity[2] = 1022.0;
    planets[1].mass = 7.342e22;

    // Define the sun
    planets[2].position[0] = 149.6e9;
    planets[2].position[1] = 0.0;
    planets[2].position[2] = 0.0;
    planets[2].velocity[0] = 0.0;
    planets[2].velocity[1] = 29783.0;
    planets[2].velocity[2] = 0.0;
    planets[2].mass = 1.989e30;

    // Time loop
    for (int i = 0; i < 100; i++) {
        // Calculate the net force on each planet
        double force[3];
        for (int j = 0; j < 3; j++) {
            force[0] = force[1] = force[2] = 0.0;
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    double f[3];
                    gravitational_force(&planets[j], &planets[k], f);
                    force[0] += f[0];
                    force[1] += f[1];
                    force[2] += f[2];
                }
            }
            // Update the velocity and position of the planet
            for (int l = 0; l < 3; l++) {
                planets[j].velocity[l] += force[l] * DT / planets[j].mass;
                planets[j].position[l] += planets[j].velocity[l] * DT;
            }
        }
        // Print the positions of the planets
        printf("Earth: (%lf, %lf, %lf)\n", planets[0].position[0], planets[0].position[1], planets[0].position[2]);
        printf("Moon: (%lf, %lf, %lf)\n", planets[1].position[0], planets[1].position[1], planets[1].position[2]);
        printf("Sun: (%lf, %lf, %lf)\n", planets[2].position[0], planets[2].position[1], planets[2].position[2]);
    }
    return 0;
}