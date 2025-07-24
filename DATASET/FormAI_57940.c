//FormAI DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float mass, velocity, distance, time, force, acceleration, energy;
    const float g = 9.81; // Earth's gravitational constant

    printf("Enter the mass of the object in kilograms: ");
    scanf("%f", &mass);

    printf("Enter the velocity of the object in meters per second: ");
    scanf("%f", &velocity);

    printf("Enter the distance covered by the object in meters: ");
    scanf("%f", &distance);

    time = distance / velocity;
    force = mass * g;
    acceleration = force / mass;
    energy = (0.5 * mass * pow(velocity, 2)) + (mass * g * distance);

    printf("\nTime taken by the object = %f seconds\n", time);
    printf("Force applied on the object due to gravity = %f newtons\n", force);
    printf("Acceleration of the object due to gravity = %f meters per second squared\n", acceleration);
    printf("Total energy of the object = %f joules\n", energy);

    return 0;
}