//FormAI DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11

typedef struct Object {
    double mass;
    double radius;
    double position[3];
    double velocity[3];
} Object;

int main() {
    Object sun = {1.989e30, 696340e3, {0, 0, 0}, {0, 0, 0}}; // Sun
    Object earth = {5.972e24, 6.371e6, {1.496e11, 0, 0}, {0, 2.9783e4, 0}}; // Earth
    Object moon = {7.342e22, 1.737e6, {1.496e11 + 3.844e8, 0, 0}, {0, 2.9783e4 + 1.022e3, 0}}; // Moon

    double timestep = 60 * 60 * 24; // 1 day time step
    double time = 0;

    while (1) {
        // Compute gravitational force on Earth and Moon by the Sun
        double sun_earth_force[3], sun_moon_force[3];
        double sun_earth_distance = sqrt(pow(earth.position[0] - sun.position[0], 2) + pow(earth.position[1] - sun.position[1], 2) + pow(earth.position[2] - sun.position[2], 2));
        double sun_moon_distance = sqrt(pow(moon.position[0] - sun.position[0], 2) + pow(moon.position[1] - sun.position[1], 2) + pow(moon.position[2] - sun.position[2], 2));
        for (int i = 0; i < 3; i++) {
            sun_earth_force[i] = G * sun.mass * earth.mass * (earth.position[i] - sun.position[i]) / pow(sun_earth_distance, 3);
            sun_moon_force[i] = G * sun.mass * moon.mass * (moon.position[i] - sun.position[i]) / pow(sun_moon_distance, 3);
        }

        // Compute gravitational force on Moon by the Earth
        double earth_moon_force[3];
        double earth_moon_distance = sqrt(pow(moon.position[0] - earth.position[0], 2) + pow(moon.position[1] - earth.position[1], 2) + pow(moon.position[2] - earth.position[2], 2));
        for (int i = 0; i < 3; i++) {
            earth_moon_force[i] = G * earth.mass * moon.mass * (moon.position[i] - earth.position[i]) / pow(earth_moon_distance, 3);
        }

        // Update Earth and Moon velocities and positions
        for (int i = 0; i < 3; i++) {
            earth.velocity[i] += (sun_earth_force[i] / earth.mass + earth_moon_force[i] / earth.mass) * timestep;
            moon.velocity[i] += (sun_moon_force[i] / moon.mass - earth_moon_force[i] / moon.mass) * timestep;
            earth.position[i] += earth.velocity[i] * timestep;
            moon.position[i] += moon.velocity[i] * timestep;
        }

        // Print current positions of Earth and Moon
        printf("Time: %.2f days, Earth position: (%.2f, %.2f, %.2f), Moon position: (%.2f, %.2f, %.2f)\n", time / (60 * 60 * 24), earth.position[0], earth.position[1], earth.position[2], moon.position[0], moon.position[1], moon.position[2]);

        if (earth.position[1] < 0) {
            break; // Simulation ends when Earth hits the Sun and doesn't bounce back
        }

        time += timestep;
    }

    return 0;
}