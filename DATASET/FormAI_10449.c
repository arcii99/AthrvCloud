//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Structure to represent a point in the 2D coordinate system
typedef struct Point {
    double x;
    double y;
} Point;

// Function to compute the distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Define three points that form a triangle
    Point A = {1.0, 1.0};
    Point B = {5.0, 1.0};
    Point C = {3.0, 4.0};
    
    // Compute the length of each side of the triangle
    double a = distance(B, C);
    double b = distance(A, C);
    double c = distance(A, B);
    
    // Compute the perimeter and area of the triangle
    double perimeter = a + b + c;
    double s = perimeter / 2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    
    // Output the results
    printf("Perimeter: %f\n", perimeter);
    printf("Area: %f\n", area);
    
    return 0;
}