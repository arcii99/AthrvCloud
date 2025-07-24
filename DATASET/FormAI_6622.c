//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define G 6.6743e-11       // gravitational constant
#define MASS_SUN 1.989e30   // mass of sun in kg
#define RADIUS_SUN 6.95e8   // radius of sun in m
#define AU 1.496e11        // astronomical unit in m
#define YEAR 31536000      // year in seconds

int main() {
    // Initialize seed for random number generator
    srand(time(NULL));

    // Define variables
    double xpos, ypos, zpos, xvel, yvel, zvel, mass, radius;
    double position[10][3] = {0};   // position of each planet
    double velocity[10][3] = {0};   // velocity of each planet
    double force[10][3] = {0};      // force acting on each planet
    double acceleration[10][3] = {0}; // acceleration of each planet
    double distance, magnitude, timestep;
    int i, j, k;

    // Initialize sun
    xpos = 0;
    ypos = 0;
    zpos = 0;
    xvel = 0;
    yvel = 0;
    zvel = 0;
    mass = MASS_SUN;
    radius = RADIUS_SUN;

    // Define planets
    double data[9][6] = {
        // xpos, ypos, zpos, xvel, yvel, zvel, mass, radius
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.011},    // Mercury
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.012},    // Venus
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.013},    // Earth
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.007},    // Mars
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.951},    // Jupiter
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.801},    // Saturn
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.377},    // Uranus
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.389},    // Neptune
        {0, 0, 0, 0, 0, 0, 0, RADIUS_SUN*0.080}     // Pluto
    };

    // Assign initial random positions and velocities
    for (i = 0; i < 9; i++) {
        position[i][0] = (rand()/(double)RAND_MAX - 0.5) * AU;
        position[i][1] = (rand()/(double)RAND_MAX - 0.5) * AU;
        position[i][2] = (rand()/(double)RAND_MAX - 0.5) * AU;
        velocity[i][0] = (rand()/(double)RAND_MAX - 0.5) * 10000;
        velocity[i][1] = (rand()/(double)RAND_MAX - 0.5) * 10000;
        velocity[i][2] = (rand()/(double)RAND_MAX - 0.5) * 10000;
        data[i][0] = position[i][0];
        data[i][1] = position[i][1];
        data[i][2] = position[i][2];
        data[i][3] = velocity[i][0];
        data[i][4] = velocity[i][1];
        data[i][5] = velocity[i][2];
    }

    timestep = 86400;   // timestep in seconds

    // Run simulation
    for (k = 0; k < 365*10; k++) {   // 10 years
        // Reset forces and accelerations
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 3; j++) {
                force[i][j] = 0;
                acceleration[i][j] = 0;
            }
        }

        // Calculate forces
        for (i = 0; i < 9; i++) {
            for (j = i+1; j < 10; j++) {
                distance = sqrt(pow((position[i][0] - position[j][0]), 2) + pow((position[i][1] - position[j][1]), 2) + pow((position[i][2] - position[j][2]), 2));
                magnitude = (G * data[i][6] * data[j][6]) / pow(distance, 2);
                force[i][0] += magnitude * (position[j][0] - position[i][0]) / distance;
                force[i][1] += magnitude * (position[j][1] - position[i][1]) / distance;
                force[i][2] += magnitude * (position[j][2] - position[i][2]) / distance;
                force[j][0] -= magnitude * (position[j][0] - position[i][0]) / distance;
                force[j][1] -= magnitude * (position[j][1] - position[i][1]) / distance;
                force[j][2] -= magnitude * (position[j][2] - position[i][2]) / distance;
            }
        }

        // Calculate accelerations
        for (i = 0; i < 9; i++) {
            acceleration[i][0] = force[i][0] / data[i][6];
            acceleration[i][1] = force[i][1] / data[i][6];
            acceleration[i][2] = force[i][2] / data[i][6];
        }

        // Calculate new positions and velocities
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 3; j++) {
                position[i][j] += velocity[i][j] * timestep + 0.5 * acceleration[i][j] * pow(timestep, 2);
                velocity[i][j] += acceleration[i][j] * timestep;
                data[i][j] = position[i][j];
                data[i][j+3] = velocity[i][j];
            }
        }

        // Print data for each year
        if (k % 365 == 0) {
            printf("Year %d:\n", k/365);
            for (i = 0; i < 10; i++) {
                printf("Planet %d:\n", i+1);
                printf("\tPosition: (%.2f, %.2f, %.2f) AU\n", data[i][0]/AU, data[i][1]/AU, data[i][2]/AU);
                printf("\tVelocity: (%.2f, %.2f, %.2f) km/s\n", data[i][3]/1000, data[i][4]/1000, data[i][5]/1000);
            }
        }
    }

    return 0;
}