//FormAI DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 100
#define MAX_ANGLE 180
#define PI 3.14159265359

int main()
{
    printf("Starting movement control program...\n");

    // initialize seed for random number generation
    srand(time(NULL));

    int distance = rand() % MAX_DISTANCE + 1;
    int angle = rand() % MAX_ANGLE + 1;

    // convert angle to radians
    double angle_in_radians = angle * PI / 180.0;

    // calculate x and y components of movement vector
    double x = distance * cos(angle_in_radians);
    double y = distance * sin(angle_in_radians);

    printf("Moving robot %d units forward at a %d degree angle...\n", distance, angle);
    printf("New robot position: (%.2f, %.2f)\n", x, y);

    printf("Ending movement control program.\n");
    return 0;
}