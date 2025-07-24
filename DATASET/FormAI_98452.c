//FormAI DATASET v1.0 Category: Physics simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the maximum height
float getMaxHeight(float v, float angle)
{
    float h = (v * v * sin(angle) * sin(angle)) / (2 * 9.81);
    return h;
}

// Function to calculate the range of projectile
float getRange(float v, float angle)
{
    float r = (v * v * sin(2 * angle)) / 9.81;
    return r;
}

int main()
{
    float velocity, angle;
    float maxHeight, range;

    printf("Enter initial velocity (in m/s): ");
    scanf("%f", &velocity);

    printf("Enter angle of projection (in degrees): ");
    scanf("%f", &angle);

    // Convert angle from degrees to radians
    angle = angle * M_PI / 180;

    maxHeight = getMaxHeight(velocity, angle);
    range = getRange(velocity, angle);

    printf("Maximum height reached is %.2f meters\n", maxHeight);
    printf("Range of the projectile is %.2f meters\n", range);

    return 0;
}