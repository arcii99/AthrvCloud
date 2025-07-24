//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
    float a = 3.0, b = 4.0, c = 5.0;

    // Calculate the area of a triangle using Heron's formula
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("The area of the triangle is: %f\n", area);

    // Calculate the perimeter of the triangle
    float perimeter = a + b + c;
    printf("The perimeter of the triangle is: %f\n", perimeter);

    // Calculate the circumradius of the triangle (R = abc / 4A)
    float circumradius = (a * b * c) / (4 * area);
    printf("The circumradius of the triangle is: %f\n", circumradius);

    // Calculate the inradius of the triangle (r = A / s)
    float inradius = area / s;
    printf("The inradius of the triangle is: %f\n", inradius);

    // Calculate the distance between the circumcenter and incenter (d = 2Rr)
    float distance = 2 * circumradius * inradius;
    printf("The distance between the circumcenter and incenter is: %f\n", distance);

    // Calculate the coordinates of the circumcenter (x,y) = (a,b) + (AB / 2sinC)
    float x_circumcenter = a + ((b * b - c * c) / (2 * a));
    float y_circumcenter = sqrt(b * b - x_circumcenter * x_circumcenter);
    printf("The circumcenter is at (%f, %f)\n", x_circumcenter, y_circumcenter);

    // Calculate the coordinates of the incenter (x,y) = (a,b) + (r / p)(a - b + c, -a + b + c)
    float x_incenter = (a + inradius * (a - b + c)) / perimeter;
    float y_incenter = (a + inradius * (-a + b + c)) / perimeter;
    printf("The incenter is at (%f, %f)\n", x_incenter, y_incenter);

    return 0;
}