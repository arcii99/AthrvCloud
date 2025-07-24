//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

int main() {
    // Let's create three points in a 2D plane
    float x1 = 5.0, y1 = 3.0; // First point
    float x2 = 1.0, y2 = 2.0; // Second point
    float x3 = -4.0, y3 = -3.0; // Third point

    // Let's calculate the distance between the first and second point
    float dist12 = distance(x1, y1, x2, y2);

    // Let's calculate the distance between the first and third point
    float dist13 = distance(x1, y1, x3, y3);

    // Let's calculate the distance between the second and third point
    float dist23 = distance(x2, y2, x3, y3);

    // Let's calculate the perimeter of the triangle using the formula P = a + b + c
    float perimeter = dist12 + dist13 + dist23;

    // Let's calculate the area of the triangle using Heron's formula
    float s = perimeter / 2.0; // Calculate the semiperimeter
    float area = sqrt(s * (s - dist12) * (s - dist13) * (s - dist23)); // Calculate the area

    // Let's print the results
    printf("The three points are: (%.1f, %.1f), (%.1f, %.1f), and (%.1f, %.1f)\n", x1, y1, x2, y2, x3, y3);
    printf("The distance between the first and second point is: %.2f\n", dist12);
    printf("The distance between the first and third point is: %.2f\n", dist13);
    printf("The distance between the second and third point is: %.2f\n", dist23);
    printf("The perimeter of the triangle is: %.2f\n", perimeter);
    printf("The area of the triangle is: %.2f\n", area);

    // The program ends here
    return 0;
}