//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

/* This program demonstrates how to calculate the area and perimeter of a regular polygon using geometric formulas */

int main() {

    int sides; // number of sides
    float length; // length of each side
    float radius; // radius of the inscribed circle
    float apothem; // length of the apothem
    float area; // area of the polygon
    float perimeter; // perimeter of the polygon

    // prompt user for input
    printf("Enter the number of sides of the regular polygon: ");
    scanf("%d", &sides);
    printf("Enter the length of each side of the regular polygon: ");
    scanf("%f", &length);

    // calculate the radius and apothem
    radius = length / (2 * sin(M_PI / sides));
    apothem = length / (2 * tan(M_PI / sides));

    // calculate the area and perimeter
    area = (sides / 2.0) * length * apothem;
    perimeter = sides * length;

    // display the results
    printf("The polygon has %d sides, each of length %f units.\n", sides, length);
    printf("The radius of the inscribed circle is %f units.\n", radius);
    printf("The length of the apothem is %f units.\n", apothem);
    printf("The area of the polygon is %f square units.\n", area);
    printf("The perimeter of the polygon is %f units.\n", perimeter);

    return 0;
}