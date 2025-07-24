//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, x3, y3, a, b, c, s, area;

    // prompt the user to enter the coordinates of the three vertices of the triangle
    printf("Enter the coordinates of the first vertex (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second vertex (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third vertex (x3, y3): ");
    scanf("%f %f", &x3, &y3);

    // calculate the length of the sides of the triangle
    a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));

    // calculate the semi-perimeter of the triangle
    s = (a + b + c) / 2;

    // calculate the area of the triangle using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // output the length of the sides and the area of the triangle
    printf("Length of side a: %f\n", a);
    printf("Length of side b: %f\n", b);
    printf("Length of side c: %f\n", c);
    printf("Area of the triangle: %f\n", area);

    return 0;
}