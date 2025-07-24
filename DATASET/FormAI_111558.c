//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main()
{
    //Declaring variables
    double velocity, angle, height, time, x, y, range;

    //Taking user input
    printf("Enter the initial velocity: ");
    scanf("%lf", &velocity);
    printf("Enter the angle of projection: ");
    scanf("%lf", &angle);
    printf("Enter the initial height: ");
    scanf("%lf", &height);

    //Converting angle from degree to radian
    angle = angle * M_PI / 180.0;

    //Calculating time of flight
    time = (2 * velocity * sin(angle)) / 9.81;

    //Calculating range
    range = (velocity * cos(angle)) * time;

    //Printing the result
    printf("Time of flight: %.2lf seconds\n", time);
    printf("Range: %.2lf meters\n", range);

    //Calculating the trajectory and printing it
    printf("Trajectory:\n");
    printf("x\t\t y\n");
    for(x = 0; x <= range; x+=1)
    {
        y = height + (x * tan(angle)) - ((9.81 * x * x) / (2 * velocity * velocity * cos(angle) * cos(angle)));
        printf("%.2lf\t\t %.2lf\n", x, y);
    }

    return 0;
}