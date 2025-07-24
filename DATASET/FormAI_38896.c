//FormAI DATASET v1.0 Category: Physics simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float mass, initial_velocity, angle;
    float acceleration, time, range;

    printf("Enter the mass of the object (in kg): ");
    scanf("%f", &mass);

    printf("Enter the initial velocity of the object (in m/s): ");
    scanf("%f", &initial_velocity);

    printf("Enter the angle of launch (in degrees): ");
    scanf("%f", &angle);
    angle = angle * PI / 180;

    acceleration = -9.8; // acceleration due to gravity
    time = (2 * initial_velocity * sin(angle)) / (-1 * acceleration);
    range = pow(initial_velocity, 2) * sin(2 * angle) / (-1 * acceleration);

    printf("The object will reach the maximum height after %.2f seconds\n", time/2);
    printf("The object will land after %.2f seconds\n", time);
    printf("The object will land %.2f meters away\n", range);

    return 0;
}