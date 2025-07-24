//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

// Struct to represent a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return dist;
}

// Function to calculate the area of a triangle using Heron's formula
double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    return area;
}

// Function to check if a point lies inside a triangle
int pointInsideTriangle(Point p, Point t1, Point t2, Point t3) {
    double area1 = triangleArea(p, t1, t2);
    double area2 = triangleArea(p, t2, t3);
    double area3 = triangleArea(p, t3, t1);
    double totalArea = triangleArea(t1, t2, t3);
    
    if (area1 + area2 + area3 == totalArea) {
        return 1;
    } else {
        return 0;
    }
}

// Main function to test the above functions
int main() {
    // Define points
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {3, 3};
    Point p4 = {1, 1};
    
    // Calculate areas
    double area1 = triangleArea(p1, p2, p3);
    double area2 = triangleArea(p1, p4, p2);
    double area3 = triangleArea(p2, p4, p3);
    double area4 = triangleArea(p3, p4, p1);
    double totalArea = area2 + area3 + area4;
    
    // Print results
    printf("Area of triangle ABC: %lf\n", area1);
    printf("Area of triangle PAB: %lf\n", area2);
    printf("Area of triangle PBC: %lf\n", area3);
    printf("Area of triangle PAC: %lf\n", area4);
    printf("Total area of PAB, PBC, PAC: %lf\n", totalArea);
    
    // Check if point is inside triangle
    Point p5 = {2, 1};
    if (pointInsideTriangle(p5, p1, p2, p3)) {
        printf("Point (%lf, %lf) is inside triangle ABC\n", p5.x, p5.y);
    } else {
        printf("Point (%lf, %lf) is NOT inside triangle ABC\n", p5.x, p5.y);
    }
    
    return 0;
}