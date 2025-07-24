//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    float a, b, c, perimeter, area, s;

    printf("Enter the coordinates of vertex A (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of vertex B (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of vertex C (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Calculating the length of each side of the triangle
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculating the perimeter of the triangle
    perimeter = a + b + c;

    // Calculating the semi-perimeter of the triangle
    s = perimeter / 2;

    // Calculating the area of the triangle using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("\nPerimeter of the triangle: %.2f", perimeter);
    printf("\nArea of the triangle: %.2f", area);

    return 0;
}