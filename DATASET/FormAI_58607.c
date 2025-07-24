//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define dt 0.1 // time step size
#define t_end 1000 // end time of simulation

#define num_planets 3 // number of planets in the simulation

struct planet {
    char name[20];
    double mass;
    double pos[3];
    double vel[3];
};

int main() {
    srand(time(NULL)); // seed for random numbers
    struct planet planets[num_planets];

    // generate random planets
    for (int i = 0; i < num_planets; i++) {
        sprintf(planets[i].name, "Planet %d", i+1); // use sprintf to format planet name
        planets[i].mass = rand() % (1000 - 100 + 1) + 100; // random mass between 100 and 1000 kg
        for (int j = 0; j < 3; j++) {
            planets[i].pos[j] = rand() % (1000 - (-1000) + 1) - 1000; // random position between -1000 and 1000 meters
            planets[i].vel[j] = rand() % (10 - (-10) + 1) - 10; // random velocity between -10 and 10 m/s
        }
    }

    // simulate gravity
    double t = 0; // current time
    while (t <= t_end) { // loop until end time
        // calculate net force on each planet
        for (int i = 0; i < num_planets; i++) {
            double f_total[3] = {0, 0, 0}; // initialize total force to zero
            for (int j = 0; j < num_planets; j++) {
                if (i == j) { // do not calculate force on itself
                    continue;
                }
                double r = 0; // distance between planets
                for (int k = 0; k < 3; k++) {
                    r += pow(planets[i].pos[k] - planets[j].pos[k], 2);
                }
                r = sqrt(r);
                double f = G * planets[i].mass * planets[j].mass / pow(r, 2); // gravitational force
                for (int k = 0; k < 3; k++) {
                    f_total[k] += f * (planets[j].pos[k] - planets[i].pos[k]) / r; // calculate force vector component
                }
            }
            // update planet velocity and position
            for (int j = 0; j < 3; j++) {
                planets[i].vel[j] += f_total[j] / planets[i].mass * dt;
                planets[i].pos[j] += planets[i].vel[j] * dt;
            }
        }
        t += dt; // advance time step
    }

    // print final positions and velocities of planets
    for (int i = 0; i < num_planets; i++) {
        printf("%s final position: (%.2f, %.2f, %.2f) m\n", planets[i].name, planets[i].pos[0], planets[i].pos[1], planets[i].pos[2]);
        printf("%s final velocity: (%.2f, %.2f, %.2f) m/s\n", planets[i].name, planets[i].vel[0], planets[i].vel[1], planets[i].vel[2]);
    }

    return 0;
}