//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>

// Define the Point struct to represent a point in 2D space
typedef struct Point {
    float x;
    float y;
} Point;

// Define the Triangle struct to represent a triangle in 2D space
typedef struct Triangle {
    Point a;
    Point b;
    Point c;
} Triangle;

// Calculate the distance between two points
float distance(Point p1, Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculate the area of a triangle given the lengths of its sides
float areaFromSides(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// Calculate the area of a triangle given its vertices
float areaFromVertices(Point a, Point b, Point c) {
    float side_a = distance(b, c);
    float side_b = distance(a, c);
    float side_c = distance(a, b);
    return areaFromSides(side_a, side_b, side_c);
}

int main() {
    // Define a triangle with vertices at (0,0), (3,0), and (0,4)
    Triangle t = {
        .a = { .x = 0, .y = 0 },
        .b = { .x = 3, .y = 0 },
        .c = { .x = 0, .y = 4 }
    };
    
    // Calculate the area of the triangle
    float area = areaFromVertices(t.a, t.b, t.c);
    
    printf("The area of the triangle is %f\n", area);
    
    return 0;
}