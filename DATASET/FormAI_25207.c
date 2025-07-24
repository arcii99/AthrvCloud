//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Instance of a geometric calcultor
typedef struct GeometricCalculator
{
    int sides; 
    int radius;
    float apothem;
} GeometricCalculator;

// Function to calculate the area of a regular polygon
float area_of_regular_polygon(int n, int r)
{
    GeometricCalculator geoCalc;
    geoCalc.sides = n;
    geoCalc.radius = r;
    geoCalc.apothem = r * cos(PI / n);

    return (0.5 * geoCalc.sides * geoCalc.radius * geoCalc.apothem);
}

// Main function to test program
int main()
{
    int numSides, rad;
    float result;

    printf("Welcome to the Geometric Calculator!\n");
    
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);

    printf("Enter the radius of the polygon: ");
    scanf("%d", &rad);

    result = area_of_regular_polygon(numSides, rad);
    
    printf("The area of the regular polygon with %d sides and a radius of %d is: %.2f\n", numSides, rad, result);

    return 0;
}