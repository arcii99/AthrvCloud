//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <math.h>

// Define a Point struct
struct Point {
    double x;
    double y;
};

// Define a function to calculate the distance between two points
double distance(struct Point a, struct Point b) {
    return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
}

// Define a function to calculate the perimeter of a triangle given three points
double trianglePerimeter(struct Point a, struct Point b, struct Point c) {
    return distance(a, b) + distance(b, c) + distance(c, a);
}

int main() {
    // Initialize three points
    struct Point a = {0, 0};
    struct Point b = {3, 4};
    struct Point c = {6, 0};
    
    // Calculate the perimeter of the triangle formed by these points
    double perimeter = trianglePerimeter(a, b, c);
    
    // Print the perimeter
    printf("Perimeter: %f\n", perimeter);
    
    return 0;
}