//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G_CONST 6.67408E-11    // gravitational constant
#define NUM_BODIES 9           // number of bodies in our solar system
#define NUM_STEPS 60*60*24*365 // total number of simulation steps

// body structure to hold information for each celestial body
typedef struct body {
    char name[30];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
    double acceleration[3];
} Body;

int main() {
    Body bodies[NUM_BODIES];

    // set up each body with its initial conditions
    sprintf(bodies[0].name, "Sun");
    bodies[0].mass = 1.9885E30;
    bodies[0].radius = 696340000;
    bodies[0].position[0] = bodies[0].velocity[0] = bodies[0].acceleration[0] = 0.0;
    bodies[0].position[1] = bodies[0].velocity[1] = bodies[0].acceleration[1] = 0.0;
    bodies[0].position[2] = bodies[0].velocity[2] = bodies[0].acceleration[2] = 0.0;

    sprintf(bodies[1].name, "Mercury");
    bodies[1].mass = 3.285E23;
    bodies[1].radius = 2439700;
    bodies[1].position[0] = -6.98169E10;
    bodies[1].position[1] = 4.22330E10;
    bodies[1].position[2] = 1.18059E10;
    bodies[1].velocity[0] = -29599.8;
    bodies[1].velocity[1] = -47401.9;
    bodies[1].velocity[2] = -5926.28;

    sprintf(bodies[2].name, "Venus");
    bodies[2].mass = 4.867E24;
    bodies[2].radius = 6051800;
    bodies[2].position[0] = -9.82428E10;
    bodies[2].position[1] = -5.29333E10;
    bodies[2].position[2] = 7.28331E9;
    bodies[2].velocity[0] = 23267.6;
    bodies[2].velocity[1] = -39822.1;
    bodies[2].velocity[2] = -4166.3;

    sprintf(bodies[3].name, "Earth");
    bodies[3].mass = 5.972E24;
    bodies[3].radius = 6378140;
    bodies[3].position[0] = -9.83772E10;
    bodies[3].position[1] = -2.01368E11;
    bodies[3].position[2] = -1.50981E7;
    bodies[3].velocity[0] = 28826.8;
    bodies[3].velocity[1] = -11180.2;
    bodies[3].velocity[2] = -1.02848;

    sprintf(bodies[4].name, "Mars");
    bodies[4].mass = 6.39E23;
    bodies[4].radius = 3396200;
    bodies[4].position[0] = 2.40189E11;
    bodies[4].position[1] = 7.26158E10;
    bodies[4].position[2] = -2.61451E9;
    bodies[4].velocity[0] = -9777.86;
    bodies[4].velocity[1] = 24193.9;
    bodies[4].velocity[2] = 717.266;

    sprintf(bodies[5].name, "Jupiter");
    bodies[5].mass = 1.898E27;
    bodies[5].radius = 71492000;
    bodies[5].position[0] = 7.41710E11;
    bodies[5].position[1] = -7.59425E11;
    bodies[5].position[2] = -1.66603E10;
    bodies[5].velocity[0] = 9887.88;
    bodies[5].velocity[1] = 9565.03;
    bodies[5].velocity[2] = -140.081;

    sprintf(bodies[6].name, "Saturn");
    bodies[6].mass = 5.683E26;
    bodies[6].radius = 60268000;
    bodies[6].position[0] = 1.31322E12;
    bodies[6].position[1] = -7.20881E11;
    bodies[6].position[2] = -3.48863E10;
    bodies[6].velocity[0] = 6272.39;
    bodies[6].velocity[1] = 10809.0;
    bodies[6].velocity[2] = -206.962;

    sprintf(bodies[7].name, "Uranus");
    bodies[7].mass = 8.681E25;
    bodies[7].radius = 25559000;
    bodies[7].position[0] = 2.56690E12;
    bodies[7].position[1] = 1.43717E12;
    bodies[7].position[2] = -2.77605E10;
    bodies[7].velocity[0] = -3934.16;
    bodies[7].velocity[1] = 6847.97;
    bodies[7].velocity[2] = 32.4609;

    sprintf(bodies[8].name, "Neptune");
    bodies[8].mass = 1.024E26;
    bodies[8].radius = 24764000;
    bodies[8].position[0] = 4.32413E12;
    bodies[8].position[1] = -1.00768E12;
    bodies[8].position[2] = -7.86032E10;
    bodies[8].velocity[0] = 1378.69;
    bodies[8].velocity[1] = 5255.55;
    bodies[8].velocity[2] = -158.617;

    // initialize time variables
    double time_step = 60 * 60 * 24; // 1 day
    double current_time = 0.0;

    // print initial conditions before simulation
    printf("Initial Conditions\n");
    for (int i = 0; i < NUM_BODIES; i++) {
        printf("%-10s: (%.3e, %.3e, %.3e) (%.3e, %.3e, %.3e)\n",
            bodies[i].name,
            bodies[i].position[0], bodies[i].position[1], bodies[i].position[2],
            bodies[i].velocity[0], bodies[i].velocity[1], bodies[i].velocity[2]);
    }

    // perform simulation
    for (int t = 0; t < NUM_STEPS; t++) {
        // calculate acceleration on each body
        for (int i = 0; i < NUM_BODIES; i++) {
            for (int j = 0; j < NUM_BODIES; j++) {
                if (i == j) continue;

                double distance = sqrt(pow(bodies[j].position[0] - bodies[i].position[0], 2)
                                    + pow(bodies[j].position[1] - bodies[i].position[1], 2)
                                    + pow(bodies[j].position[2] - bodies[i].position[2], 2));

                double acceleration = G_CONST * bodies[j].mass / pow(distance, 2);

                bodies[i].acceleration[0] += acceleration * (bodies[j].position[0] - bodies[i].position[0]) / distance;
                bodies[i].acceleration[1] += acceleration * (bodies[j].position[1] - bodies[i].position[1]) / distance;
                bodies[i].acceleration[2] += acceleration * (bodies[j].position[2] - bodies[i].position[2]) / distance;
            }
        }

        // update position and velocity of each body
        for (int i = 0; i < NUM_BODIES; i++) {
            for (int j = 0; j < 3; j++) {
                bodies[i].position[j] += bodies[i].velocity[j] * time_step
                                       + 0.5 * bodies[i].acceleration[j] * pow(time_step, 2);
                bodies[i].velocity[j] += bodies[i].acceleration[j] * time_step;
                bodies[i].acceleration[j] = 0.0;
            }
        }

        // update current time
        current_time += time_step;

        // print simulation results every 10 years
        if (fmod(current_time, 60 * 60 * 24 * 3650) == 0) {
            printf("\nTime: %d years\n", (int) (current_time / (60 * 60 * 24 * 365)));
            for (int i = 0; i < NUM_BODIES; i++) {
                printf("%-10s: (%.3e, %.3e, %.3e) (%.3e, %.3e, %.3e)\n",
                    bodies[i].name,
                    bodies[i].position[0], bodies[i].position[1], bodies[i].position[2],
                    bodies[i].velocity[0], bodies[i].velocity[1], bodies[i].velocity[2]);
            }
        }
    }

    return 0;
}