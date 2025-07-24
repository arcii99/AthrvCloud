//FormAI DATASET v1.0 Category: Physics simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Happy Physics Simulation Program!\n");

    float mass, velocity, height, kineticEnergy, potentialEnergy;

    printf("Please enter the mass of the object (in kg): ");
    scanf("%f", &mass);

    printf("Please enter the initial velocity of the object (in m/s): ");
    scanf("%f", &velocity);

    printf("Please enter the height from which the object is dropped (in m): ");
    scanf("%f", &height);

    float time = sqrt(2 * height / 9.8);
    float distance = velocity * time;
    float acceleration = velocity / time;

    kineticEnergy = 0.5 * mass * pow(velocity, 2);
    potentialEnergy = mass * 9.8 * height;

    printf("\nThe object will hit the ground in %.2f seconds.\n", time);
    printf("The object will travel %.2f meters before hitting the ground.\n", distance);
    printf("The acceleration of the object is %.2f m/s^2.\n", acceleration);
    printf("The kinetic energy of the object at impact is %.2f joules.\n", kineticEnergy);
    printf("The potential energy of the object at the height is %.2f joules.\n", potentialEnergy);

    printf("\nThank you for using the Happy Physics Simulation Program!\n");

    return 0;
}