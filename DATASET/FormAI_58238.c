//FormAI DATASET v1.0 Category: Physics simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // seed the random number generator

    // Set up simulation variables
    double mass = 10.0, velocity = 0.0, acceleration = 0.0;
    const double force = 20.0, friction_coefficient = 0.5;
    const double time_step = 0.1;
    double distance_traveled = 0.0;
    int seconds_elapsed = 0;

    printf("Welcome to the wacky physics simulation!\n");
    printf("Our brave little mass will be traveling on a friction-y surface.\n");
    
    // Run simulation for 60 seconds
    for(int i = 0; i < 60; i++) {
        // Calculate force and acceleration
        double friction_force = friction_coefficient * mass * 9.81;
        double net_force = force - friction_force;
        acceleration = net_force / mass;
        printf("Acceleration at time %d: %f\n", seconds_elapsed, acceleration);

        // Calculate velocity and distance traveled
        velocity += acceleration * time_step;
        distance_traveled += velocity * time_step;

        // Display info to user
        printf("Seconds elapsed: %d | Distance traveled: %f meters | Velocity: %f m/s\n", seconds_elapsed, distance_traveled, velocity);

        // Increase seconds_elapsed and wait a second
        seconds_elapsed++;
        printf("Tick, tock, tick, tock...\n");
        sleep(1);
    }

    printf("Simulation complete! Our mass traveled a distance of %f meters in 60 seconds.\n", distance_traveled);

    return 0;
}