//FormAI DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    float initial_velocity, final_velocity, acceleration, time;
    
    printf("Enter the initial velocity: ");
    scanf("%f", &initial_velocity);

    printf("Enter the final velocity: ");
    scanf("%f", &final_velocity);

    printf("Enter the acceleration: ");
    scanf("%f", &acceleration);

    printf("Enter the time: ");
    scanf("%f", &time);

    float distance = ((initial_velocity + final_velocity) / 2) * time;
    float velocity_change = acceleration * time;
    
    printf("\nThe distance traveled is: %.2f meters.", distance);
    printf("\nThe change in velocity is: %.2f m/s.", velocity_change);

    return 0;
}