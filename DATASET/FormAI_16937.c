//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <math.h>

// define a structure to store a 2D point
struct Point {
    double x;
    double y;
};

// function to calculate distance between two points
double distance(struct Point a, struct Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// function to calculate area of a triangle (Heron's formula)
double areaTriangle(struct Point a, struct Point b, struct Point c) {
    double s = (distance(a, b) + distance(b, c) + distance(c, a)) / 2.0;
    return sqrt(s * (s - distance(a, b)) * (s - distance(b, c)) * (s - distance(c, a)));
}

// function to check if a point is inside a triangle
int isInsideTriangle(struct Point a, struct Point b, struct Point c, struct Point p) {
    double A = areaTriangle(a, b, c);
    double A1 = areaTriangle(p, b, c);
    double A2 = areaTriangle(a, p, c);
    double A3 = areaTriangle(a, b, p);
    return A == A1 + A2 + A3;
}

int main() {
    struct Point a = {0, 0};
    struct Point b = {3, 0};
    struct Point c = {0, 4};
    struct Point p = {1, 1};
    
    // calculate distance between two points
    printf("Distance between points a and b: %.2f\n", distance(a, b));
    
    // calculate area of a triangle
    printf("Area of triangle abc: %.2f\n", areaTriangle(a, b, c));
    
    // check if a point is inside a triangle
    if (isInsideTriangle(a, b, c, p)) {
        printf("Point p is inside triangle abc.\n");
    } else {
        printf("Point p is not inside triangle abc.\n");
    }
    
    return 0;
}