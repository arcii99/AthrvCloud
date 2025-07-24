//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

#define DAY 86400 // number of seconds in a day
#define YEAR 31536000 // number of seconds in a year

// define struct for planet
typedef struct {
    char name[20];
    double mass; // kg
    double radius; // m
    double x; // position
    double y;
    double z;
    double vx; // velocity
    double vy;
    double vz;
} planet_t;

// get distance between two planets
double distance(planet_t p1, planet_t p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// update a planet's velocity based on gravitational force from other planets
void update_velocity(planet_t *planet, planet_t *planets, int num_planets) {
    double fx = 0.0;
    double fy = 0.0;
    double fz = 0.0;
    for (int i = 0; i < num_planets; i++) {
        if (strcmp(planet->name, planets[i].name) != 0) { // don't apply force to self
            double r = distance(*planet, planets[i]);
            double f = G * planet->mass * planets[i].mass / (r*r);
            fx += f * (planets[i].x - planet->x) / r;
            fy += f * (planets[i].y - planet->y) / r;
            fz += f * (planets[i].z - planet->z) / r;
        }
    }
    planet->vx += fx / planet->mass * DAY;
    planet->vy += fy / planet->mass * DAY;
    planet->vz += fz / planet->mass * DAY;
}

// update a planet's position based on its velocity
void update_position(planet_t *planet) {
    planet->x += planet->vx * DAY;
    planet->y += planet->vy * DAY;
    planet->z += planet->vz * DAY;
}

int main() {
    // create array of planets
    planet_t planets[] = {
        {"Sun", 1.989e30, 696340000, 0, 0, 0, 0, 0, 0},
        {"Mercury", 3.285e23, 2439700, 0, 57910000, 0, 47870, 0, 0},
        {"Venus", 4.867e24, 6051800, 0, 108200000, 0, 35020, 0, 0},
        {"Earth", 5.972e24, 6371000, 0, 149600000, 0, 29783, 0, 0},
        {"Mars", 6.39e23, 3389500, 0, 227940000, 0, 24130, 0, 0},
        {"Jupiter", 1.898e27, 69911000, 0, 778570000, 0, 13070, 0, 0},
        {"Saturn", 5.683e26, 58232000, 0, 1433500000, 0, 9690, 0, 0},
        {"Uranus", 8.681e25, 25362000, 0, 2872500000, 0, 6810, 0, 0},
        {"Neptune", 1.024e26, 24622000, 0, 4495100000, 0, 5430, 0, 0},
        {"Pluto", 1.309e22, 1188300, 0, 5906400000, 0, 4740, 0, 0}
    };
    int num_planets = sizeof(planets) / sizeof(planets[0]);

    // simulate for one year
    double time = 0;
    double dt = DAY;
    while (time < 1*YEAR) {
        // update velocities and positions of each planet
        for (int i = 0; i < num_planets; i++) {
            update_velocity(&planets[i], planets, num_planets);
            update_position(&planets[i]);
        }
        time += dt;
    }

    // print final positions of each planet
    for (int i = 0; i < num_planets; i++) {
        printf("%s: (%e, %e, %e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}