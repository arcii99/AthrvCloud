//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

// Define a structure to represent a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Define a function to calculate the distance between two 2D points
double distance(Point a, Point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx*dx + dy*dy);
}

// Define a function to calculate the area of a triangle given its three vertices
double triangle_area(Point a, Point b, Point c) {
    double side_a = distance(a, b);
    double side_b = distance(b, c);
    double side_c = distance(c, a);
    double s = (side_a + side_b + side_c) / 2;
    return sqrt(s*(s-side_a)*(s-side_b)*(s-side_c));
}

// Define a function to calculate the centroid of a triangle given its three vertices
Point triangle_centroid(Point a, Point b, Point c) {
    Point centroid;
    centroid.x = (a.x + b.x + c.x) / 3;
    centroid.y = (a.y + b.y + c.y) / 3;
    return centroid;
}

int main() {
    // Define some example points to create a triangle
    Point a = {0, 0};
    Point b = {3, 0};
    Point c = {2, 2};

    // Calculate and print the area and centroid of the triangle
    double area = triangle_area(a, b, c);
    printf("Triangle area: %f\n", area);

    Point centroid = triangle_centroid(a, b, c);
    printf("Triangle centroid: (%f,%f)\n", centroid.x, centroid.y);

    return 0;
}