//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define AU 149.6e6    // Earth's distance from the Sun in kilometers
#define G 6.67e-11     // Universal gravitational constant in N*(m/kg)^2

typedef struct {
    double x, y, z;
} vector;

typedef struct {
    vector pos, vel;
    double mass;
} body;

int main() {
    body sun, earth, moon;
    double dt = 86400;    // Time step in seconds, equivalent to one day
    int steps = 365;      // Number of time steps for one year
    int i;

    // Define the properties of the Sun, Earth, and Moon
    sun.pos.x = sun.pos.y = sun.pos.z = sun.vel.x = sun.vel.y = sun.vel.z = sun.mass = 0;
    earth.pos.x = AU;
    earth.pos.y = earth.pos.z = earth.vel.x = earth.vel.z = 0;
    earth.vel.y = sqrt(G * sun.mass / AU);
    earth.mass = 5.97e24;
    moon.pos.x = AU + 384400;
    moon.pos.y = moon.pos.z = 0;
    moon.vel.x = earth.vel.x + sqrt(G * earth.mass / 384400);
    moon.vel.y = earth.vel.y;
    moon.vel.z = 0;
    moon.mass = 7.34e22;

    // Simulate the Solar System for one year
    for (i = 0; i < steps; i++) {
        // Calculate the gravitational forces on each body
        vector f_earth, f_moon;
        f_earth.x = f_earth.y = f_earth.z = f_moon.x = f_moon.y = f_moon.z = 0;
        double dist_earth = sqrt(pow(earth.pos.x - sun.pos.x, 2) + pow(earth.pos.y - sun.pos.y, 2) + pow(earth.pos.z - sun.pos.z, 2));
        double dist_moon = sqrt(pow(moon.pos.x - earth.pos.x, 2) + pow(moon.pos.y - earth.pos.y, 2) + pow(moon.pos.z - earth.pos.z, 2));
        double f = G * earth.mass * sun.mass / pow(dist_earth, 2);
        f_earth.x = -f * (earth.pos.x - sun.pos.x) / dist_earth;
        f_earth.y = -f * (earth.pos.y - sun.pos.y) / dist_earth;
        f_earth.z = -f * (earth.pos.z - sun.pos.z) / dist_earth;
        f = G * moon.mass * earth.mass / pow(dist_moon, 2);
        f_moon.x = -f * (moon.pos.x - earth.pos.x) / dist_moon;
        f_moon.y = -f * (moon.pos.y - earth.pos.y) / dist_moon;
        f_moon.z = -f * (moon.pos.z - earth.pos.z) / dist_moon;

        // Update each body's position and velocity
        vector a_earth, a_moon;
        a_earth.x = f_earth.x / earth.mass;
        a_earth.y = f_earth.y / earth.mass;
        a_earth.z = f_earth.z / earth.mass;
        a_moon.x = f_moon.x / moon.mass;
        a_moon.y = f_moon.y / moon.mass;
        a_moon.z = f_moon.z / moon.mass;
        earth.vel.x += a_earth.x * dt;
        earth.vel.y += a_earth.y * dt;
        earth.vel.z += a_earth.z * dt;
        moon.vel.x += a_moon.x * dt;
        moon.vel.y += a_moon.y * dt;
        moon.vel.z += a_moon.z * dt;
        earth.pos.x += earth.vel.x * dt;
        earth.pos.y += earth.vel.y * dt;
        earth.pos.z += earth.vel.z * dt;
        moon.pos.x += moon.vel.x * dt;
        moon.pos.y += moon.vel.y * dt;
        moon.pos.z += moon.vel.z * dt;

        // Print the current positions of the three bodies
        printf("Step %d:\n", i + 1);
        printf("Sun: (%g, %g, %g)\n", sun.pos.x, sun.pos.y, sun.pos.z);
        printf("Earth: (%g, %g, %g)\n", earth.pos.x, earth.pos.y, earth.pos.z);
        printf("Moon: (%g, %g, %g)\n", moon.pos.x, moon.pos.y, moon.pos.z);
    }

    return 0;
}