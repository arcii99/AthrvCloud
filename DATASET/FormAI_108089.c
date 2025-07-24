//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    // The Sun
    double sun_x = 0;
    double sun_y = 0;
    double sun_vx = 0;
    double sun_vy = 0;
    double sun_mass = 333000;

    // Romeo
    double romeo_x = 0.39;
    double romeo_y = 0;
    double romeo_vx = 0;
    double romeo_vy = 47.4;
    double romeo_mass = 0.055;

    // Juliet
    double juliet_x = 0.72;
    double juliet_y = 0;
    double juliet_vx = 0;
    double juliet_vy = 35.0;
    double juliet_mass = 0.046;

    // Simulation variables
    double delta_t = 0.01;
    double G = 6.67e-11;
    double dist_romeo_to_sun, dist_juliet_to_sun, dist_romeo_to_juliet;
    double f_gravity_romeo, f_gravity_juliet;
    double a_gravity_romeo, a_gravity_juliet;

    // Simulation loop
    int t;
    for (t = 0; t < 1000; t++) {
        // Calculate distance between objects
        dist_romeo_to_sun = sqrt(pow(romeo_x - sun_x, 2) + pow(romeo_y - sun_y, 2));
        dist_juliet_to_sun = sqrt(pow(juliet_x - sun_x, 2) + pow(juliet_y - sun_y, 2));
        dist_romeo_to_juliet = sqrt(pow(romeo_x - juliet_x, 2) + pow(romeo_y - juliet_y, 2));

        // Calculate gravitational forces
        f_gravity_romeo = G * romeo_mass * sun_mass / pow(dist_romeo_to_sun, 2);
        f_gravity_juliet = G * juliet_mass * sun_mass / pow(dist_juliet_to_sun, 2);

        // Add force vectors for Romeo
        a_gravity_romeo = f_gravity_romeo / romeo_mass;
        double theta_romeo = atan2(romeo_y - sun_y, romeo_x - sun_x);
        double a_gravity_romeo_x = -a_gravity_romeo * cos(theta_romeo);
        double a_gravity_romeo_y = -a_gravity_romeo * sin(theta_romeo);
        romeo_vx += a_gravity_romeo_x * delta_t;
        romeo_vy += a_gravity_romeo_y * delta_t;

        // Add force vectors for Juliet
        a_gravity_juliet = f_gravity_juliet / juliet_mass;
        double theta_juliet = atan2(juliet_y - sun_y, juliet_x - sun_x);
        double a_gravity_juliet_x = -a_gravity_juliet * cos(theta_juliet);
        double a_gravity_juliet_y = -a_gravity_juliet * sin(theta_juliet);
        juliet_vx += a_gravity_juliet_x * delta_t;
        juliet_vy += a_gravity_juliet_y * delta_t;

        // Move objects
        romeo_x += romeo_vx * delta_t;
        romeo_y += romeo_vy * delta_t;
        juliet_x += juliet_vx * delta_t;
        juliet_y += juliet_vy * delta_t;

        // Print out current positions
        printf("Romeo: (%f, %f)\n", romeo_x, romeo_y);
        printf("Juliet: (%f, %f)\n", juliet_x, juliet_y);
    }

    return 0;
}