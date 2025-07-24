//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point in 2D space
typedef struct Point
{
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to calculate the perimeter of a triangle
double perimeter(Point a, Point b, Point c)
{
    return distance(a, b) + distance(b, c) + distance(c, a);
}

// Function to calculate the area of a triangle
double area(Point a, Point b, Point c)
{
    double s = perimeter(a, b, c) / 2.0;
    return sqrt(s * (s - distance(a, b)) * (s - distance(b, c)) * (s - distance(c, a)));
}

int main()
{
    // Define three points
    Point a = {0, 0};
    Point b = {3, 0};
    Point c = {0, 4};

    // Calculate and print the perimeter and area of the triangle
    printf("Perimeter: %f\n", perimeter(a, b, c));
    printf("Area: %f\n", area(a, b, c));

    return 0;
}