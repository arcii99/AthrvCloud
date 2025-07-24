//FormAI DATASET v1.0 Category: Physics simulation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
    // Welcome message
    printf("Welcome to the physics simulation program!\n");

    // Initialization
    double force, mass, acceleration, velocity, displacement, time;
    printf("Enter the mass in kg: ");
    scanf("%lf", &mass);
    printf("Enter the force in N: ");
    scanf("%lf", &force);
    printf("Enter the time in s: ");
    scanf("%lf", &time);

    // Calculation of acceleration
    acceleration = force / mass;
    printf("The acceleration is %.2lf m/s^2\n", acceleration);

    // Calculation of velocity
    velocity = acceleration * time;
    printf("The velocity is %.2lf m/s\n", velocity);

    // Calculation of displacement
    displacement = (force * pow(time, 2)) / (2 * mass);
    printf("The displacement is %.2lf m\n", displacement);

    // Goodbye message
    printf("Simulation complete! Thank you for using this program.\n");

    // End program
    return 0;
}