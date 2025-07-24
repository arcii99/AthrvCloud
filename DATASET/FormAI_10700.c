//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle given its sides using Heron's formula
double calculateTriangleArea(double side1, double side2, double side3) {
    double semiPerimeter = (side1 + side2 + side3) / 2;
    return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}

int main() {
    // Initialize variables for the coordinates of the three vertices of the triangle
    int x1, y1, x2, y2, x3, y3;

    // Prompt user for input
    printf("Enter the coordinates of the first vertex (x1, y1):\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second vertex (x2, y2):\n");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third vertex (x3, y3):\n");
    scanf("%d %d", &x3, &y3);

    // Calculate the length of each side
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate the area of the triangle
    double triangleArea = calculateTriangleArea(side1, side2, side3);

    // Print the length of each side and the area of the triangle
    printf("The length of side 1 is: %lf\n", side1);
    printf("The length of side 2 is: %lf\n", side2);
    printf("The length of side 3 is: %lf\n", side3);
    printf("The area of the triangle is: %lf\n", triangleArea);

    return 0;
}