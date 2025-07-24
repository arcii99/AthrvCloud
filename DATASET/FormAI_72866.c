//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: satisfied
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 8  // Number of planets in the solar system
#define GRAVITY 6.674e-11  // Gravitational constant
#define TIMESTEP 86400  // Time step size (in seconds)

/* Definition of a planet */
typedef struct {
    char name[20];
    double mass;  // in kg
    double radius;  // in meters
    double x;  // x position in meters
    double y;  // y position in meters
    double z;  // z position in meters
    double vx;  // x velocity in meters/second
    double vy;  // y velocity in meters/second
    double vz;  // z velocity in meters/second
} planet;

/* Function to calculate the distance between two planets */
double distance(planet *p1, planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

/* Function to calculate the gravitational force between two planets */
double gravitational_force(planet *p1, planet *p2) {
    double r = distance(p1, p2);
    return GRAVITY * p1->mass * p2->mass / (r*r);
}

int main() {
    planet planets[NUM_PLANETS];
    int i, j;
    double fx, fy, fz, force;

    /* Initialize the planets */
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.989e30;
    planets[0].radius = 696340000;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;

    strcpy(planets[1].name, "Mercury");
    planets[1].mass = 3.285e23;
    planets[1].radius = 2439700;
    planets[1].x = -57910000;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 47360;
    planets[1].vz = 0;

    strcpy(planets[2].name, "Venus");
    planets[2].mass = 4.867e24;
    planets[2].radius = 6051800;
    planets[2].x = 0;
    planets[2].y = 108200000;
    planets[2].z = 0;
    planets[2].vx = -35020;
    planets[2].vy = 0;
    planets[2].vz = 0;

    strcpy(planets[3].name, "Earth");
    planets[3].mass = 5.972e24;
    planets[3].radius = 6371000;
    planets[3].x = 149600000;
    planets[3].y = 0;
    planets[3].z = 0;
    planets[3].vx = 0;
    planets[3].vy = 29783;
    planets[3].vz = 0;

    strcpy(planets[4].name, "Mars");
    planets[4].mass = 6.39e23;
    planets[4].radius = 3396200;
    planets[4].x = 0;
    planets[4].y = -227940000;
    planets[4].z = 0;
    planets[4].vx = 24077;
    planets[4].vy = 0;
    planets[4].vz = 0;

    strcpy(planets[5].name, "Jupiter");
    planets[5].mass = 1.898e27;
    planets[5].radius = 69911000;
    planets[5].x = 778500000;
    planets[5].y = 0;
    planets[5].z = 0;
    planets[5].vx = 0;
    planets[5].vy = 13070;
    planets[5].vz = 0;

    strcpy(planets[6].name, "Saturn");
    planets[6].mass = 5.683e26;
    planets[6].radius = 58232000;
    planets[6].x = 0;
    planets[6].y = 1433500000;
    planets[6].z = 0;
    planets[6].vx = -9070;
    planets[6].vy = 0;
    planets[6].vz = 0;

    strcpy(planets[7].name, "Uranus");
    planets[7].mass = 8.681e25;
    planets[7].radius = 25362000;
    planets[7].x = -2872500000;
    planets[7].y = 0;
    planets[7].z = 0;
    planets[7].vx = 0;
    planets[7].vy = 5845;
    planets[7].vz = 0;

    /* Run the simulation */
    for (int t = 0; t < 365*10; t++) {
        /* Calculate the forces acting on each planet */
        for (i = 0; i < NUM_PLANETS; i++) {
            fx = fy = fz = 0.0;

            for (j = 0; j < NUM_PLANETS; j++) {
                if (i == j) continue;

                force = gravitational_force(&planets[i], &planets[j]);
                fx += force * (planets[j].x - planets[i].x) / distance(&planets[i], &planets[j]);
                fy += force * (planets[j].y - planets[i].y) / distance(&planets[i], &planets[j]);
                fz += force * (planets[j].z - planets[i].z) / distance(&planets[i], &planets[j]);
            }

            /* Update the velocities and positions of each planet */
            planets[i].vx += fx / planets[i].mass * TIMESTEP;
            planets[i].vy += fy / planets[i].mass * TIMESTEP;
            planets[i].vz += fz / planets[i].mass * TIMESTEP;
            planets[i].x += planets[i].vx * TIMESTEP;
            planets[i].y += planets[i].vy * TIMESTEP;
            planets[i].z += planets[i].vz * TIMESTEP;
        }

        /* Print the position of each planet */
        for (i = 0; i < NUM_PLANETS; i++) {
            printf("%s: (%e, %e, %e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
        }

        printf("\n");

        /* Wait for a short period of time (in seconds) to slow down the simulation */
        struct timespec ts = {0, 100000000};
        nanosleep(&ts, NULL);
    }

    return 0;
}