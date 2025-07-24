//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONSTANT 6.674e-11 // Gravitational constant in m^3/(kg*s^2)

typedef struct {
    double x, y, z; // Coordinates of the planet in m
    double mass; // Mass of the planet in kg
    double vx, vy, vz; // Velocity components of the planet in m/s
} Planet;

typedef struct {
    double x, y, z; // Coordinates of the point in m
} Point;

void calculate_gravity(Planet *p1, Planet *p2, double *fx, double *fy, double *fz) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = (G_CONSTANT * p1->mass * p2->mass) / (distance * distance);
    *fx = force * dx / distance;
    *fy = force * dy / distance;
    *fz = force * dz / distance;
}

void update_planet(Planet *p, double fx, double fy, double fz, double dt) {
    p->vx += fx * dt / p->mass;
    p->vy += fy * dt / p->mass;
    p->vz += fz * dt / p->mass;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

double calculate_distance(Point *p1, Point *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    // Define planets
    int num_planets = 2;
    Planet planets[num_planets];

    // Set planet 1
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].mass = 5.97e24; // Mass of Earth in kg
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;

    // Set planet 2
    planets[1].x = 384400000; // Distance from Earth to Moon in m
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].mass = 7.35e22; // Mass of Moon in kg
    planets[1].vx = 0;
    planets[1].vy = 1022; // Speed of Moon in m/s
    planets[1].vz = 0;

    // Initialize simulation variables
    double simulation_time = 86400; // Simulation time in seconds (1 day)
    double time_step = 1; // Time step in seconds
    double current_time = 0; // Current time in seconds

    // Print initial positions
    printf("Planet 1: (%f, %f, %f)\n", planets[0].x, planets[0].y, planets[0].z);
    printf("Planet 2: (%f, %f, %f)\n", planets[1].x, planets[1].y, planets[1].z);

    // Simulate gravity
    while (current_time < simulation_time) {
        // Calculate forces
        double fx, fy, fz;
        calculate_gravity(&planets[0], &planets[1], &fx, &fy, &fz);

        // Update planets
        update_planet(&planets[0], -fx, -fy, -fz, time_step);
        update_planet(&planets[1], fx, fy, fz, time_step);

        // Print new positions
        printf("Planet 1: (%f, %f, %f)\n", planets[0].x, planets[0].y, planets[0].z);
        printf("Planet 2: (%f, %f, %f)\n", planets[1].x, planets[1].y, planets[1].z);

        // Check if planets have collided
        double distance = calculate_distance((Point *)&planets[0], (Point *)&planets[1]);
        if (distance < 1737100) { // Diameter of Moon in m
            printf("Collision detected!\n");
            break;
        }

        // Update time
        current_time += time_step;
    }

    return 0;
}