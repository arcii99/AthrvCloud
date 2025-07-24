//FormAI DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    float initialVelocity, angle, time, distance;

    printf("Enter the initial velocity (m/s): ");
    scanf("%f", &initialVelocity);

    printf("Enter the angle (degrees): ");
    scanf("%f", &angle);

    printf("Enter the time (s): ");
    scanf("%f", &time);

    // Convert angle from degrees to radians
    angle = angle * PI / 180;

    // Calculate distance
    distance = initialVelocity * cos(angle) * time;

    printf("\nDistance traveled: %.2f meters\n", distance);

    return 0;
}