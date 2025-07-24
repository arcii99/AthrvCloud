//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program calculates the volume of a sphere using input from the user

int main()
{
    double radius, volume;

    // Get radius from user
    printf("Enter the radius of the sphere: ");
    scanf("%lf", &radius);

    // Calculate volume using the formula V = 4/3 * pi * r^3
    volume = (4.0/3.0) * M_PI * pow(radius, 3);

    // Display volume to user
    printf("The volume of the sphere with radius %f is %f\n", radius, volume);

    return 0;
}