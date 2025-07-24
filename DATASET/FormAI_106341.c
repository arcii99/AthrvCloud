//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point { double x, y; };

// Calculate the distance between two points
double distance(struct Point a, struct Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// Calculate the perimeter of a triangle
double triangle_perimeter(struct Point a, struct Point b, struct Point c) {
    return distance(a, b) + distance(b, c) + distance(c, a);
}

// Calculate the area of a triangle
double triangle_area(struct Point a, struct Point b, struct Point c) {
    double s = triangle_perimeter(a, b, c) / 2.0;
    double ab = distance(a, b), bc = distance(b, c), ca = distance(c, a);
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

// Calculate the length of the longest side of a triangle
double longest_side(struct Point a, struct Point b, struct Point c) {
    double ab = distance(a, b), bc = distance(b, c), ca = distance(c, a);
    return fmax(fmax(ab, bc), ca);
}

int main() {
    struct Point a = {0.0, 0.0};
    struct Point b = {3.0, 4.0};
    struct Point c = {5.0, 2.0};

    printf("Distance between a and b: %f\n", distance(a, b)); // 5.0
    printf("Perimeter of triangle abc: %f\n", triangle_perimeter(a, b, c)); // 12.4032
    printf("Area of triangle abc: %f\n", triangle_area(a, b, c)); // 6.0000
    printf("Longest side of triangle abc: %f\n", longest_side(a, b, c)); // 5.0

    return 0;
}