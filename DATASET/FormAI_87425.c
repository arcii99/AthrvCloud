//FormAI DATASET v1.0 Category: Physics simulation ; Style: romantic
#include <stdio.h>

int main() {
    float time, initialVelocity, acceleration, height;
    float finalVelocity, displacement;

    // take input from user
    printf("Enter the initial velocity (in m/s): ");
    scanf("%f", &initialVelocity);

    printf("Enter the height (in meters): ");
    scanf("%f", &height);

    printf("Enter the acceleration due to gravity (in m/s^2): ");
    scanf("%f", &acceleration);

    // calculate time of flight
    time = sqrt((2 * height) / acceleration);

    // calculate final velocity
    finalVelocity = initialVelocity + (acceleration * time);

    // calculate displacement
    displacement = initialVelocity * time + (0.5 * acceleration * time * time);

    // print results
    printf("The time of flight is: %.2f seconds\n", time);
    printf("The final velocity is: %.2f m/s\n", finalVelocity);
    printf("The displacement is: %.2f meters\n", displacement);

    return 0;
}