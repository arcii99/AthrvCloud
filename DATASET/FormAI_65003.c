//FormAI DATASET v1.0 Category: Physics simulation ; Style: protected
#include<stdio.h>

int main(void) {
    float mass, velocity, time, acceleration, distance, force;

    printf("Enter the values of mass and velocity: \n");
    scanf("%f %f", &mass, &velocity);

    force = mass * acceleration;
    printf("Force exerted by the object: %.2f N\n", force);

    printf("Enter the values of time and acceleration: \n");
    scanf("%f %f", &time, &acceleration);

    distance = velocity * time + (0.5) * acceleration * time * time;
    printf("Distance traveled by the object: %.2f m\n", distance);

    return 0;
}