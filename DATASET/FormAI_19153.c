//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Structure to store the properties of each planet
typedef struct {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

// Function to calculate the gravitational force between two planets
double gravitational_force(Planet p1, Planet p2) {
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / pow(r, 2);
}

// Function to calculate the gravitational force vector between two planets
void gravitational_force_vector(Planet p1, Planet p2, double *fx, double *fy, double *fz) {
    double r = distance(p1, p2);
    double f = gravitational_force(p1, p2);
    *fx = f * (p2.x - p1.x) / r;
    *fy = f * (p2.y - p1.y) / r;
    *fz = f * (p2.z - p1.z) / r;
}

// Function to update the velocity, position and acceleration of a planet after a time step dt
void update_planet(Planet *planet, double fx, double fy, double fz, double dt) {
    planet->vx += fx / planet->mass * dt;
    planet->vy += fy / planet->mass * dt;
    planet->vz += fz / planet->mass * dt;
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
    planet->z += planet->vz * dt;
}

// Function to simulate the gravity between all planets in the system
void gravity_simulation(Planet *planets, int num_planets, double dt, int step) {
    // Calculate the total force on each planet due to gravitational attraction
    int i, j;
    double fx, fy, fz;
    for (i = 0; i < num_planets; i++) {
        fx = fy = fz = 0;
        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                double f_x, f_y, f_z;
                gravitational_force_vector(planets[i], planets[j], &f_x, &f_y, &f_z);
                fx += f_x;
                fy += f_y;
                fz += f_z;
            }
        }
        // Update the velocity, position and acceleration of the planet
        update_planet(&planets[i], fx, fy, fz, dt);
    }
    // Display the position of each planet after the current step
    printf("Step %d:\n", step);
    for (i = 0; i < num_planets; i++) {
        printf("%s: %.2f %.2f %.2f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }
    printf("\n");
    // Recursive call to simulate the simulation for the next time step
    gravity_simulation(planets, num_planets, dt, step + 1);
}

int main() {
    // Initialize the properties of each planet
    Planet planets[2];
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97e24;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    strcpy(planets[1].name, "Moon");
    planets[1].mass = 7.35e22;
    planets[1].x = 384400000;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 1023;
    planets[1].vz = 0;

    // Run the simulation for 100 time steps of 10 seconds each
    double dt = 10;
    int num_planets = 2;
    int step = 1;
    gravity_simulation(planets, num_planets, dt, step);
    
    return 0;
}