//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Point structure to store x and y values
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate perimeter of triangle with points p1, p2, p3
double triangle_perimeter(Point p1, Point p2, Point p3) {
    double side1 = distance(p1, p2);
    double side2 = distance(p2, p3);
    double side3 = distance(p3, p1);
    return side1 + side2 + side3;
}

// Function to calculate area of triangle with points p1, p2, p3
double triangle_area(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2; // Semi-perimeter of triangle
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Using Heron's formula to calculate area
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {5, 0};
    Point p3 = {0, 5};

    // Calculate perimeter and area of triangle
    double perimeter = triangle_perimeter(p1, p2, p3);
    double area = triangle_area(p1, p2, p3);

    // Print results
    printf("Perimeter of Triangle: %f\n", perimeter);
    printf("Area of Triangle: %f\n", area);

    return 0;
}