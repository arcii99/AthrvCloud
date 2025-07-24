//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11

// Define a struct for the planets
typedef struct {
    char name[30];
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
} Planet;

// Calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    double x_diff = p2.x_pos - p1.x_pos;
    double y_diff = p2.y_pos - p1.y_pos;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

int main() {
    // Create an array of planets
    Planet planets[3];

    // Initialize the planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.972e24;
    planets[0].x_pos = 0;
    planets[0].y_pos = 0;
    planets[0].x_vel = 0;
    planets[0].y_vel = 0;

    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.39e23;
    planets[1].x_pos = 2.279e11;
    planets[1].y_pos = 0;
    planets[1].x_vel = 0;
    planets[1].y_vel = 2.41e4;

    strcpy(planets[2].name, "Jupiter");
    planets[2].mass = 1.898e27;
    planets[2].x_pos = 7.785e11;
    planets[2].y_pos = 0;
    planets[2].x_vel = 0;
    planets[2].y_vel = 1.31e4;

    // Set the total simulation time and time step
    double t_total = 1e8;
    double dt = 1e4;

    // Run the simulation
    for (double t = 0; t <= t_total; t += dt) {
        // Calculate the gravitational force on each planet
        double fx[3] = {0, 0, 0};
        double fy[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    Planet p1 = planets[i];
                    Planet p2 = planets[j];
                    double dist = distance(p1, p2);
                    double f = G * p1.mass * p2.mass / pow(dist, 2);
                    double fx0 = f * (p2.x_pos - p1.x_pos) / dist;
                    double fy0 = f * (p2.y_pos - p1.y_pos) / dist;
                    fx[i] += fx0;
                    fy[i] += fy0;
                }
            }
        }

        // Update the planet positions and velocities
        for (int i = 0; i < 3; i++) {
            Planet *p = &planets[i];
            double ax = fx[i] / p->mass;
            double ay = fy[i] / p->mass;
            p->x_vel += ax * dt;
            p->y_vel += ay * dt;
            p->x_pos += p->x_vel * dt;
            p->y_pos += p->y_vel * dt;
        }

        // Print the current planet positions
        printf("t=%.2f Earth:(%.2f,%.2f) Mars:(%.2f,%.2f) Jupiter:(%.2f,%.2f)\n", t,
            planets[0].x_pos, planets[0].y_pos,
            planets[1].x_pos, planets[1].y_pos,
            planets[2].x_pos, planets[2].y_pos);
    }

    return 0;
}