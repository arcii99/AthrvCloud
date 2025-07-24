//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Define a structure to represent a point in 2D cartesian coordinates
typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a triangle given its three vertices
double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // Create three points
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};

    // Calculate the area of the triangle
    double area = triangleArea(p1, p2, p3);

    // Print out the coordinates and area of the triangle
    printf("Triangle vertices:\n");
    printf("(%f, %f)\n", p1.x, p1.y);
    printf("(%f, %f)\n", p2.x, p2.y);
    printf("(%f, %f)\n", p3.x, p3.y);
    printf("Triangle area: %f\n", area);

    return 0;
}