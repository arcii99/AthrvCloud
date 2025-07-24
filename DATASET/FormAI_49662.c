//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11 // gravitational constant
#define RADIUS 6371000 // radius of Earth in meters
#define TIMESTEP 1 // timestep in seconds
#define DURATION 86400 // duration in seconds (1 day)

// function to calculate the gravitational force between two objects
double gravitationalForce(double mass1, double mass2, double distance) {
    return (G * mass1 * mass2) / (distance * distance);
}

int main() {
    double earthMass = 5.972e24; // mass of Earth in kg
    double spaceshipMass = 1000; // mass of spaceship in kg
    double spaceshipVelocity = 0; // initial velocity of spaceship in m/s
    double spaceshipPosition = RADIUS + 500000; // initial position of spaceship in meters
    double time = 0; // initial time in seconds

    while (time <= DURATION) {
        double force = gravitationalForce(earthMass, spaceshipMass, spaceshipPosition * spaceshipPosition);
        double acceleration = force / spaceshipMass;
        double deltaVelocity = acceleration * TIMESTEP;
        spaceshipVelocity += deltaVelocity;
        double deltaPosition = spaceshipVelocity * TIMESTEP;
        spaceshipPosition += deltaPosition;
        time += TIMESTEP;

        // check if spaceship crashes into Earth
        if (spaceshipPosition <= RADIUS) {
            printf("Spaceship crashed into Earth at time %lf seconds.\n", time);
            break;
        }

        printf("Time: %lf seconds, Position: %lf meters, Velocity: %lf m/s\n", time, spaceshipPosition, spaceshipVelocity);
    }

    return 0;
}