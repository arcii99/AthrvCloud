//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

int main()
{
    const double G = 6.67e-11;  // gravitational constant
    const double TIME_STEP = 0.01;  // time step for simulation
    const double MASS_EARTH = 5.97e24;  // mass of the Earth
    const double RADIUS_EARTH = 6.37e6;  // radius of the Earth
    const double ALTITUDE_SAT = 200e3;  // altitude of satellite above Earth's surface
    const double VEL_SAT = sqrt(G * MASS_EARTH / (ALTITUDE_SAT + RADIUS_EARTH));  // velocity of satellite
    const double MASS_SAT = 1000;  // mass of satellite

    double x_sat = RADIUS_EARTH + ALTITUDE_SAT;  // initial x-coordinate of satellite
    double y_sat = 0;  // initial y-coordinate of satellite
    double vx_sat = 0;  // initial x-velocity of satellite
    double vy_sat = VEL_SAT;  // initial y-velocity of satellite
    double ax_sat, ay_sat;  // x- and y- acceleration of satellite
    double x_earth = 0;  // x-coordinate of Earth
    double y_earth = 0;  // y-coordinate of Earth

    while (1)
    {
        // calculate distance between satellite and Earth
        double dx = x_earth - x_sat;
        double dy = y_earth - y_sat;
        double dist = sqrt(dx * dx + dy * dy);

        // calculate gravitational force between satellite and Earth
        double force_mag = G * MASS_SAT * MASS_EARTH / (dist * dist);
        double force_x = force_mag * dx / dist;
        double force_y = force_mag * dy / dist;

        // calculate acceleration of satellite
        ax_sat = force_x / MASS_SAT;
        ay_sat = force_y / MASS_SAT;

        // update velocity of satellite
        vx_sat += ax_sat * TIME_STEP;
        vy_sat += ay_sat * TIME_STEP;

        // update position of satellite
        x_sat += vx_sat * TIME_STEP;
        y_sat += vy_sat * TIME_STEP;

        // check if satellite has crashed into the Earth
        if (dist < RADIUS_EARTH)
        {
            printf("Satellite crashed into Earth\n");
            break;
        }

        // check if satellite has escaped Earth's gravity
        if (sqrt(vx_sat * vx_sat + vy_sat * vy_sat) < sqrt(G * MASS_EARTH / RADIUS_EARTH))
        {
            printf("Satellite escaped Earth's gravity\n");
            break;
        }

        // print current position of satellite
        printf("Satellite position: (%.2f, %.2f)\n", x_sat, y_sat);
    }

    return 0;
}