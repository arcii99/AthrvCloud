//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

// Define constants and variables
#define GRAV_CONST 6.674e-11
#define TIME_STEP 1e-2
#define SIM_TIME 10000
#define EARTH_MASS 5.974e24
#define MOON_MASS 7.348e22
#define EARTH_RADIUS 6.37e6
#define MOON_RADIUS 1.737e6
#define DISTANCE 3.84e8
#define INIT_SPEED 1022
#define INIT_ANGLE 68.75

double earth_x, earth_y, moon_x, moon_y, vx, vy;

int main() {
    // Initial conditions
    earth_x = 0;
    earth_y = 0;
    moon_x = DISTANCE;
    moon_y = 0;
    vx = INIT_SPEED * cos(INIT_ANGLE * M_PI / 180);
    vy = INIT_SPEED * sin(INIT_ANGLE * M_PI / 180);

    double earth_f, moon_f, earth_a, moon_a, earth_ax, earth_ay, moon_ax, moon_ay;
    double earth_dist, moon_dist;

    for (int t=0; t<=SIM_TIME; t++) {
        // Calculate distance between Earth and Moon
        earth_dist = sqrt(pow(moon_x-earth_x, 2) + pow(moon_y-earth_y, 2));
        moon_dist = earth_dist;

        // Calculate force and acceleration of Earth and Moon
        earth_f = GRAV_CONST * EARTH_MASS * MOON_MASS / pow(earth_dist, 2);
        moon_f = earth_f;

        earth_a = earth_f / EARTH_MASS;
        moon_a = moon_f / MOON_MASS;

        // Calculate components of acceleration for Earth and Moon
        earth_ax = earth_a * (moon_x - earth_x) / earth_dist;
        earth_ay = earth_a * (moon_y - earth_y) / earth_dist;
        moon_ax = moon_a * (earth_x - moon_x) / moon_dist;
        moon_ay = moon_a * (earth_y - moon_y) / moon_dist;

        // Update velocity and position of Earth and Moon
        vx += (earth_ax + moon_ax) * TIME_STEP;
        vy += (earth_ay + moon_ay) * TIME_STEP;
        earth_x += vx * TIME_STEP;
        earth_y += vy * TIME_STEP;
        moon_x -= vx * TIME_STEP;
        moon_y -= vy * TIME_STEP;

        printf("Time: %d seconds\n", t);
        printf("Earth position: (%.1fm, %.1fm)\n", earth_x, earth_y);
        printf("Moon position: (%.1fm, %.1fm)\n", moon_x, moon_y);
        printf("\n");
    }

    return 0;
}