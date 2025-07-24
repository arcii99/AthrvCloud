//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>

int main() {
    float speed, acceleration, time, initial_velocity, final_velocity, displacement;

    printf("Enter initial velocity: ");
    scanf("%f", &initial_velocity);

    printf("Enter acceleration: ");
    scanf("%f", &acceleration);

    printf("Enter time: ");
    scanf("%f", &time);

    final_velocity = initial_velocity + acceleration * time;
    displacement = (initial_velocity + final_velocity) / 2.0 * time;
    speed = displacement / time;

    printf("\nFinal velocity = %f", final_velocity);
    printf("\nDisplacement = %f", displacement);
    printf("\nSpeed = %f\n", speed);

    return 0;
}