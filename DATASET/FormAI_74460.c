//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>

// Struct for a point in 2D space
typedef struct Point {
    float x;
    float y;
} Point;

// Function to calculate the Euclidean distance between two points
float calcDistance(Point p1, Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a triangle given its three vertices
float calcTriangleArea(Point p1, Point p2, Point p3) {
    float a = calcDistance(p1, p2);
    float b = calcDistance(p2, p3);
    float c = calcDistance(p3, p1);
    float s = (a + b + c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // Create three points for a triangle
    Point p1 = {.x = 0.0, .y = 0.0};
    Point p2 = {.x = 5.0, .y = 0.0};
    Point p3 = {.x = 2.5, .y = 4.3};

    // Calculate the area of the triangle
    float area = calcTriangleArea(p1, p2, p3);

    // Print out the area of the triangle
    printf("The area of the triangle formed by (%f,%f), (%f,%f), and (%f,%f) is %f\n",
        p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);

    return 0;
}