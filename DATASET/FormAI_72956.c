//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

// Function to calculate the area of a triangle with three given sides
double calcTriangleArea(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to calculate the distance between two given points on a Cartesian plane
double calcPointDistance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// Function to calculate the area of a circle with a given radius
double calcCircleArea(double radius)
{
    return PI * radius * radius;
}

int main()
{
    double a, b, c;
    printf("Enter the lengths of the three sides of a triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double triangle_area = calcTriangleArea(a, b, c);
    printf("The area of the triangle is: %.2f\n", triangle_area);

    double x1, y1, x2, y2;
    printf("Enter the coordinates of two points on a Cartesian plane: ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    double point_distance = calcPointDistance(x1, y1, x2, y2);
    printf("The distance between the two points is: %.2f\n", point_distance);

    double radius;
    printf("Enter the radius of a circle: ");
    scanf("%lf", &radius);
    double circle_area = calcCircleArea(radius);
    printf("The area of the circle is: %.2f\n", circle_area);

    return 0;
}