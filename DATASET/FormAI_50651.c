//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Define a struct for a point
struct Point {
    double x;
    double y;
};

// Compute the distance between two points
double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Compute the area of a triangle given its three vertices
double area(struct Point p1, struct Point p2, struct Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // Define three points to form a triangle
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 4};
    struct Point p3 = {6, 0};

    // Compute the area of the triangle
    double a = area(p1, p2, p3);

    // Print the result
    printf("The area of the triangle is %f\n", a);

    return 0;
}