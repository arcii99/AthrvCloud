//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational Constant
#define TIMESTEP 3600 // Timestep = 1 hour

int main()
{
    // Initial conditions for the solar system
    // Units used: m, kg, s for length, mass and time
    // Initial time: t = 0
    double sun_mass = 1.989e30;
    double sun_x = 0;
    double sun_y = 0;
    double sun_z = 0;
    double sun_vx = 0;
    double sun_vy = 0;
    double sun_vz = 0;

    double earth_mass = 5.972e24;
    double earth_x = 147.09e9;
    double earth_y = 0;
    double earth_z = 0;
    double earth_vx = 0;
    double earth_vy = 29.29e3;
    double earth_vz = 0;

    double moon_mass = 7.342e22;
    double moon_x = 147.1e9;
    double moon_y = 0;
    double moon_z = 0;
    double moon_vx = 0;
    double moon_vy = 29.29e3 + 1.02e3;
    double moon_vz = 0;

    // Simulation Parameters
    double time = 0;
    double x, y, z, vx, vy, vz, dx, dy, dz, r, a, ax, ay, az;
    while (time < 31557600) // 1 year simulation
    {
        // Calculate Earth's acceleration due to the sun
        dx = sun_x - earth_x;
        dy = sun_y - earth_y;
        dz = sun_z - earth_z;
        r = sqrt(dx*dx + dy*dy + dz*dz);
        a = G * sun_mass / (r*r);
        ax = a * dx / r;
        ay = a * dy / r;
        az = a * dz / r;

        // Update Earth's velocity and position
        earth_vx += ax * TIMESTEP;
        earth_vy += ay * TIMESTEP;
        earth_vz += az * TIMESTEP;
        earth_x += earth_vx * TIMESTEP;
        earth_y += earth_vy * TIMESTEP;
        earth_z += earth_vz * TIMESTEP;

        // Calculate Moon's acceleration due to the Earth and Sun
        dx = earth_x - moon_x;
        dy = earth_y - moon_y;
        dz = earth_z - moon_z;
        r = sqrt(dx*dx + dy*dy + dz*dz);
        a = G * earth_mass / (r*r);
        ax = a * dx / r;
        ay = a * dy / r;
        az = a * dz / r;

        dx = sun_x - moon_x;
        dy = sun_y - moon_y;
        dz = sun_z - moon_z;
        r = sqrt(dx*dx + dy*dy + dz*dz);
        a += G * sun_mass / (r*r);
        ax += a * dx / r;
        ay += a * dy / r;
        az += a * dz / r;

        // Update Moon's velocity and position
        moon_vx += ax * TIMESTEP;
        moon_vy += ay * TIMESTEP;
        moon_vz += az * TIMESTEP;
        moon_x += moon_vx * TIMESTEP;
        moon_y += moon_vy * TIMESTEP;
        moon_z += moon_vz * TIMESTEP;

        // Print the positions of Earth and Moon at the end of every day
        if (fmod(time, 86400) == 0)
        {
            printf("Time: %f days\n", time / 86400);
            printf("Earth: (%e, %e, %e) m\n", earth_x, earth_y, earth_z);
            printf("Moon:  (%e, %e, %e) m\n", moon_x, moon_y, moon_z);
            printf("\n");
        }

        // Update time
        time += TIMESTEP;
    }

    return 0;
}