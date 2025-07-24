//FormAI DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Grateful style physics simulation example program

int main()
{
    printf("Welcome to the Grateful Physics Simulation! \n");

    // Declare variables
    double mass = 4.0; // Mass of object in kg
    double velocity = 10.0; // Velocity of object in m/s
    double time = 0.0; // Starting time in seconds
    double acceleration; // Acceleration of object
    double distance = 0.0; // Distance traveled by object

    // Print starting values
    printf("Starting values: \n");
    printf("Mass: %.2f kg \n", mass);
    printf("Velocity: %.2f m/s \n", velocity);
    printf("Time: %.2f s \n", time);

    // Calculate and print acceleration
    acceleration = (-9.81); // Acceleration due to gravity in m/s^2
    printf("Calculated acceleration: %.2f m/s^2 \n", acceleration);

    // Simulate the motion of object over 10 seconds
    while (time <= 10.0)
    {
        distance = distance + (velocity * (time + 0.1) - 0.5 * acceleration * pow((time + 0.1), 2)) - (velocity * time - 0.5 * acceleration * pow(time, 2));
        time = time + 0.1;
    }

    // Print final position of object
    printf("Final position of object after 10 seconds: %.2f m \n", distance);

    return 0;
}