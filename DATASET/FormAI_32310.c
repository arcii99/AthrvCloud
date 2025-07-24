//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 6.67430e-11

struct Planet {
    double mass;
    double position[3];
    double velocity[3];
};

typedef struct Planet Planet;

int main() {
    // define planet objects
    Planet earth = {5.972e24, {0, 0, 0}, {0, 0, 0}};
    Planet moon = {7.342e22, {384400000, 0, 0}, {0, 1022, 0}};

    // define simulation parameters
    double time = 0;
    double dt = 60;
    double simulation_time = 2880;

    // calculate initial force vectors
    double force_vec[3];
    double dist_vec[3];
    double distance;
    for (int i = 0; i < 3; i++) {
        dist_vec[i] = moon.position[i] - earth.position[i];
    }
    distance = sqrt(pow(dist_vec[0], 2) + pow(dist_vec[1], 2) + pow(dist_vec[2], 2));
    double force = GRAVITY * earth.mass * moon.mass / pow(distance, 2);
    for (int i = 0; i < 3; i++) {
        force_vec[i] = force * dist_vec[i] / distance;
    }

    // start simulation loop
    while (time < simulation_time) {
        // calculate earth acceleration
        double accel_earth[3];
        for (int i = 0; i < 3; i++) {
            accel_earth[i] = force_vec[i] / earth.mass;
        }

        // calculate moon acceleration
        double accel_moon[3];
        for (int i = 0; i < 3; i++) {
            accel_moon[i] = -force_vec[i] / moon.mass;
        }

        // update velocities
        for (int i = 0; i < 3; i++) {
            earth.velocity[i] += accel_earth[i] * dt;
            moon.velocity[i] += accel_moon[i] * dt;
        }

        // update positions
        for (int i = 0; i < 3; i++) {
            earth.position[i] += earth.velocity[i] * dt;
            moon.position[i] += moon.velocity[i] * dt;
        }

        // calculate force vector for next iteration
        for (int i = 0; i < 3; i++) {
            dist_vec[i] = moon.position[i] - earth.position[i];
        }
        distance = sqrt(pow(dist_vec[0], 2) + pow(dist_vec[1], 2) + pow(dist_vec[2], 2));
        force = GRAVITY * earth.mass * moon.mass / pow(distance, 2);
        for (int i = 0; i < 3; i++) {
            force_vec[i] = force * dist_vec[i] / distance;
        }

        // update simulation time
        time += dt;
    }

    // print final position and velocity of moon
    printf("Final position of moon:\n");
    for (int i = 0; i < 3; i++) {
        printf("%.3e ", moon.position[i]);
    }
    printf("\n");
    printf("Final velocity of moon:\n");
    for (int i = 0; i < 3; i++) {
        printf("%.3e ", moon.velocity[i]);
    }
    printf("\n");

    return 0;
}