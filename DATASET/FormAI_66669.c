//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>

/*
This program calculates the area and circumference of a circle given its radius.
It then calculates the area and perimeter of a square whose side length is equal
to the circle's diameter
*/

int main() {
    
    float radius, diameter, circle_area, circle_circumference, square_area, square_perimeter;
    
    printf("Please enter the radius of the circle: ");
    scanf("%f", &radius);
    
    diameter = radius * 2;
    circle_area = M_PI * pow(radius, 2);
    circle_circumference = M_PI * diameter;
    square_area = pow(diameter, 2);
    square_perimeter = 4 * diameter;
    
    printf("\nCircle information:");
    printf("\nRadius: %.2f", radius);
    printf("\nDiameter: %.2f", diameter);
    printf("\nArea: %.2f", circle_area);
    printf("\nCircumference: %.2f", circle_circumference);
    
    printf("\n\nSquare information:");
    printf("\nSide length: %.2f", diameter);
    printf("\nArea: %.2f", square_area);
    printf("\nPerimeter: %.2f\n", square_perimeter);
    
    return 0;
}