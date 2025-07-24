//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: curious
#include <stdio.h>
#include <math.h>

#define G 6.673e-11      // gravitational constant
#define SUN_MASS 1.989e30 // mass of the Sun

#define N 8 // number of bodies in the simulation

struct body {
    char name[10];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
};

int main() {
    // initialize the bodies in the solar system
    struct body sun = {"Sun", SUN_MASS, 695700000, {0,0,0}, {0,0,0}};
    struct body mercury = {"Mercury", 3.285e23, 2440000, {57909000000,0,0}, {0,47360,0}};
    struct body venus = {"Venus", 4.867e24, 6052000, {108208930000,0,0}, {0,35020,0}};
    struct body earth = {"Earth", 5.972e24, 6371000, {149597870700,0,0}, {0,29783,0}};
    struct body mars = {"Mars", 6.39e23, 3390000, {227943820000,0,0}, {0,24077,0}};
    struct body jupiter = {"Jupiter", 1.898e27, 69911000, {778340821000,0,0}, {0,13070,0}};
    struct body saturn = {"Saturn", 5.683e26, 58232000, {1426666422000,0,0}, {0,9690,0}};
    struct body uranus = {"Uranus", 8.681e25, 25362000, {2870658186000,0,0}, {0,6810,0}};
    struct body neptune = {"Neptune", 1.024e26, 24622000, {4503443661000,0,0}, {0,5430,0}};

    // put the bodies in an array
    struct body bodies[N] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    // simulate the solar system for 100 years
    double dt = 86400; // one day
    int years = 100;
    int steps_per_day = 1000;
    int total_steps = years * 365 * steps_per_day;
    for (int step = 1; step <= total_steps; step++) {
        // update the positions and velocities of the bodies
        for (int i = 0; i < N; i++) {
            double acceleration[3] = {0,0,0};
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double r_ij[3];
                    for (int k = 0; k < 3; k++) {
                        r_ij[k] = bodies[j].position[k] - bodies[i].position[k];
                    }
                    double r = sqrt(r_ij[0]*r_ij[0] + r_ij[1]*r_ij[1] + r_ij[2]*r_ij[2]);
                    double magnitude = G * bodies[j].mass / r / r;
                    for (int k = 0; k < 3; k++) {
                        acceleration[k] += magnitude * r_ij[k] / r;
                    }
                }
            }
            for (int k = 0; k < 3; k++) {
                bodies[i].velocity[k] += acceleration[k] * dt / 2;
                bodies[i].position[k] += bodies[i].velocity[k] * dt;
            }
        }
        // update the velocities again
        for (int i = 0; i < N; i++) {
            double acceleration[3] = {0,0,0};
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double r_ij[3];
                    for (int k = 0; k < 3; k++) {
                        r_ij[k] = bodies[j].position[k] - bodies[i].position[k];
                    }
                    double r = sqrt(r_ij[0]*r_ij[0] + r_ij[1]*r_ij[1] + r_ij[2]*r_ij[2]);
                    double magnitude = G * bodies[j].mass / r / r;
                    for (int k = 0; k < 3; k++) {
                        acceleration[k] += magnitude * r_ij[k] / r;
                    }
                }
            }
            for (int k = 0; k < 3; k++) {
                bodies[i].velocity[k] += acceleration[k] * dt / 2;
            }
        }
        // print the positions of the bodies every year
        if (step % (365*steps_per_day) == 0) {
            printf("Year %d:\n", step / (365*steps_per_day));
            for (int i = 0; i < N; i++) {
                printf("%s: (%.2f, %.2f, %.2f) meters\n", bodies[i].name, bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
            }
            printf("\n");
        }
    }

    return 0;
}