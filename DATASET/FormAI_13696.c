//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>

// Define a struct to represent a point in 2D space
struct Point {
    double x;
    double y;
};

// Define a function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Define a function to calculate the area of a triangle given its three vertices
double area(struct Point p1, struct Point p2, struct Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // Define some points
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 0};
    struct Point p3 = {0, 4};

    // Calculate the area of the triangle with these points
    double a = area(p1, p2, p3);
    
    // Output the result
    printf("The area of the triangle with vertices (%f, %f), (%f, %f), and (%f, %f) is %f.",
           p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, a);

    return 0;
}