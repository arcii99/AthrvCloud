//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: excited
#include <stdio.h>
#include <math.h>

// Defining constants for the simulation
#define G 6.674 * pow(10, -11)
#define DT 100000

int main() {
    // Defining initial values for the solar system
    double sun_mass = 1.989 * pow(10, 30);
    double earth_mass = 5.972 * pow(10, 24);
    double moon_mass = 7.342 * pow(10, 22);

    double sun_pos_x = 0, sun_pos_y = 0, sun_vel_x = 0, sun_vel_y = 0;
    double earth_pos_x = -147095000000, earth_pos_y = 0, earth_vel_x = 0, earth_vel_y = 30300;
    double moon_pos_x = -147095000000 + 384400000, moon_pos_y = 0, moon_vel_x = 0, moon_vel_y = 30300 + 1022;

    double distance, accel_x, accel_y;

    for (int i = 0; i < 1000000; i++) {
        // Calculating distance between earth and sun
        distance = sqrt(pow(sun_pos_x - earth_pos_x, 2) + pow(sun_pos_y - earth_pos_y, 2));

        // Calculating acceleration experienced by earth
        accel_x = (G * sun_mass * (sun_pos_x - earth_pos_x)) / pow(distance, 3);
        accel_y = (G * sun_mass * (sun_pos_y - earth_pos_y)) / pow(distance, 3);

        // Updating velocity and position of earth
        earth_vel_x += accel_x * DT;
        earth_vel_y += accel_y * DT;

        earth_pos_x += earth_vel_x * DT;
        earth_pos_y += earth_vel_y * DT;

        // Calculating distance between moon and earth
        distance = sqrt(pow(earth_pos_x - moon_pos_x, 2) + pow(earth_pos_y - moon_pos_y, 2));

        // Calculating acceleration experienced by moon
        accel_x = (G * earth_mass * (earth_pos_x - moon_pos_x)) / pow(distance, 3);
        accel_y = (G * earth_mass * (earth_pos_y - moon_pos_y)) / pow(distance, 3);

        // Updating velocity and position of moon
        moon_vel_x += accel_x * DT;
        moon_vel_y += accel_y * DT;

        moon_pos_x += moon_vel_x * DT;
        moon_pos_y += moon_vel_y * DT;

        // Printing position of earth and moon
        printf("Earth Position: (%lf, %lf)\n", earth_pos_x, earth_pos_y);
        printf("Moon Position: (%lf, %lf)\n", moon_pos_x, moon_pos_y);
    }

    return 0;
}