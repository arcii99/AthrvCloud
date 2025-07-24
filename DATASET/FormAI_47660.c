//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include <stdio.h>
#include <math.h>

struct Point {
    double x, y;
};

struct Line {
    double a, b, c;
};

// Function to calculate distance between two points
double distance(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to calculate slope of a line
double slope(struct Point p1, struct Point p2) {
    if (p1.x == p2.x) {
        return INFINITY;
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}

// Function to calculate equation of a line given two points
struct Line getLine(struct Point p1, struct Point p2) {
    struct Line line;
    line.a = p2.y - p1.y;
    line.b = p1.x - p2.x;
    line.c = line.a * p1.x + line.b * p1.y;
    return line;
}

// Function to calculate intersection point of two lines
struct Point intersect(struct Line line1, struct Line line2) {
    double det = line1.a * line2.b - line2.a * line1.b;
    if (det == 0) {
        printf("Lines are parallel\n");
        return (struct Point){0, 0};
    }
    double x = (line2.b * line1.c - line1.b * line2.c) / det;
    double y = (line1.a * line2.c - line2.a * line1.c) / det;
    return (struct Point){x, y};
}

// Function to calculate area of a triangle given its three vertices
double area(struct Point p1, struct Point p2, struct Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2; // semiperimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to check if a point is inside a triangle
int pointInsideTriangle(struct Point p, struct Point t1, struct Point t2, struct Point t3) {
    double a1 = area(p, t1, t2);
    double a2 = area(p, t2, t3);
    double a3 = area(p, t3, t1);
    double a = area(t1, t2, t3);
    return a1 + a2 + a3 == a;
}

int main() {
    struct Point p1 = {0, 0};
    struct Point p2 = {1, 1};
    struct Line line1 = getLine(p1, p2);
    printf("Line 1: %.2fx + %.2fy = %.2f\n", line1.a, line1.b, line1.c);
    struct Point p3 = {1, 0};
    struct Point p4 = {0, 1};
    struct Line line2 = getLine(p3, p4);
    printf("Line 2: %.2fx + %.2fy = %.2f\n", line2.a, line2.b, line2.c);
    struct Point intersectPoint = intersect(line1, line2);
    printf("Intersection point: (%.2f, %.2f)\n", intersectPoint.x, intersectPoint.y);
    struct Point p5 = {0.5, 0.5};
    struct Point p6 = {1, 0};
    struct Point p7 = {0, 1};
    printf("Area of triangle: %.2f\n", area(p5, p6, p7));
    struct Point p8 = {0.25, 0.25};
    if (pointInsideTriangle(p8, p5, p6, p7)) {
        printf("Point is inside triangle\n");
    } else {
        printf("Point is outside triangle\n");
    }
    return 0;
}