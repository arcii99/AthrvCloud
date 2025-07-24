//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main()
{
    float length, velocity, acceleration, time;
    printf("Enter the length of a track in meters: ");
    scanf("%f", &length);
    printf("Enter the initial velocity of a car in m/s: ");
    scanf("%f", &velocity);
    printf("Enter the acceleration of the car in m/s^2: ");
    scanf("%f", &acceleration);
    printf("Enter the time for the car to travel the length of the track in seconds: ");
    scanf("%f", &time);

    float distance = (velocity*time) + (0.5*acceleration*pow(time, 2));
    float finalVelocity = velocity + (acceleration*time);

    printf("\nThe distance traveled by the car is %.2f meters.", distance);
    printf("\nThe final velocity of the car is %.2f m/s.", finalVelocity);

    return 0;
}