//FormAI DATASET v1.0 Category: Physics simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int time = 0;
    double gravity = 9.8;
    double angle = 0;
    double velocity = 0;
    double x = 0;
    double y = 0;

    printf("Welcome to the Physics Simulator!\n");
    printf("In this simulation, a cow will be launched into the air with a catapult.\n");
    printf("Enter the angle (in degrees) at which the cow will be launched: ");
    scanf("%lf", &angle);
    printf("Enter the velocity at which the cow will be launched (in meters per second): ");
    scanf("%lf", &velocity);

    printf("\nHere we go!\n");

    while(y >= 0)
    {
        time++;
        x = velocity * cos(angle) * time;
        y = velocity * sin(angle) * time - 0.5 * gravity * pow(time, 2);
        printf("Time: %d seconds, Distance: %.2f meters\n", time, x);
    }

    printf("\nThe cow hit the ground after %d seconds.\n", time);
    printf("Luckily, it bounced right back up!\n");

    y = 0;

    while(y >= 0)
    {
        time++;
        x = velocity * cos(angle) * time;
        y = velocity * sin(angle) * time - 0.5 * gravity * pow(time, 2);
        printf("Time: %d seconds, Distance: %.2f meters, Height: %.2f meters\n", time, x, y);
    }

    printf("\nThe cow hit the ground again after %d seconds.\n", time);
    printf("It looks like the cow is okay, but we may need to get a new catapult.\n");

    return 0;
}