//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Struct for representing a planet
typedef struct Planet {
    char name[20];
    double mass; // kg
    double radius; // m
    double x, y, z, vx, vy, vz; // position and velocity vectors, m and m/s
} Planet;

// Function for computing gravitational force between two planets
void compute_gravity_force(Planet* p1, Planet* p2, double* fx, double* fy, double* fz) {
    double G = 6.6743*pow(10, -11); // gravitational constant
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r_squared = dx*dx + dy*dy + dz*dz;
    double r = sqrt(r_squared);
    double force_magnitude = G*p1->mass*p2->mass/(r_squared);
    *fx = force_magnitude * dx / r;
    *fy = force_magnitude * dy / r;
    *fz = force_magnitude * dz / r;
}

// Function for updating planet positions and velocities based on computed forces
void update_planets(Planet* planets, int num_planets, double timestep) {
    double fx[num_planets], fy[num_planets], fz[num_planets]; // arrays of forces for each planet
    for (int i = 0; i < num_planets; i++) {
        fx[i] = 0;
        fy[i] = 0;
        fz[i] = 0;
        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double dfx, dfy, dfz;
                compute_gravity_force(&planets[i], &planets[j], &dfx, &dfy, &dfz);
                fx[i] += dfx;
                fy[i] += dfy;
                fz[i] += dfz;
            }
        }
        // Update planet's velocity and position
        planets[i].vx += fx[i]/planets[i].mass * timestep;
        planets[i].vy += fy[i]/planets[i].mass * timestep;
        planets[i].vz += fz[i]/planets[i].mass * timestep;
        planets[i].x += planets[i].vx * timestep;
        planets[i].y += planets[i].vy * timestep;
        planets[i].z += planets[i].vz * timestep;
    }
}

int main() {
    // Instantiate planets
    Planet planets[4];
    // Mercury
    sprintf(planets[0].name, "Mercury");
    planets[0].mass = 3.285*pow(10, 23);
    planets[0].radius = 2440000;
    planets[0].x = 57910000;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 47870;
    planets[0].vz = 0;
    // Venus
    sprintf(planets[1].name, "Venus");
    planets[1].mass = 4.867*pow(10, 24);
    planets[1].radius = 6052000;
    planets[1].x = 108200000;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 35020;
    planets[1].vz = 0;
    // Earth
    sprintf(planets[2].name, "Earth");
    planets[2].mass = 5.972*pow(10, 24);
    planets[2].radius = 6371000;
    planets[2].x = 147100000;
    planets[2].y = 0;
    planets[2].z = 0;
    planets[2].vx = 0;
    planets[2].vy = 29780;
    planets[2].vz = 0;
    // Mars
    sprintf(planets[3].name, "Mars");
    planets[3].mass = 6.39*pow(10, 23);
    planets[3].radius = 3390000;
    planets[3].x = 227940000;
    planets[3].y = 0;
    planets[3].z = 0;
    planets[3].vx = 0;
    planets[3].vy = 24070;
    planets[3].vz = 0;

    double timestep = 3600 * 24; // timestep in seconds, 1 day
    double total_time = 3600 * 24 * 365 * 10; // total time simulated, 10 years
    int num_steps = total_time / timestep; // total number of steps in simulation

    // Simulate motion of planets
    for (int i = 0; i < num_steps; i++) {
        printf("Time: %.2f Earth days.\n", i*timestep/(3600*24));
        for (int j = 0; j < 4; j++) {
            printf("%s position: (%.3f, %.3f, %.3f) m\n", planets[j].name, planets[j].x, planets[j].y, planets[j].z);
        }
        printf("\n");
        update_planets(planets, 4, timestep);
    }

    return EXIT_SUCCESS;
}