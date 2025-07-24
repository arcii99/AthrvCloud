//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include<stdio.h>
#include<math.h>

struct point {
    double x;
    double y;
};

typedef struct point Point;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double area(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};

    double triArea = area(p1, p2, p3);

    printf("Triangle with vertices (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    printf("has area %.2f\n", triArea);

    return 0;
}