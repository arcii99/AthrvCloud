//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Point {
    double x;
    double y;
};

struct Circle {
    struct Point center;
    double radius;
};

double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double perimeter(struct Circle c) {
    return 2 * PI * c.radius;
}

double area(struct Circle c) {
    return PI * c.radius * c.radius;
}

struct Circle findCircle(struct Point a, struct Point b, struct Point c) {
    struct Circle circle;
    double ma = (b.y - a.y) / (b.x - a.x);
    double mb = (c.y - b.y) / (c.x - b.x);

    circle.center.x = (ma*mb*(a.y - c.y) + mb*(a.x + b.x) - ma*(b.x + c.x)) / (2*(mb-ma));
    circle.center.y = (-1/ma) * (circle.center.x - (a.x + b.x)/2) + (a.y + b.y)/2;
    circle.radius = distance(circle.center, a);
    return circle;
}

int main() {
    struct Point a, b, c;
    printf("Enter coordinates of point A: ");
    scanf("%lf %lf", &a.x, &a.y);
    printf("Enter coordinates of point B: ");
    scanf("%lf %lf", &b.x, &b.y);
    printf("Enter coordinates of point C: ");
    scanf("%lf %lf", &c.x, &c.y);

    struct Circle mystery_circle = findCircle(a, b, c);
    printf("Mystery circle center: (%.2lf, %.2lf)\n", mystery_circle.center.x, mystery_circle.center.y);
    printf("Mystery circle radius: %.2lf\n", mystery_circle.radius);

    double mystery_circle_area = area(mystery_circle);
    double mystery_circle_perimeter = perimeter(mystery_circle);
    printf("Mystery circle area: %.2lf\n", mystery_circle_area);
    printf("Mystery circle perimeter: %.2lf\n", mystery_circle_perimeter);

    return 0;
}