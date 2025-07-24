//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

struct Point {
    int x, y;
};

typedef struct Point Point;

float distance(Point p1, Point p2) {
    int x_diff = p2.x - p1.x;
    int y_diff = p2.y - p1.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int area(Point p1, Point p2, Point p3) {
    int a = distance(p1, p2);
    int b = distance(p2, p3);
    int c = distance(p3, p1);
    int s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    Point a = {1, 2};
    Point b = {3, 4};
    Point c = {5, 6};

    printf("Distance between points a and b: %.2f\n", distance(a, b));
    printf("Distance between points b and c: %.2f\n", distance(b, c));
    printf("Distance between points a and c: %.2f\n", distance(a, c));

    printf("Area of triangle abc: %d\n", area(a, b, c));

    return 0;
}