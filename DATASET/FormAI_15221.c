//FormAI DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define GRAV_CONST 6.67408e-11
#define MASS_EARTH 5.972e24

// Define particle struct
typedef struct {
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

// Define function to calculate force between two particles
double calc_force(Particle p1, Particle p2) {
    double r = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
    double force = GRAV_CONST * p1.mass * p2.mass / pow(r, 2);
    return force;
}

// Define function to update the velocity and position of a particle
void update_particle(Particle *p, double time_step, double force_x, double force_y, double force_z) {
    // Calculate acceleration
    double acceleration_x = force_x / p->mass;
    double acceleration_y = force_y / p->mass;
    double acceleration_z = force_z / p->mass;

    // Update velocity
    p->vx += acceleration_x * time_step;
    p->vy += acceleration_y * time_step;
    p->vz += acceleration_z * time_step;

    // Update position
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
    p->z += p->vz * time_step;
}

int main() {
    // Initialize particles
    Particle earth = {MASS_EARTH, 6378.1e3, 0, 0, 0, 0, 0, 0};
    Particle moon = {7.342e22, 1737.4e3, 384.4e6, 0, 0, 0, 1022, 0};
    Particle sun = {1.989e30, 696340e3, 0, 0, 0, 0, 0, 0};

    // Set time step and simulation time
    double dt = 60;
    double t = 0;
    const double t_max = 86400 * 365;

    // Run simulation
    while (t < t_max) {
        // Calculate force between particles
        double force_earth_moon = calc_force(earth, moon);
        double force_moon_earth = -force_earth_moon;
        double force_earth_sun = calc_force(earth, sun);
        double force_sun_earth = -force_earth_sun;
        double force_moon_sun = calc_force(moon, sun);
        double force_sun_moon = -force_moon_sun;

        // Update particles
        update_particle(&earth, dt, force_earth_moon + force_earth_sun, 0, 0);
        update_particle(&moon, dt, force_moon_earth + force_moon_sun, 0, 0);
        update_particle(&sun, dt, force_sun_earth + force_sun_moon, 0, 0);

        // Print positions of particles in a surrealistic style
        printf("The earth was found %f meters %s away from its original position. \n", earth.x, (earth.x > 0) ? "above" : "below");
        printf("The moon was found %f meters %s away from its original position. \n", moon.x, (moon.x > 384.4e6) ? "above" : "below");
        printf("The sun was found %f meters %s away from its original position. \n", sun.x, (sun.x > 0) ? "above" : "below");

        t += dt;
    }

    return 0;
}