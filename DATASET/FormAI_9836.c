//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: genious
#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    float a, b, c; // length of the sides of the triangle
    float s, area; // semi-perimeter and area of the triangle

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // calculate the length of the sides of the triangle
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // calculate the semi-perimeter
    s = (a + b + c) / 2;

    // calculate the area of the triangle
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("\nSide lengths: a = %f, b = %f, c = %f\n", a, b, c);
    printf("Semi-perimeter: s = %f\n", s);
    printf("Area of the triangle: area = %f\n", area);

    return 0;
}