//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    double x1, y1, x2, y2, distance;

    // Prompt user to enter coordinates of two points
    printf("Enter the coordinates of two points (x1, y1) and (x2, y2): ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    
    // Calculate the distance between the two points using the distance formula
    distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    
    // Print the distance
    printf("The distance between the two points is: %lf\n", distance);

    return 0;
}