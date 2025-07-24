//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>

// structure to represent a point in 2D space
typedef struct {
    float x;
    float y;
} Point;

// function to calculate the distance between two points
float distance(Point p1, Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// function to calculate the area of a triangle given the lengths of its sides
float area_triangle(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // create three points representing the vertices of a triangle
    Point a = {0, 0};
    Point b = {3, 4};
    Point c = {5, 1};

    // calculate the lengths of the sides of the triangle
    float ab = distance(a, b);
    float bc = distance(b, c);
    float ac = distance(a, c);

    // calculate the area of the triangle and print it
    float triangle_area = area_triangle(ab, bc, ac);
    printf("The area of the triangle is: %0.2f\n", triangle_area);

    return 0;
}