//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

/* function to compute the area of a triangle given the length of its three sides */
double computeTriangleArea(double a, double b, double c)
{
    double s = (a + b + c) / 2; /* half the perimeter */
    return sqrt(s * (s - a) * (s - b) * (s - c)); /* Heron's formula for the area of a triangle */
}

/* function to compute the distance between two points in 2D plane */
double computeDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    double x1, y1, x2, y2, x3, y3, a, b, c, perimeter, area;

    /* read the coordinates of the three vertices of the triangle from the user */
    printf("Enter the coordinates of the three points of the triangle:\n");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    /* compute the lengths of the three sides of the triangle */
    a = computeDistance(x1, y1, x2, y2);
    b = computeDistance(x2, y2, x3, y3);
    c = computeDistance(x3, y3, x1, y1);

    /* compute the perimeter and the area of the triangle */
    perimeter = a + b + c;
    area = computeTriangleArea(a, b, c);

    /* print the perimeter and area of the triangle */
    printf("Perimeter: %.2lf\n", perimeter);
    printf("Area: %.2lf\n", area);

    return 0;
}