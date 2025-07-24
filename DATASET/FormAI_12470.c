//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

int main() {
    // Provide three points to form a triangle
    float x1, y1, x2, y2, x3, y3;

    // Get user input for points of triangle
    printf("Enter the coordinates for point 1: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates for point 2: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates for point 3: ");
    scanf("%f %f", &x3, &y3);

    // Calculate the sides of the triangle
    float a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    float b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    float c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));

    // Calculate the semi-perimeter of the triangle
    float s = (a + b + c) / 2.0f;

    // Calculate the area of the triangle using Heron's formula
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Print the area of the triangle
    printf("The area of the triangle is: %f square units.\n", area);

    // Calculate the perimeter of the triangle
    float perimeter = a + b + c;

    // Print the perimeter of the triangle
    printf("The perimeter of the triangle is: %f units.\n", perimeter);

    // Calculate the centroid of the triangle
    float xc = (x1 + x2 + x3) / 3.0f;
    float yc = (y1 + y2 + y3) / 3.0f;

    // Print the coordinates of the centroid of the triangle
    printf("The centroid of the triangle is at: (%f, %f).\n", xc, yc);

    return 0;
}