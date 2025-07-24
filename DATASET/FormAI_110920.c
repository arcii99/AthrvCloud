//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct Point {
    double x, y;
};

double getDistance(struct Point p1, struct Point p2) {
    double xDiff = p2.x - p1.x;
    double yDiff = p2.y - p1.y;
    return sqrt((xDiff * xDiff) + (yDiff * yDiff));
}

double getAngle(struct Point p1, struct Point p2) {
    double angle = atan2(p2.y - p1.y, p2.x - p1.x);
    return angle < 0 ? angle + (2 * PI) : angle;
}

struct Point getIntersection(struct Point l1p1, struct Point l1p2, struct Point l2p1, struct Point l2p2) {
    double a1 = l1p1.y - l1p2.y;
    double b1 = l1p2.x - l1p1.x;
    double c1 = a1 * l1p1.x + b1 * l1p1.y;
    double a2 = l2p1.y - l2p2.y;
    double b2 = l2p2.x - l2p1.x;
    double c2 = a2 * l2p1.x + b2 * l2p1.y;
    double determinant = a1 * b2 - a2 * b1;
    if (determinant == 0) {
        printf("The lines are parallel.\n");
        return (struct Point){.x = NAN, .y = NAN};
    } else {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return (struct Point){.x = x, .y = y};
    }
}

int isPointInsideTriangle(struct Point p, struct Point t1, struct Point t2, struct Point t3) {
    double d1, d2, d3, sum;
    d1 = getDistance(p, t1);
    d2 = getDistance(p, t2);
    d3 = getDistance(p, t3);
    sum = getDistance(t1, t2) + getDistance(t2, t3) + getDistance(t3, t1);
    return d1 + d2 + d3 <= sum;
}

int main() {
    struct Point p1 = {.x = 0, .y = 0};
    struct Point p2 = {.x = 5, .y = 5};
    struct Point p3 = {.x = 10, .y = 0};
    struct Point p4 = {.x = 5, .y = -5};
    struct Point intersection = getIntersection(p1, p2, p3, p4);
    printf("Intersection: (%.2f, %.2f)\n", intersection.x, intersection.y);
    struct Point t1 = {.x = 3, .y = 3};
    struct Point t2 = {.x = 7, .y = 7};
    struct Point t3 = {.x = 5, .y = 0};
    struct Point testPoint = {.x = 4, .y = 4};
    printf("Is point inside triangle? %d\n", isPointInsideTriangle(testPoint, t1, t2, t3));
    return 0;
}