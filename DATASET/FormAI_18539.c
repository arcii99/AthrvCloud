//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include<stdio.h>
#include<math.h>

int main()
{
    // declare variables
    float x1, y1, x2, y2, distance;
    printf("Enter the x-coordinate of the first point: ");
    scanf("%f", &x1);
    printf("Enter the y-coordinate of the first point: ");
    scanf("%f", &y1);
    printf("Enter the x-coordinate of the second point: ");
    scanf("%f", &x2);
    printf("Enter the y-coordinate of the second point: ");
    scanf("%f", &y2);

    // calculate distance between two points
    distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    // print the result
    printf("Distance between the two points: %f", distance);

    return 0;
}