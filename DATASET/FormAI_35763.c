//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <math.h>

// Define a structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Define a function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Define a function to calculate the area of a triangle
double area(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p1, p3);
    double c = distance(p2, p3);
    double s = (a + b + c) / 2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
    // Define three points to form a triangle
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};
    
    // Calculate and print the distance between two points
    printf("The distance between p1 and p2 is: %f\n", distance(p1, p2));
    
    // Calculate and print the area of the triangle
    printf("The area of the triangle is: %f\n", area(p1, p2, p3));
    
    return 0;
}