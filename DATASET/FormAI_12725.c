//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11    // gravitational constant

struct body {
    double mass;
    double pos[3];
    double vel[3];
    double force[3];
};

const double sim_time = 31557600.0; // one year in seconds

// function to calculate distance between two bodies
double distance(double pos1[3], double pos2[3]) {
    double dx = pos2[0] - pos1[0];
    double dy = pos2[1] - pos1[1];
    double dz = pos2[2] - pos1[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    struct body sun = {1.989e30, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};   // the sun
    struct body earth = {5.972e24, {147e9, 0.0, 0.0}, {0.0, 30330.0, 0.0}, {0.0, 0.0, 0.0}}; // the earth
    struct body jupiter = {1.898e27, {778e9, 0.0, 0.0}, {0.0, 13150.0, 0.0}, {0.0, 0.0, 0.0}}; // jupiter

    double dt = 86400.0;    // one day in seconds
    double t = 0.0;

    while (t < sim_time) {
        // calculate forces on each body
        double dist_sun_earth = distance(sun.pos, earth.pos);
        double force_sun_earth = G * sun.mass * earth.mass / (dist_sun_earth * dist_sun_earth);
        for (int i = 0; i < 3; i++) {
            earth.force[i] += force_sun_earth * (sun.pos[i] - earth.pos[i]) / dist_sun_earth;
        }

        double dist_sun_jupiter = distance(sun.pos, jupiter.pos);
        double force_sun_jupiter = G * sun.mass * jupiter.mass / (dist_sun_jupiter * dist_sun_jupiter);
        for (int i = 0; i < 3; i++) {
            jupiter.force[i] += force_sun_jupiter * (sun.pos[i] - jupiter.pos[i]) / dist_sun_jupiter;
        }

        double dist_earth_jupiter = distance(earth.pos, jupiter.pos);
        double force_earth_jupiter = G * earth.mass * jupiter.mass / (dist_earth_jupiter * dist_earth_jupiter);
        for (int i = 0; i < 3; i++) {
            earth.force[i] += force_earth_jupiter * (jupiter.pos[i] - earth.pos[i]) / dist_earth_jupiter;
            jupiter.force[i] -= force_earth_jupiter * (jupiter.pos[i] - earth.pos[i]) / dist_earth_jupiter;
        }

        // update positions and velocities of each body
        for (int i = 0; i < 3; i++) {
            earth.vel[i] += earth.force[i] / earth.mass * dt;
            earth.pos[i] += earth.vel[i] * dt;
            earth.force[i] = 0.0;

            jupiter.vel[i] += jupiter.force[i] / jupiter.mass * dt;
            jupiter.pos[i] += jupiter.vel[i] * dt;
            jupiter.force[i] = 0.0;
        }

        // print current positions of earth and jupiter
        printf("t = %f, earth pos = (%e, %e, %e), jupiter pos = (%e, %e, %e)\n",
            t, earth.pos[0], earth.pos[1], earth.pos[2], jupiter.pos[0], jupiter.pos[1], jupiter.pos[2]);

        t += dt;
    }

    return 0;
}