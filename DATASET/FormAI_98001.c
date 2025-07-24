//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>

// A function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {

    // Get input from the user
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point:\n");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point:\n");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point:\n");
    scanf("%f %f", &x3, &y3);

    // Calculate the length of the sides
    float side1 = distance(x1, y1, x2, y2);
    float side2 = distance(x2, y2, x3, y3);
    float side3 = distance(x3, y3, x1, y1);

    // Calculate the perimeter and semiperimeter
    float perimeter = side1 + side2 + side3;
    float semiperimeter = perimeter / 2;

    // Calculate the area using Heron's formula
    float area = sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));

    // Print the results
    printf("Side 1: %.2f\n", side1);
    printf("Side 2: %.2f\n", side2);
    printf("Side 3: %.2f\n", side3);
    printf("Perimeter: %.2f\n", perimeter);
    printf("Area: %.2f\n", area);

    return 0;
}