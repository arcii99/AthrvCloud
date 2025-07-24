//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    float velocity = 0, acceleration = 0, distance = 0, time = 0;
    printf("Enter initial velocity (m/s): ");
    scanf("%f", &velocity);
    printf("Enter acceleration (m/s^2): ");
    scanf("%f", &acceleration);
    printf("Enter distance (m): ");
    scanf("%f", &distance);
    printf("\n");

    time = (-velocity + sqrtf((velocity * velocity) - (2 * acceleration * -distance))) / acceleration;
    // Calculation using quadratic formula

    printf("The object will hit the ground after %.2f seconds.\n", time);
    printf("At that time, it will be traveling at a speed of %.2f m/s.", velocity + (acceleration * time));

    return 0;
}