//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

// Calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Calculate the area of a triangle using Heron's formula
double triangle_area(struct Point p1, struct Point p2, struct Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // Calculate the area of a triangle with vertices (0, 0), (0, 1), (1, 0)
    struct Point p1 = {0, 0};
    struct Point p2 = {0, 1};
    struct Point p3 = {1, 0};
    double area = triangle_area(p1, p2, p3);
    printf("The area of the triangle is: %f", area);
    return 0;
}