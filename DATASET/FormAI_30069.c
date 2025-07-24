//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.67430e-11 // m^3/(kg*s^2)

struct body {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
};

typedef struct body Body;

int main() {
    Body sun = {0, 0, 0, 0, 0, 0, 1.9885e30}; // Sun
    Body earth = {1.4710e11, 0, 0, 0, 3.0287e4, 0, 5.9736e24}; // Earth
    Body moon = {1.4710e11 + 3.844e8, 0, 0, 0, 3.0287e4 + 1.022e3, 0, 7.342e22}; // Moon

    double time_step = 3600; // seconds
    double time_limit = 365.25 * 24 * 3600; // seconds
    double time_elapsed = 0;

    while (time_elapsed < time_limit) {
        double dx_earth_sun = sun.x - earth.x;
        double dy_earth_sun = sun.y - earth.y;
        double dz_earth_sun = sun.z - earth.z;
        double dx_moon_earth = earth.x - moon.x;
        double dy_moon_earth = earth.y - moon.y;
        double dz_moon_earth = earth.z - moon.z;

        double distance_earth_sun = sqrt(dx_earth_sun * dx_earth_sun + dy_earth_sun * dy_earth_sun + dz_earth_sun * dz_earth_sun);
        double distance_moon_earth = sqrt(dx_moon_earth * dx_moon_earth + dy_moon_earth * dy_moon_earth + dz_moon_earth * dz_moon_earth);

        double force_earth_sun = GRAVITY_CONSTANT * sun.mass * earth.mass / (distance_earth_sun * distance_earth_sun);
        double force_moon_earth = GRAVITY_CONSTANT * earth.mass * moon.mass / (distance_moon_earth * distance_moon_earth);

        double ax_earth_sun = force_earth_sun * dx_earth_sun / distance_earth_sun / earth.mass;
        double ay_earth_sun = force_earth_sun * dy_earth_sun / distance_earth_sun / earth.mass;
        double az_earth_sun = force_earth_sun * dz_earth_sun / distance_earth_sun / earth.mass;
        double ax_moon_earth = force_moon_earth * dx_moon_earth / distance_moon_earth / moon.mass;
        double ay_moon_earth = force_moon_earth * dy_moon_earth / distance_moon_earth / moon.mass;
        double az_moon_earth = force_moon_earth * dz_moon_earth / distance_moon_earth / moon.mass;

        earth.vx += (ax_earth_sun - ax_moon_earth) * time_step;
        earth.vy += (ay_earth_sun - ay_moon_earth) * time_step;
        earth.vz += (az_earth_sun - az_moon_earth) * time_step;
        moon.vx += (ax_moon_earth) * time_step;
        moon.vy += (ay_moon_earth) * time_step;
        moon.vz += (az_moon_earth) * time_step;

        earth.x += earth.vx * time_step;
        earth.y += earth.vy * time_step;
        earth.z += earth.vz * time_step;
        moon.x += moon.vx * time_step;
        moon.y += moon.vy * time_step;
        moon.z += moon.vz * time_step;

        time_elapsed += time_step;
    }

    printf("Earth's final position: (%g, %g, %g)\n", earth.x, earth.y, earth.z);
    printf("Moon's final position: (%g, %g, %g)\n", moon.x, moon.y, moon.z);

    return 0;
}