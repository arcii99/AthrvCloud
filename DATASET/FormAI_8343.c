//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define G 6.674E-11 // gravitational constant
#define TIMESTEP 0.1 // length of each timestep
#define STEPS 1000 // number of timesteps to simulate
#define MASS_EARTH 5.972E24 // mass of Earth
#define MASS_MOON 7.342E22 // mass of Moon

int main() {
    double earth_x = 0, earth_y = 0, earth_vx = 0, earth_vy = 0, earth_ax = 0, earth_ay = 0;
    double moon_x = 384400000, moon_y = 0, moon_vx = 0, moon_vy = 1000, moon_ax = 0, moon_ay = 0;
    double distance, force;
    int i;

    for (i = 0; i < STEPS; i++) {
        distance = sqrt(pow(moon_x - earth_x, 2) + pow(moon_y - earth_y, 2));
        force = G * MASS_EARTH * MASS_MOON / pow(distance, 2);
        earth_ax = force / MASS_EARTH * (moon_x - earth_x) / distance;
        earth_ay = force / MASS_EARTH * (moon_y - earth_y) / distance;
        moon_ax = -force / MASS_MOON * (moon_x - earth_x) / distance;
        moon_ay = -force / MASS_MOON * (moon_y - earth_y) / distance;

        earth_vx += earth_ax * TIMESTEP;
        earth_vy += earth_ay * TIMESTEP;
        moon_vx += moon_ax * TIMESTEP;
        moon_vy += moon_ay * TIMESTEP;

        earth_x += earth_vx * TIMESTEP;
        earth_y += earth_vy * TIMESTEP;
        moon_x += moon_vx * TIMESTEP;
        moon_y += moon_vy * TIMESTEP;

        printf("Step %d: Earth x=%f y=%f Moon x=%f y=%f\n", i+1, earth_x, earth_y, moon_x, moon_y);
    }

    return 0;
}