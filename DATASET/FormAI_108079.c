//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <math.h> 

int main() {

    int x1, y1, x2, y2;

    printf("Enter the coordinates of point 1 (x1,y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of point 2 (x2,y2): ");
    scanf("%d %d", &x2, &y2);

    int distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    printf("Distance between the two points is: %d\n", distance);

    printf("\n");

    int slope = (y2 - y1) / (x2 - x1);
    printf("Slope of the line passing through the points is: %d\n", slope);

    printf("\n");

    double midx = (x1 + x2) / 2.0;
    double midy = (y1 + y2) / 2.0;
    printf("Midpoint of the line segment is: (%.2f, %.2f)\n", midx, midy);

    printf("\n");

    int angle = atan2((y2 - y1), (x2 - x1)) * (180 / M_PI);
    printf("Angle made by the line with the positive x-axis is: %d degrees\n", angle);

    return 0;
}