//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.67e-11 // Gravitational constant
#define TIME_STEP 3600 // Time step of 1 hour

struct Planet {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

// Function to calculate the distance between two planets
double distance(struct Planet p1, struct Planet p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

// Function to calculate the gravitational force between two planets
double gravitational_force(struct Planet p1, struct Planet p2) {
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / (r * r);
}

// Function to update the velocity and position of a planet
void update_planet_velocity_position(struct Planet *p, double fx, double fy, double fz, double time_step) {
    p->vx += fx / p->mass * time_step;
    p->vy += fy / p->mass * time_step;
    p->vz += fz / p->mass * time_step;
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
    p->z += p->vz * time_step;
}

int main() {
    struct Planet earth = {5.97e24, 0, 0, 0, 0, 0, 0};
    struct Planet moon = {7.34e22, 3.84e8, 0, 0, 0, 1022, 0};

    double time = 0;
    double distance_earth_moon = distance(earth, moon);
    double force_earth_moon = gravitational_force(earth, moon);

    printf("====================================\n");
    printf("   PLANET GRAVITY SIMULATION\n");
    printf("====================================\n");

    while(time < 31536000) { // Time for 1 year
        double force_earth_moon = gravitational_force(earth, moon);
        double fx_earth_moon = force_earth_moon * (moon.x - earth.x) / distance_earth_moon;
        double fy_earth_moon = force_earth_moon * (moon.y - earth.y) / distance_earth_moon;
        double fz_earth_moon = force_earth_moon * (moon.z - earth.z) / distance_earth_moon;

        double force_moon_earth = -force_earth_moon;
        double fx_moon_earth = force_moon_earth * (earth.x - moon.x) / distance_earth_moon;
        double fy_moon_earth = force_moon_earth * (earth.y - moon.y) / distance_earth_moon;
        double fz_moon_earth = force_moon_earth * (earth.z - moon.z) / distance_earth_moon;

        update_planet_velocity_position(&earth, fx_earth_moon, fy_earth_moon, fz_earth_moon, TIME_STEP);
        update_planet_velocity_position(&moon, fx_moon_earth, fy_moon_earth, fz_moon_earth, TIME_STEP);

        distance_earth_moon = distance(earth, moon);

        printf("Year: %.2f\n", time / 31536000);
        printf("Distance between Earth and Moon: %.2f km\n", distance_earth_moon / 1000);
        printf("Earth: x=%.2fkm y=%.2fkm z=%.2fkm vx=%.2fm/s vy=%.2fm/s vz=%.2fm/s\n", earth.x / 1000, earth.y / 1000, earth.z / 1000, earth.vx, earth.vy, earth.vz);
        printf("Moon: x=%.2fkm y=%.2fkm z=%.2fkm vx=%.2fm/s vy=%.2fm/s vz=%.2fm/s\n", moon.x / 1000, moon.y / 1000, moon.z / 1000, moon.vx, moon.vy, moon.vz);
        printf("------------------------------------\n");

        time += TIME_STEP;
    }

    printf("Simulation complete!\n");

    return 0;
}