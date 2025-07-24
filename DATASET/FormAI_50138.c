//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// A structure to represent a point in a 2D cartesian plane
struct Point
{
    int x, y;
};

// A function to find the distance between two points
float distance(struct Point p1, struct Point p2)
{
    float dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return dist;
}

// A function to find the area of a triangle using Heron's formula
float area(struct Point p1, struct Point p2, struct Point p3)
{
    float s = (distance(p1, p2) + distance(p2, p3) + distance(p3, p1)) / 2; // Semi-perimeter
    float ar = sqrt(s * (s - distance(p1, p2)) * (s - distance(p2, p3)) * (s - distance(p3, p1))); // Heron's formula
    return ar;
}

// A function to find the orientation of three points (clockwise or counter-clockwise)
int orientation(struct Point p1, struct Point p2, struct Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0)
        return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counter-clockwise
}

// A function to check if a point lies inside a triangle or not
int isInside(struct Point p1, struct Point p2, struct Point p3, struct Point p)
{
    int o1 = orientation(p1, p2, p);
    int o2 = orientation(p2, p3, p);
    int o3 = orientation(p3, p1, p);

    if (o1 == 0 || o2 == 0 || o3 == 0)
        return 0; // On the edge
    if (o1 == o2 && o2 == o3)
        return 1; // Inside
    return 0; // Outside
}

// Driver code to test the functions
int main()
{
    struct Point p1 = {0, 0}, p2 = {4, 0}, p3 = {0, 3}, p4 = {2, 1}; // Coordinates of four points

    // Find the area of the triangle
    float ar = area(p1, p2, p3);
    printf("Area of the triangle formed by the points (%d,%d), (%d,%d) and (%d,%d) is: %f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, ar);

    // Check if the point p4 lies inside the triangle or not
    if (isInside(p1, p2, p3, p4))
        printf("The point (%d,%d) lies inside the triangle\n", p4.x, p4.y);
    else
        printf("The point (%d,%d) lies outside the triangle\n", p4.x, p4.y);

    return 0;
}