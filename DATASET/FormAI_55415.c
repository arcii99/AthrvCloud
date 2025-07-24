//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area, perimeter;

    printf("Enter the coordinates of first point (x1, y1): ");
    scanf("%f%f", &x1, &y1);
    printf("Enter the coordinates of second point (x2, y2): ");
    scanf("%f%f", &x2, &y2);
    printf("Enter the coordinates of third point (x3, y3): ");
    scanf("%f%f", &x3, &y3);

    // calculate the length of sides of the triangle
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // calculate the perimeter of the triangle
    perimeter = a + b + c;

    // calculate the semi-perimeter of the triangle
    s = perimeter / 2;

    // calculate the area of the triangle
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("The length of the sides of the triangle are:\n");
    printf("Side a: %f\n", a);
    printf("Side b: %f\n", b);
    printf("Side c: %f\n", c);
    printf("The perimeter of the triangle is: %f\n", perimeter);
    printf("The area of the triangle is: %f\n", area);

    return 0;
}