//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {

    // define starting and ending points
    double startX = 2.0;
    double startY = 4.0;
    double endX = 10.0;
    double endY = 12.0;

    // calculate distance between starting and ending points
    double distance = sqrt(pow((endX - startX), 2) + pow((endY - startY), 2));

    // calculate angle between starting and ending points
    double angle = atan2((endY - startY), (endX - startX)) * 180 / PI;

    // print out directions
    printf("Starting Point: (%.1lf, %.1lf)\n", startX, startY);
    printf("Ending Point: (%.1lf, %.1lf)\n", endX, endY);
    printf("Distance: %.2lf units\n", distance);
    printf("Angle: %.2lf degrees\n", angle);
    printf("Head %.2lf degrees.\n", angle + 180);

    return 0;
}