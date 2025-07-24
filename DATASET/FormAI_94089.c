//FormAI DATASET v1.0 Category: Physics simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.674 * pow(10, -11) // gravitational constant
#define MASS 5.972 * pow(10, 24) // mass of the Earth
#define RADIUS 6.371 * pow(10, 6) // radius of the Earth

/*
 * Function to calculate the force between two particles
 */
double calc_force(double mass1, double mass2, double distance) {
    return G * mass1 * mass2 / pow(distance, 2);
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // create variables for two particles
    double mass1 = 1000;
    double mass2 = 1000;
    double position1 = 0;
    double position2 = 1000000;
    double velocity1 = 0;
    double velocity2 = 0;

    // create variables for simulation parameters
    double time_step = 1;
    double simulation_time = 1000;
    double distance = fabs(position2 - position1);

    // start simulation loop
    for (double t = 0; t <= simulation_time; t += time_step) {
        // calculate force between the particles
        double force = calc_force(mass1, mass2, distance);

        // calculate acceleration of each particle
        double acceleration1 = force / mass1;
        double acceleration2 = force / mass2;

        // calculate velocity of each particle
        velocity1 += acceleration1 * time_step;
        velocity2 += acceleration2 * time_step;

        // calculate position of each particle
        position1 += velocity1 * time_step;
        position2 += velocity2 * time_step;

        // update distance between particles
        distance = fabs(position2 - position1);

        // check if particles collide
        if (distance <= 0) {
            printf("Collision occurred at time %.2f seconds\n", t);
            break;
        }
        // check if particles collide with Earth
        else if (position1 <= RADIUS || position2 <= RADIUS) {
            printf("Particle collided with Earth at time %.2f seconds\n", t);
            break;
        }
        // print positions of particles every 10 seconds
        else if ((int) t % 10 == 0) {
            printf("Position of particle 1: %.2f meters\n", position1);
            printf("Position of particle 2: %.2f meters\n", position2);
        }
    }

    return 0;
}