//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x;
    double y;
    double vx;
    double vy;
    double mass;
} Body;

int main() {
    srand(time(NULL));

    const double G = 6.6743e-11; // gravitational constant
    const double m_sun = 1.9891e30; // sun's mass
    const double m_earth = 5.9722e24; // earth's mass
    const double m_moon = 7.342e22; // moon's mass
    const double r_earth = 147e9; // earth's distance from the sun
    const double r_moon = 384.4e6; // moon's distance from the earth
    const double v_earth = sqrt(G * m_sun / r_earth); // earth's velocity
    const double v_moon = sqrt(G * (m_earth + m_moon) / r_moon); // moon's velocity

    Body sun = {0, 0, 0, 0, m_sun}; // sun's position and velocity are fixed
    Body earth = {r_earth, 0, 0, v_earth, m_earth}; // earth's initial position and velocity
    Body moon = {r_earth + r_moon, 0, 0, v_earth + v_moon, m_moon}; // moon's initial position and velocity

    const int iterations = 365; // simulate one year

    printf("Simulating the Solar System...\n\n");

    for (int i = 0; i < iterations; i++) {
        double dx_earth_sun = sun.x - earth.x;
        double dy_earth_sun = sun.y - earth.y;
        double dx_moon_earth = earth.x - moon.x;
        double dy_moon_earth = earth.y - moon.y;

        double r_earth_sun = sqrt(dx_earth_sun * dx_earth_sun + dy_earth_sun * dy_earth_sun);
        double r_moon_earth = sqrt(dx_moon_earth * dx_moon_earth + dy_moon_earth * dy_moon_earth);

        double F_earth_sun = G * sun.mass * earth.mass / (r_earth_sun * r_earth_sun);
        double F_moon_earth = G * earth.mass * moon.mass / (r_moon_earth * r_moon_earth);

        double ax_earth = F_earth_sun / earth.mass * dx_earth_sun / r_earth_sun;
        double ay_earth = F_earth_sun / earth.mass * dy_earth_sun / r_earth_sun;
        double ax_moon = F_moon_earth / moon.mass * dx_moon_earth / r_moon_earth;
        double ay_moon = F_moon_earth / moon.mass * dy_moon_earth / r_moon_earth;

        earth.vx += ax_earth;
        earth.vy += ay_earth;

        moon.vx += ax_moon;
        moon.vy += ay_moon;

        earth.x += earth.vx;
        earth.y += earth.vy;

        moon.x += moon.vx;
        moon.y += moon.vy;

        printf("Earth x: %f y: %f\n", earth.x, earth.y);
        printf("Moon x: %f y: %f\n\n", moon.x, moon.y);
    }

    return 0;
}