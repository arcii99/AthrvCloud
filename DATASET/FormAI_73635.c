//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
// This program calculates the area and perimeter of a rectangle and a circle
// based on user input of their dimensions.

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int shape;
    float length, width, radius, area, perimeter;

    // Prompt user to select a shape and input its dimensions
    printf("Please select a shape (enter 1 for rectangle, 2 for circle): ");
    scanf("%d", &shape);

    if (shape == 1) { // Rectangle
        // Prompt user to input length and width
        printf("Please enter the length and width of the rectangle, separated by a space: ");
        scanf("%f %f", &length, &width);

        // Calculate area and perimeter using rectangle formulas
        area = length * width;
        perimeter = 2 * (length + width);

        // Display results
        printf("Area of the rectangle: %.2f\n", area);
        printf("Perimeter of the rectangle: %.2f\n", perimeter);
    }
    else if (shape == 2) { // Circle
        // Prompt user to input radius
        printf("Please enter the radius of the circle: ");
        scanf("%f", &radius);

        // Calculate area and circumference using circle formulas
        area = PI * pow(radius, 2);
        perimeter = 2 * PI * radius;

        // Display results
        printf("Area of the circle: %.2f\n", area);
        printf("Circumference of the circle: %.2f\n", perimeter);
    }
    else { // Invalid input
        printf("Invalid shape selection.\n");
        return 1;
    }

    return 0;
}