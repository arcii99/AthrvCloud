//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

struct Point {
    double x;
    double y;
};

double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double angle(struct Point p1, struct Point p2) {
    double rads = atan2(p2.y - p1.y, p2.x - p1.x);
    return rads * 180 / PI;
}

void drawLine(struct Point p1, struct Point p2) {
    printf("Drawing line from (%.2f, %.2f) to (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y);
}

void drawTriangle(struct Point p1, struct Point p2, struct Point p3) {
    printf("Drawing triangle with vertices (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);

    double A = angle(p1, p2);
    double B = angle(p2, p3);
    double C = angle(p3, p1);

    printf("\tSide lengths: %.2f, %.2f, %.2f\n", a, b, c);
    printf("\tAngles: %.2f deg, %.2f deg, %.2f deg\n", A, B, C);
}

int main() {
    struct Point p1 = {1.0, 2.0};
    struct Point p2 = {3.0, 4.0};
    struct Point p3 = {5.0, 6.0};

    drawLine(p1, p2);

    drawTriangle(p1, p2, p3);

    return 0;
}