//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ken Thompson
/*

    C Planet Gravity Simulation

    A program that simulates the gravitational interactions between multiple planets.

    By: [Your Name]

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 100      /* maximum number of planets */
#define G_CONST 6.6743e-11   /* gravitational constant */

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
} planet_t;

planet_t planets[MAX_PLANETS];  /* initialize capacity for planets */

int num_planets;                /* number of planets currently in the simulation */

/* function that calculates the distance between two planets */
double get_distance(int planet1, int planet2) {
    double dx = planets[planet1].position[0] - planets[planet2].position[0];
    double dy = planets[planet1].position[1] - planets[planet2].position[1];
    double dz = planets[planet1].position[2] - planets[planet2].position[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

/* function that calculates the gravitational force between two planets */
double get_force(int planet1, int planet2) {
    double distance = get_distance(planet1, planet2);
    double force = G_CONST * planets[planet1].mass * planets[planet2].mass / (distance * distance);
    return force;
}

/* function that updates the acceleration of a planet */
void update_acceleration(int planet) {
    int i;
    double force_x = 0, force_y = 0, force_z = 0;
    for (i = 0; i < num_planets; i++) {
        if (i != planet) {
            double force = get_force(planet, i);
            double distance = get_distance(planet, i);
            double dx = (planets[i].position[0] - planets[planet].position[0]) / distance;
            double dy = (planets[i].position[1] - planets[planet].position[1]) / distance;
            double dz = (planets[i].position[2] - planets[planet].position[2]) / distance;
            force_x += force * dx;
            force_y += force * dy;
            force_z += force * dz;
        }
    }
    planets[planet].acceleration[0] = force_x / planets[planet].mass;
    planets[planet].acceleration[1] = force_y / planets[planet].mass;
    planets[planet].acceleration[2] = force_z / planets[planet].mass;
}

/* function that updates the velocity of a planet */
void update_velocity(int planet, double timestep) {
    planets[planet].velocity[0] += planets[planet].acceleration[0] * timestep;
    planets[planet].velocity[1] += planets[planet].acceleration[1] * timestep;
    planets[planet].velocity[2] += planets[planet].acceleration[2] * timestep;
}

/* function that updates the position of a planet */
void update_position(int planet, double timestep) {
    planets[planet].position[0] += planets[planet].velocity[0] * timestep;
    planets[planet].position[1] += planets[planet].velocity[1] * timestep;
    planets[planet].position[2] += planets[planet].velocity[2] * timestep;
}

/* function that updates the position, velocity, and acceleration of all planets */
void update_planets(double timestep) {
    int i;
    for (i = 0; i < num_planets; i++) {
        update_acceleration(i);
        update_velocity(i, timestep);
        update_position(i, timestep);
    }
}

/* main function that runs the simulation */
int main() {
    /* initialize the planets */
    num_planets = 2;
    planets[0].mass = 5.97e24;
    planets[0].position[0] = 0;
    planets[0].position[1] = 0;
    planets[0].position[2] = 0;
    planets[0].velocity[0] = 0;
    planets[0].velocity[1] = 0;
    planets[0].velocity[2] = 0;
    planets[1].mass = 7.35e22;
    planets[1].position[0] = 3.8440e8;
    planets[1].position[1] = 0;
    planets[1].position[2] = 0;
    planets[1].velocity[0] = 0;
    planets[1].velocity[1] = 1.022e3;
    planets[1].velocity[2] = 0;

    /* run the simulation */
    double time = 0;
    double timestep = 3600;
    while (time < 864000) {
        printf("Time: %.0f seconds\n", time);
        printf("Planet 1: (x,y,z) = (%.2f,%.2f,%.2f)\n", planets[0].position[0], planets[0].position[1], planets[0].position[2]);
        printf("Planet 2: (x,y,z) = (%.2f,%.2f,%.2f)\n", planets[1].position[0], planets[1].position[1], planets[1].position[2]);
        printf("\n");
        update_planets(timestep);
        time += timestep;
    }

    return 0;
}