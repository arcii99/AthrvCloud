//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    double G = 6.67430e-11; // gravitational constant

    double sun_mass = 1.989e+30; // mass of the sun
    double earth_mass = 5.97e+24; // mass of the earth
    double moon_mass = 7.3477e+22; // mass of the moon

    double sun_radius = 695700.0; // radius of the sun
    double earth_radius = 6371.0; // radius of the earth
    double moon_radius = 1737.0; // radius of the moon

    double earth_dist = 147095000000.0; // distance between earth and sun
    double moon_dist = 384400000.0; // distance between moon and earth

    // calculate the gravitational forces
    double force = G * sun_mass * earth_mass / (earth_dist * earth_dist);
    double moon_force = G * earth_mass * moon_mass / (moon_dist * moon_dist);

    // calculate the accelerations
    double acceleration = force / earth_mass;
    double moon_acceleration = moon_force / moon_mass;

    // calculate the velocities
    double velocity = sqrt(acceleration * earth_dist * 2);
    double moon_velocity = sqrt(moon_acceleration * moon_dist * 2);

    // calculate the periods
    double period = sqrt((4 * M_PI * M_PI * earth_dist * earth_dist * earth_dist) / (G * sun_mass));
    double moon_period = sqrt((4 * M_PI * M_PI * moon_dist * moon_dist * moon_dist) / (G * earth_mass));

    // print the results
    printf("The gravitational force between the earth and sun is %.3fN\n", force);
    printf("The gravitational force between the earth and moon is %.3fN\n", moon_force);
    printf("The acceleration of the earth due to the sun's gravity is %.3fm/s^2\n", acceleration);
    printf("The acceleration of the moon due to the earth's gravity is %.3fm/s^2\n", moon_acceleration);
    printf("The velocity of the earth in orbit around the sun is %.3fm/s\n", velocity);
    printf("The velocity of the moon in orbit around the earth is %.3fm/s\n", moon_velocity);
    printf("The period of the earth's orbit around the sun is %.3f seconds\n", period);
    printf("The period of the moon's orbit around the earth is %.3f seconds\n", moon_period);

    return 0;
}