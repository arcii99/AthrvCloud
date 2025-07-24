//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

// Function to calculate the Euclidean distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a triangle given its three vertices
double triangleArea(Point p1, Point p2, Point p3) {
    double s = (distance(p1,p2) + distance(p2,p3) + distance(p3,p1)) / 2.0;
    return sqrt(s*(s-distance(p1,p2))*(s-distance(p2,p3))*(s-distance(p3,p1)));
}

// Function to check if a point is inside a triangle using barycentric coordinates
int pointInTriangle(Point p, Point a, Point b, Point c) {
    // Calculate the areas of the sub-triangles formed by the point and each of the triangle's edges
    double area1 = triangleArea(p,a,b);
    double area2 = triangleArea(p,b,c);
    double area3 = triangleArea(p,c,a);
    // Calculate the area of the whole triangle
    double wholeArea = triangleArea(a,b,c);
    // Check if the sum of the sub-triangles' areas is equal to the whole triangle's area
    return (fabs(area1 + area2 + area3 - wholeArea) < 1e-4);
}

int main() {
    Point a = {0,0};
    Point b = {5,0};
    Point c = {2.5,4.33};
    Point p = {4,2};
    
    // Check if point p is inside triangle abc
    if (pointInTriangle(p,a,b,c)) {
        printf("Point (%.2lf, %.2lf) is inside triangle ABC\n", p.x, p.y);
    }
    else {
        printf("Point (%.2lf, %.2lf) is outside triangle ABC\n", p.x, p.y);
    }
    
    return 0;
}