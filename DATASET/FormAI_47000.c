//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to represent a planet
typedef struct Planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double fx;
    double fy;
    double fz;
} Planet;

// Struct to represent a force acting on a planet
typedef struct Force {
    double fx;
    double fy;
    double fz;
} Force;

// Constants
const int NUM_PLANETS = 9; // number of planets in our solar system
const double GRAV_CONST = 6.67430e-11; // gravitational constant
const double TIMESTEP = 60 * 60 * 24; // time increment (one day in seconds)
const double YEAR = 365.25 * 24 * 60 * 60; // length of a year in seconds

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate the force acting on one planet due to another
Force calculate_force(Planet p1, Planet p2) {
    Force f;
    
    double dist = distance(p1, p2);
    double magnitude = GRAV_CONST * p1.mass * p2.mass / (dist * dist);
    
    f.fx = magnitude * (p2.x - p1.x) / dist;
    f.fy = magnitude * (p2.y - p1.y) / dist;
    f.fz = magnitude * (p2.z - p1.z) / dist;
    
    return f;
}

// Function to update the forces on each planet
void update_forces(Planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].fx = 0;
        planets[i].fy = 0;
        planets[i].fz = 0;
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                Force f = calculate_force(planets[i], planets[j]);
                planets[i].fx += f.fx;
                planets[i].fy += f.fy;
                planets[i].fz += f.fz;
            }
        }
    }
}

// Function to update the positions and velocities of each planet
void update_positions(Planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double ax = planets[i].fx / planets[i].mass;
        double ay = planets[i].fy / planets[i].mass;
        double az = planets[i].fz / planets[i].mass;
        planets[i].vx += ax * TIMESTEP;
        planets[i].vy += ay * TIMESTEP;
        planets[i].vz += az * TIMESTEP;
        planets[i].x += planets[i].vx * TIMESTEP;
        planets[i].y += planets[i].vy * TIMESTEP;
        planets[i].z += planets[i].vz * TIMESTEP;
    }
}

// Function to print out the current positions of each planet
void print_positions(Planet planets[], double time) {
    printf("Time: %.2f years\n", time / YEAR);
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.2f, %.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the planets
    Planet planets[NUM_PLANETS];
    // Mercury
    sprintf(planets[0].name, "Mercury");
    planets[0].mass = 3.30e23;
    planets[0].x = -4.60e10;
    planets[0].y = 2.64e10;
    planets[0].z = 1.36e10;
    planets[0].vx = -3.78e4;
    planets[0].vy = -4.35e4;
    planets[0].vz = -6.57e3;
    // Venus
    sprintf(planets[1].name, "Venus");
    planets[1].mass = 4.87e24;
    planets[1].x = -1.07e11;
    planets[1].y = 3.30e9;
    planets[1].z = 6.58e9;
    planets[1].vx = -1.76e4;
    planets[1].vy = -3.50e4;
    planets[1].vz = -2.28e3;
    // Earth
    sprintf(planets[2].name, "Earth");
    planets[2].mass = 5.98e24;
    planets[2].x = -1.50e11;
    planets[2].y = 0;
    planets[2].z = 0;
    planets[2].vx = 0;
    planets[2].vy = -2.98e4;
    planets[2].vz = 0;
    // Mars
    sprintf(planets[3].name, "Mars");
    planets[3].mass = 6.42e23;
    planets[3].x = -2.28e11;
    planets[3].y = -4.03e10;
    planets[3].z = -1.73e10;
    planets[3].vx = 1.07e4;
    planets[3].vy = -2.41e4;
    planets[3].vz = -2.17e3;
    // Jupiter
    sprintf(planets[4].name, "Jupiter");
    planets[4].mass = 1.90e27;
    planets[4].x = -7.77e11;
    planets[4].y = -5.50e11;
    planets[4].z = 1.58e11;
    planets[4].vx = 7.33e3;
    planets[4].vy = -1.01e4;
    planets[4].vz = -1.97e3;
    // Saturn
    sprintf(planets[5].name, "Saturn");
    planets[5].mass = 5.68e26;
    planets[5].x = -1.43e12;
    planets[5].y = -9.59e11;
    planets[5].z = 3.51e11;
    planets[5].vx = 5.28e3;
    planets[5].vy = -7.71e3;
    planets[5].vz = -1.28e3;
    // Uranus
    sprintf(planets[6].name, "Uranus");
    planets[6].mass = 8.68e25;
    planets[6].x = -2.87e12;
    planets[6].y = -3.41e12;
    planets[6].z = 9.70e10;
    planets[6].vx = 3.49e3;
    planets[6].vy = -2.92e3;
    planets[6].vz = -3.87e3;
    // Neptune
    sprintf(planets[7].name, "Neptune");
    planets[7].mass = 1.02e26;
    planets[7].x = -4.50e12;
    planets[7].y = -1.10e12;
    planets[7].z = 2.52e11;
    planets[7].vx = 1.34e3;
    planets[7].vy = -5.35e3;
    planets[7].vz = -1.54e3;
    // Pluto
    sprintf(planets[8].name, "Pluto");
    planets[8].mass = 1.31e22;
    planets[8].x = -4.39e12;
    planets[8].y = -3.13e12;
    planets[8].z = 8.48e11;
    planets[8].vx = 3.13e3;
    planets[8].vy = -4.27e3;
    planets[8].vz = -6.35e2;
    
    // Run the simulation for 100 years
    double time = 0;
    while (time < 100 * YEAR) {
        update_forces(planets);
        update_positions(planets);
        if ((int)time % (int)(YEAR/10) == 0) { // print out every 10th of a year
            print_positions(planets, time);
        }
        time += TIMESTEP;
    }
    
    return 0;
}