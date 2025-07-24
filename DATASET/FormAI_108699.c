//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant
#define MASS_EARTH 5.972e24 // Mass of Earth
#define RADIUS_EARTH 6371000 // Radius of Earth
#define TIME_STEP 1 // Time step in seconds

typedef struct Planet {
    double mass; // Mass in kg
    double x, y, z; // Position in m
    double vx, vy, vz; // Velocity in m/s
} Planet;

int main() {
    Planet earth = {
        .mass = MASS_EARTH,
        .x = 0,
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 0,
        .vz = 0
    };

    Planet moon = {
        .mass = 7.342e22,
        .x = 384400000,
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 1022,
        .vz = 0
    };

    printf("Starting gravity simulation...\n");
    for (int t=0; t<86400*365*2; t+=TIME_STEP) {
        // Calculate distance between Earth and Moon
        double dx = moon.x - earth.x;
        double dy = moon.y - earth.y;
        double dz = moon.z - earth.z;
        double distance = sqrt(dx*dx + dy*dy + dz*dz);

        // Calculate force between Earth and Moon
        double force = G * earth.mass * moon.mass / distance / distance;

        // Calculate components of force in x, y, and z directions
        double fx = force * dx / distance;
        double fy = force * dy / distance;
        double fz = force * dz / distance;

        // Update velocities of Earth and Moon
        earth.vx += fx / earth.mass * TIME_STEP;
        earth.vy += fy / earth.mass * TIME_STEP;
        earth.vz += fz / earth.mass * TIME_STEP;

        moon.vx -= fx / moon.mass * TIME_STEP;
        moon.vy -= fy / moon.mass * TIME_STEP;
        moon.vz -= fz / moon.mass * TIME_STEP;

        // Update positions of Earth and Moon
        earth.x += earth.vx * TIME_STEP;
        earth.y += earth.vy * TIME_STEP;
        earth.z += earth.vz * TIME_STEP;

        moon.x += moon.vx * TIME_STEP;
        moon.y += moon.vy * TIME_STEP;
        moon.z += moon.vz * TIME_STEP;
    }

    printf("Earth position: (%.0f, %.0f, %.0f)\n", earth.x, earth.y, earth.z);
    printf("Moon position: (%.0f, %.0f, %.0f)\n", moon.x, moon.y, moon.z);
    printf("Distance between Earth and Moon: %.0f km\n", (sqrt(pow(moon.x-earth.x, 2) + pow(moon.y-earth.y, 2) + pow(moon.z-earth.z, 2))) / 1000);
    return 0;
}