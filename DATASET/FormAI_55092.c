//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    // Declare Variables
    double x1, x2, y1, y2, distance;

    // Prompt User to Input Variables
    printf("Enter the x coordinate of point 1: ");
    scanf("%lf", &x1);
    printf("Enter the y coordinate of point 1: ");
    scanf("%lf", &y1);
    printf("Enter the x coordinate of point 2: ");
    scanf("%lf", &x2);
    printf("Enter the y coordinate of point 2: ");
    scanf("%lf", &y2);

    // Calculate Distance
    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    // Print Results
    printf("\nThe distance between point 1 (%.2lf, %.2lf) and point 2 (%.2lf, %.2lf) is: %.2lf\n", x1, y1, x2, y2, distance);

    return 0;
}