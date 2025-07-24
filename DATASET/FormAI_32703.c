//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Planet{
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

void calculate_forces(Planet* planets, int num_planets) {
    const double G = 6.6743e-11;
    int i, j;
    for (i = 0; i < num_planets; i++) {
        Planet* planet_i = &planets[i];
        double total_fx = 0;
        double total_fy = 0;
        double total_fz = 0;
        for (j = 0; j < num_planets; j++) {
            if (i == j) {
                continue;
            }
            Planet* planet_j = &planets[j];
            double dx = planet_i->x - planet_j->x;
            double dy = planet_i->y - planet_j->y;
            double dz = planet_i->z - planet_j->z;
            double distance = sqrt(dx*dx + dy*dy + dz*dz);
            double force = G * planet_i->mass * planet_j->mass / (distance*distance);
            total_fx += force * (-dx/distance);
            total_fy += force * (-dy/distance);
            total_fz += force * (-dz/distance); 
        }
        planet_i->vx += total_fx / planet_i->mass;
        planet_i->vy += total_fy / planet_i->mass;
        planet_i->vz += total_fz / planet_i->mass;
    }
}

void update_positions(Planet* planets, int num_planets, double dt) {
    int i;
    for (i = 0; i < num_planets; i++) {
        Planet* planet = &planets[i];
        planet->x += planet->vx * dt;
        planet->y += planet->vy * dt;
        planet->z += planet->vz * dt;
    }
}

void print_planet(Planet* planet) {
    printf("Mass: %g kg\n", planet->mass);
    printf("Position: (%g, %g, %g) m\n", planet->x, planet->y, planet->z);
    printf("Velocity: (%g, %g, %g) m/s\n\n", planet->vx, planet->vy, planet->vz);
}

int main() {
    Planet planets[] = {
        {5.972e24, 0, 0, 0, 0, 0, 0},
        {7.342e22, 384400000, 0, 0, 0, 1022, 0},
        {0.07346e24, 0, 0, -6.371e6, 11000, 0, 0}
    };
    int num_planets = sizeof(planets) / sizeof(Planet);
    double dt = 1;
    int num_steps = 86400;
    int i, j;
    for (i = 0; i < num_steps; i++) {
        printf("Step %d:\n", i+1);
        for (j = 0; j < num_planets; j++) {
            printf("Planet %d:\n", j+1);
            print_planet(&planets[j]);
        }
        calculate_forces(planets, num_planets);
        update_positions(planets, num_planets, dt);
    }
    return 0;
}