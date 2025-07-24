//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11    // gravitational constant
#define TIME_STEP 86400   // time step in seconds (one day)
#define NUM_PLANETS 4   // number of planets in the simulation

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    char name[20];
    double mass;
    Vector3D pos;
    Vector3D vel;
    Vector3D force;
} Planet;

void initialize_planets(Planet *planets) {
    // initialize the planets
    // distances are in meters, velocities are in meters/second
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.9885e30;
    planets[0].pos.x = 0.0;
    planets[0].pos.y = 0.0;
    planets[0].pos.z = 0.0;
    planets[0].vel.x = 0.0;
    planets[0].vel.y = 0.0;
    planets[0].vel.z = 0.0;

    strcpy(planets[1].name, "Earth");
    planets[1].mass = 5.9722e24;
    planets[1].pos.x = -1.4710e11;
    planets[1].pos.y = 0.0;
    planets[1].pos.z = 0.0;
    planets[1].vel.x = 0.0;
    planets[1].vel.y = 3.0287e4;
    planets[1].vel.z = 0.0;

    strcpy(planets[2].name, "Mars");
    planets[2].mass = 6.4169e23;
    planets[2].pos.x = 0.0;
    planets[2].pos.y = -2.067e11;
    planets[2].pos.z = 0.0;
    planets[2].vel.x = 2.641e4;
    planets[2].vel.y = 0.0;
    planets[2].vel.z = 0.0;

    strcpy(planets[3].name, "Jupiter");
    planets[3].mass = 1.8982e27;
    planets[3].pos.x = 0.0;
    planets[3].pos.y = 0.0;
    planets[3].pos.z = 7.4052e11;
    planets[3].vel.x = 1.3073e4;
    planets[3].vel.y = 0.0;
    planets[3].vel.z = 0.0;
}

Vector3D calculate_force(Planet planet1, Planet planet2) {
    Vector3D r;
    r.x = planet2.pos.x - planet1.pos.x;
    r.y = planet2.pos.y - planet1.pos.y;
    r.z = planet2.pos.z - planet1.pos.z;
    double distance = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
    double magnitude = G * planet1.mass * planet2.mass / (distance * distance);
    Vector3D force;
    force.x = magnitude * r.x / distance;
    force.y = magnitude * r.y / distance;
    force.z = magnitude * r.z / distance;
    return force;
}

void calculate_forces(Planet *planets) {
    // calculate forces between all pairs of planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].force.x = 0.0;
        planets[i].force.y = 0.0;
        planets[i].force.z = 0.0;
    }
    for (int i = 0; i < NUM_PLANETS - 1; i++) {
        for (int j = i + 1; j < NUM_PLANETS; j++) {
            Vector3D force = calculate_force(planets[i], planets[j]);
            planets[i].force.x += force.x;
            planets[i].force.y += force.y;
            planets[i].force.z += force.z;
            planets[j].force.x -= force.x;
            planets[j].force.y -= force.y;
            planets[j].force.z -= force.z;
        }
    }
}

void update_planets(Planet *planets) {
    // update positions and velocities of all the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        // update velocity
        planets[i].vel.x += planets[i].force.x / planets[i].mass * TIME_STEP;
        planets[i].vel.y += planets[i].force.y / planets[i].mass * TIME_STEP;
        planets[i].vel.z += planets[i].force.z / planets[i].mass * TIME_STEP;
        // update position
        planets[i].pos.x += planets[i].vel.x * TIME_STEP;
        planets[i].pos.y += planets[i].vel.y * TIME_STEP;
        planets[i].pos.z += planets[i].vel.z * TIME_STEP;
    }
}

void print_planets(Planet *planets) {
    // print out the positions and velocities of all the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s\t(%e, %e, %e)\t(%e, %e, %e)\n", planets[i].name,
               planets[i].pos.x, planets[i].pos.y, planets[i].pos.z,
               planets[i].vel.x, planets[i].vel.y, planets[i].vel.z);
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    initialize_planets(planets);

    for (int i = 0; i < 365; i++) {
        calculate_forces(planets);
        update_planets(planets);
        print_planets(planets);
    }

    return 0;
}