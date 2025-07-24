//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A struct to hold the X and Y coordinates of a point
typedef struct Point
{
    int x;
    int y;
} Point;

// Calculate the distance between two points
double distance(Point a, Point b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Calculate the area of a triangle using Heron's formula
double area(Point a, Point b, Point c)
{
    double s = (distance(a, b) + distance(b, c) + distance(c, a)) / 2.0;
    double product = s * (s - distance(a, b)) * (s - distance(b, c)) * (s - distance(c, a));
    return sqrt(product);
}

int main()
{
    // Create some points
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {1, 4};

    // Calculate the area of the triangle formed by these points
    double areaResult = area(p1, p2, p3);

    // Print the result
    printf("The area of the triangle formed by (%d,%d), (%d,%d), and (%d,%d) is %f\n",
           p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, areaResult);

    return 0;
}