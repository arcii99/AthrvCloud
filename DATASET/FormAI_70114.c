//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>
#include <math.h>

// Compute the area of a triangle given three vertices, using Heron's formula
float area_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));  // Distance between points (x1, y1) and (x2, y2)
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));  // Distance between points (x2, y2) and (x3, y3)
    float c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));  // Distance between points (x1, y1) and (x3, y3)
    float s = (a + b + c) / 2;  // Half of the triangle's perimeter
    float area = sqrt(s * (s - a) * (s - b) * (s - c));  // Heron's formula for computing the triangle's area
    return area;
}

int main() {
    printf("This program computes the area of a triangle given three vertices.\n\n");
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first vertex (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second vertex (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third vertex (x3, y3): ");
    scanf("%f %f", &x3, &y3);
    float area = area_of_triangle(x1, y1, x2, y2, x3, y3);
    printf("\nThe area of the triangle with vertices (%.1f, %.1f), (%.1f, %.1f), and (%.1f, %.1f) is %.1f\n",
           x1, y1, x2, y2, x3, y3, area);
    return 0;
}