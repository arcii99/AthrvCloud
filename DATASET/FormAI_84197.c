//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <math.h>

/* This program computes the area and perimeter of a regular polygon */

int main() {

    // Declare variables for input
    int numSides;
    double sideLength;

    // Prompt user for input
    printf("Enter the number of sides of the regular polygon: ");
    scanf("%d", &numSides);
    printf("Enter the length of each side: ");
    scanf("%lf", &sideLength);

    // Calculate area and perimeter
    double apothem = sideLength / (2 * tan(M_PI / numSides));
    double perimeter = numSides * sideLength;
    double area = apothem * perimeter / 2;

    // Output results
    printf("The perimeter of the regular polygon is: %lf\n", perimeter);
    printf("The apothem of the regular polygon is: %lf\n", apothem);
    printf("The area of the regular polygon is: %lf\n", area);

    return 0;
}