//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
#include <stdio.h>
#include <math.h>

// Define a data structure to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Define a function to calculate the Euclidean distance between two points
double euclidean_distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Define a function to calculate the area of a triangle given its three vertices
double triangle_area(Point p1, Point p2, Point p3) {
    double a = euclidean_distance(p1, p2);
    double b = euclidean_distance(p2, p3);
    double c = euclidean_distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// Define a function to calculate the circumcenter of a triangle given its three vertices
Point circumcenter(Point p1, Point p2, Point p3) {
    double ma = (p2.y - p1.y) / (p2.x - p1.x);
    double mb = (p3.y - p2.y) / (p3.x - p2.x);
    double x = (ma*mb*(p1.y - p3.y) + mb*(p1.x + p2.x) - ma*(p2.x + p3.x)) / (2.0*(mb - ma));
    double y = (y-ma*(x-(p1.x+p2.x)/2.0) + (p1.y+p2.y)/2.0);
    return (Point) { x, y };
}

int main() {
    // Define three points to form a triangle
    Point p1 = { 0.0, 0.0 };
    Point p2 = { 1.0, 0.0 };
    Point p3 = { 0.0, 1.0 };

    // Calculate the area of the triangle
    double area = triangle_area(p1, p2, p3);
    printf("The area of the triangle is %f\n", area);

    // Calculate the circumcenter of the triangle
    Point center = circumcenter(p1, p2, p3);
    printf("The circumcenter of the triangle is (%f, %f)\n", center.x, center.y);

    return 0;
}