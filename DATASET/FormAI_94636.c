//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store a point
struct Point
{
    int x, y;
};

// Calculates the distance between two points
float distance(struct Point p1, struct Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Calculates the area of a triangle using Heron's formula
float area(struct Point p1, struct Point p2, struct Point p3)
{
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Calculates the centroid of a triangle
struct Point centroid(struct Point p1, struct Point p2, struct Point p3)
{
    struct Point c;
    c.x = (p1.x + p2.x + p3.x) / 3;
    c.y = (p1.y + p2.y + p3.y) / 3;
    return c;
}

// Main function
int main()
{
    // Initialize three points of a triangle
    struct Point p1 = {2, 3};
    struct Point p2 = {7, 10};
    struct Point p3 = {13, 4};

    // Calculate the area of the triangle and print it
    printf("Area of triangle: %0.2f\n", area(p1, p2, p3));

    // Calculate the centroid of the triangle and print it
    struct Point c = centroid(p1, p2, p3);
    printf("Centroid of triangle: (%d, %d)", c.x, c.y);

    return 0;
}