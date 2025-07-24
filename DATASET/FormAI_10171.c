//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define G 6.67430e-11

struct planet {
    char name[256];
    double mass; // in kg
    double position[3]; // in km
    double velocity[3]; // in km/s
};

int main() {
    struct planet sun = {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}};
    struct planet earth = {"Earth", 5.972e24, {149.6e6, 0, 0}, {0, 29.78, 0}};
    struct planet mars = {"Mars", 6.39e23, {-227.9e6, 0, 0}, {0, -24.077, 0}};
    struct planet venus = {"Venus", 4.87e24, {108.2e6, 0, 0}, {0, 35.02, 0}};

    struct planet planets[] = {sun, earth, mars, venus};
    int num_planets = sizeof(planets) / sizeof(struct planet);

    double time_step = 60 * 60 * 24; // in seconds (one day)
    int num_steps = 365; // simulate one year

    for (int i = 0; i < num_steps; i++) {
        // Calculate acceleration of each planet
        double accelerations[num_planets][3];
        for (int j = 0; j < num_planets; j++) {
            for (int k = 0; k < num_planets; k++) {
                if (j == k) {
                    continue; // skip self-interaction
                }
                double distance[3];
                for (int l = 0; l < 3; l++) {
                    distance[l] = planets[j].position[l] - planets[k].position[l];
                }
                double r = sqrt(distance[0]*distance[0] + distance[1]*distance[1] + distance[2]*distance[2]);
                double force = G * planets[j].mass * planets[k].mass / (r*r);
                for (int l = 0; l < 3; l++) {
                    accelerations[j][l] -= force * distance[l] / (r * planets[j].mass);
                }
            }
        }

        // Update positions and velocities of each planet
        for (int j = 0; j < num_planets; j++) {
            for (int k = 0; k < 3; k++) {
                planets[j].position[k] += planets[j].velocity[k] * time_step;
            }
            for (int k = 0; k < 3; k++) {
                planets[j].velocity[k] += accelerations[j][k] * time_step;
            }
        }

        // Print out positions of each planet
        printf("Step %d:\n", i+1);
        for (int j = 0; j < num_planets; j++) {
            printf("%s: (%.2f, %.2f, %.2f) km\n", planets[j].name, planets[j].position[0], planets[j].position[1], planets[j].position[2]);
        }
        printf("\n");
    }

    return 0;
}