//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ada Lovelace
/* Ada Lovelace Solar System Simulation */
#include<stdio.h>
#include<stdlib.h>

int main ()
{
    float time = 0.0;
    float dt = 0.01;

    float sun_mass = 1.989 * pow(10,30);
    float earth_mass = 5.972 * pow(10,24);
    float dist_earth_sun = 1.496 * pow(10,11);
    float G = 6.67 * pow(10,-11);

    float earth_x = dist_earth_sun;
    float earth_y = 0.0;
    float earth_vx = 0.0;
    float earth_vy = 29783.0;

    float sun_x = 0.0;
    float sun_y = 0.0;
    float sun_vx = 0.0;
    float sun_vy = 0.0;

    float earth_ax;
    float earth_ay;
    float sun_ax;
    float sun_ay;

    while (1)
    {
        // Calculate acceleration of Earth and Sun
        float d = sqrt(pow(earth_x - sun_x, 2) + pow(earth_y - sun_y, 2));
        earth_ax = G * sun_mass * (sun_x - earth_x) / pow(d, 3);
        earth_ay = G * sun_mass * (sun_y - earth_y) / pow(d, 3);
        sun_ax = -earth_ax * earth_mass / sun_mass;
        sun_ay = -earth_ay * earth_mass / sun_mass;

        // Update Earth and Sun positions and velocities
        earth_vx += earth_ax * dt;
        earth_vy += earth_ay * dt;
        sun_vx += sun_ax * dt;
        sun_vy += sun_ay * dt;
        earth_x += earth_vx * dt;
        earth_y += earth_vy * dt;
        sun_x += sun_vx * dt;
        sun_y += sun_vy * dt;

        // Update time
        time += dt;

        // Print current time and Earth position
        printf("Time: %f\n", time);
        printf("Earth position: (%f, %f)\n", earth_x, earth_y);
        printf("Sun position: (%f, %f)\n", sun_x, sun_y);

        // Exit loop if Earth goes too far away from Sun
        if (d > 2 * dist_earth_sun)
        {
            printf("Earth has escaped the Solar System!\n");
            break;
        }
    }

    return 0;
}