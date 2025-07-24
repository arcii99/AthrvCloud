//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main() {

    //variables
    double initialVelocity, angle, distance, time, maxHeight, range;

    //read input values
    printf("Enter the initial velocity(m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter the angle(in degrees): ");
    scanf("%lf", &angle);

    //convert angle to radians
    angle = angle * M_PI / 180.0;

    //calculate distance and time
    distance = (initialVelocity * initialVelocity * sin(2 * angle)) / 9.81;
    time = (2 * initialVelocity * sin(angle)) / 9.81;

    //calculate maxHeight and range
    maxHeight = (initialVelocity * initialVelocity * pow(sin(angle), 2)) / (2 * 9.81);
    range = (initialVelocity * initialVelocity * sin(2 * angle)) / 9.81;

    //print results
    printf("\nDistance: %.2lf m\n", distance);
    printf("Time of flight: %.2lf s\n", time);
    printf("Maximum height: %.2lf m\n", maxHeight);
    printf("Range: %.2lf m\n", range);

    return 0;
}