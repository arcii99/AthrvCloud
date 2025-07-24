//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: genious
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point;

bool isPointInsideCircle(Point center, double radius, Point p) {
    double dx = center.x - p.x;
    double dy = center.y - p.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= radius;
}

int main() {
    Point center = {3, 4};
    double radius = 5.0;
    Point p1 = {0, 0};
    Point p2 = {4, 5};

    if (isPointInsideCircle(center, radius, p1)) {
        printf("Point p1 is inside the circle\n");
    } else {
        printf("Point p1 is not inside the circle\n");
    }

    if (isPointInsideCircle(center, radius, p2)) {
        printf("Point p2 is inside the circle\n");
    } else {
        printf("Point p2 is not inside the circle\n");
    }

    return 0;
}