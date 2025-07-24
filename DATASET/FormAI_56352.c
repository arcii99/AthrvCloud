//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a 2D Point structure
typedef struct Point2D {
    double x;
    double y;
} Point2D;

// Define a vector structure
typedef struct Vector2D {
    double dx;
    double dy;
} Vector2D;

// Function to calculate the dot product of two vectors
double dotProduct(Vector2D v1, Vector2D v2) {
    return v1.dx * v2.dx + v1.dy * v2.dy;
}

// Function to calculate the magnitude of a vector
double magnitude(Vector2D v) {
    return sqrt(v.dx * v.dx + v.dy * v.dy);
}

// Function to calculate the angle between two vectors
double angleBetweenVectors(Vector2D v1, Vector2D v2) {
    double dotP = dotProduct(v1, v2);
    double mag1 = magnitude(v1);
    double mag2 = magnitude(v2);
    return acos(dotP / (mag1 * mag2));
}

// Function to calculate the area of a triangle formed by three points
double triangleArea(Point2D p1, Point2D p2, Point2D p3) {
    double area = 0.5 * ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
    if (area < 0.0) {
        area = -area;
    }
    return area;
}

int main() {
    // Define three points to form a triangle
    Point2D p1 = { 1.0, 1.0 };
    Point2D p2 = { 2.0, 3.0 };
    Point2D p3 = { 4.0, 1.0 };

    // Calculate the vectors between the points
    Vector2D v1 = { p2.x - p1.x, p2.y - p1.y };
    Vector2D v2 = { p3.x - p1.x, p3.y - p1.y };
    Vector2D v3 = { p3.x - p2.x, p3.y - p2.y };

    // Calculate the angles between the vectors
    double angle1 = angleBetweenVectors(v1, v2);
    double angle2 = angleBetweenVectors(v2, v3);
    double angle3 = angleBetweenVectors(v3, v1);

    // Calculate the area of the triangle
    double area = triangleArea(p1, p2, p3);

    // Print the results
    printf("Angle between vectors v1 and v2 = %f radians\n", angle1);
    printf("Angle between vectors v2 and v3 = %f radians\n", angle2);
    printf("Angle between vectors v3 and v1 = %f radians\n", angle3);
    printf("Area of triangle formed by points p1, p2, and p3 = %f square units\n", area);

    return 0;
}