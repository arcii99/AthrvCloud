//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <math.h>

/* This program takes the coordinates of three points in 2D space,
and calculates the area of the triangle they form, using the
Heron's formula, as well as the coordinates of the circumcenter
of the triangle, which is the center of the circle that passes
through all the vertices of the triangle. */

int main() {
    // Input the coordinates of the three points
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point: ");
    scanf("%f %f", &x3, &y3);

    // Calculate the distance between the three points
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate the semiperimeter of the triangle
    float s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("The area of the triangle is: %f\n", area);

    // Calculate the coordinates of the circumcenter
    float d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (d == 0) {
        printf("The three points are collinear, so there is no circumcenter.\n");
    } else {
        float cx = ((pow(x1, 2) + pow(y1, 2)) * (y2 - y3) +
                    (pow(x2, 2) + pow(y2, 2)) * (y3 - y1) +
                    (pow(x3, 2) + pow(y3, 2)) * (y1 - y2)) / d;
        float cy = ((pow(x1, 2) + pow(y1, 2)) * (x3 - x2) +
                    (pow(x2, 2) + pow(y2, 2)) * (x1 - x3) +
                    (pow(x3, 2) + pow(y3, 2)) * (x2 - x1)) / d;
        printf("The circumcenter of the triangle is: (%f, %f)\n", cx, cy);
    }

    return 0;
}