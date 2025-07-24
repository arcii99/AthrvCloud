//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 6.67e-11 // gravitational constant
#define TIMESTEP 86400 // one day
#define STEPS 365 // number of time steps
#define MASS_EARTH 5.97e24 // mass of Earth
#define MASS_MOON 7.34e22 // mass of Moon
#define DIST_EARTH_MOON 3.84e8 // distance between Earth and Moon

int main()
{
    double earth_pos[2] = {0, 0}; // Earth position at t=0
    double moon_pos[2] = {DIST_EARTH_MOON, 0}; // Moon position at t=0
    double earth_velocity[2] = {0, 0}; // Earth velocity at t=0
    double moon_velocity[2] = {0, -1022}; // Moon velocity at t=0
    double earth_acceleration[2], moon_acceleration[2];
    double force[2]; // force between Earth and Moon
    double distance; // distance between Earth and Moon
    int i;

    printf("Starting simulation...\n");

    for (i = 0; i < STEPS; i++)
    {
        distance = sqrt(pow((moon_pos[0]-earth_pos[0]), 2) + pow((moon_pos[1]-earth_pos[1]), 2));
        force[0] = GRAVITY * MASS_EARTH * MASS_MOON / pow(distance, 2) * (moon_pos[0]-earth_pos[0]) / distance;
        force[1] = GRAVITY * MASS_EARTH * MASS_MOON / pow(distance, 2) * (moon_pos[1]-earth_pos[1]) / distance;

        earth_acceleration[0] = force[0] / MASS_EARTH;
        earth_acceleration[1] = force[1] / MASS_EARTH;
        moon_acceleration[0] = -force[0] / MASS_MOON;
        moon_acceleration[1] = -force[1] / MASS_MOON;

        earth_velocity[0] += earth_acceleration[0] * TIMESTEP;
        earth_velocity[1] += earth_acceleration[1] * TIMESTEP;
        moon_velocity[0] += moon_acceleration[0] * TIMESTEP;
        moon_velocity[1] += moon_acceleration[1] * TIMESTEP;

        earth_pos[0] += earth_velocity[0] * TIMESTEP;
        earth_pos[1] += earth_velocity[1] * TIMESTEP;
        moon_pos[0] += moon_velocity[0] * TIMESTEP;
        moon_pos[1] += moon_velocity[1] * TIMESTEP;

        printf("Day %d: Earth: (%e, %e) Moon: (%e, %e)\n", i+1, earth_pos[0], earth_pos[1], moon_pos[0], moon_pos[1]);
    }

    printf("Simulation complete.\n");

    return 0;
}