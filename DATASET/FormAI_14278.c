//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x; 
    double y; 
} Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double angle(Point a, Point b, Point c) { 
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    return acos((ab*ab + bc*bc - ac*ac) / (2*ab*bc)) * 180.0 / PI;
}

void print_triangle(Point a, Point b, Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    double perimeter = ab + bc + ac;
    double s = perimeter / 2;
    double area = sqrt(s * (s - ab) * (s - bc) * (s - ac));

    printf("Triangle ABC:\n");
    printf("A: (%.2f, %.2f)\n", a.x, a.y);
    printf("B: (%.2f, %.2f)\n", b.x, b.y);
    printf("C: (%.2f, %.2f)\n", c.x, c.y);
    printf("AB: %.2f\n", ab);
    printf("BC: %.2f\n", bc);
    printf("AC: %.2f\n", ac);
    printf("Perimeter: %.2f\n", perimeter);
    printf("Area: %.2f\n", area);
    printf("Angle BAC: %.2f degrees\n", angle(b, a, c));
    printf("Angle ABC: %.2f degrees\n", angle(a, b, c));
    printf("Angle ACB: %.2f degrees\n", angle(a, c, b));
}

int main() {
    Point a = {2.0, 1.0};
    Point b = {5.0, 3.0};
    Point c = {4.0, 6.0};
    print_triangle(a, b, c);
    return 0;
}