//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct Circle {
    Point center;
    double radius;
} Circle;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int intersects(Circle c1, Circle c2) {
    double d = distance(c1.center, c2.center);
    return d <= c1.radius + c2.radius;
}

int main() {
    Circle c1 = {{0, 0}, 1};
    Circle c2 = {{2, 2}, 2};
    
    if (intersects(c1, c2))
        printf("The circles intersect!\n");
    else
        printf("The circles do not intersect.\n");
    
    return 0;
}