//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <math.h>

// A structure to store a point
typedef struct
{
    double x;
    double y;
} Point;

// Function to calculate distance between two points
double distance(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a triangle using Heron's formula
double triangleArea(Point p1, Point p2, Point p3)
{
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};

    double area = triangleArea(p1, p2, p3);

    printf("The area of the triangle is %.2f\n", area);

    return 0;
}