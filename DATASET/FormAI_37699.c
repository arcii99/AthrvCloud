//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double distance(struct Point a, struct Point b) {
    // calculates the distance between points a and b using the Pythagorean theorem
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double circle_area(struct Point center, double radius) {
    // calculates the area of a circle with given center and radius
    return M_PI * radius * radius;
}

double triangle_area(struct Point a, struct Point b, struct Point c) {
    // calculates the area of a triangle with given vertices a, b, c using the determinant method
    double ax = a.x, ay = a.y;
    double bx = b.x, by = b.y;
    double cx = c.x, cy = c.y;
    return fabs((ax*(by-cy) + bx*(cy-ay) + cx*(ay-by))/2.0);
}

int main() {
    struct Point a = {0, 0};
    struct Point b = {3, 4};
    struct Point c = {6, 0};
    double radius = distance(a, b);
    double area = circle_area(a, radius);
    printf("Circle area: %lf\n", area);
    double triangle = triangle_area(a, b, c);
    printf("Triangle area: %lf\n", triangle);
    return 0;
}