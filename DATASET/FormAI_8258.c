//FormAI DATASET v1.0 Category: Fractal Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct point {
    double x, y;
} Point;

void drawFractal(Point p1, Point p2, int depth);

int main() {
    Point p1 = {-1.0, -1.0};
    Point p2 = {1.0, 1.0};
    srand(time(NULL));
    drawFractal(p1, p2, 0);
    return 0;
}

void drawFractal(Point p1, Point p2, int depth) {
    if (depth >= 5) return;

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dist = sqrt(dx * dx + dy * dy);

    if (dist <= 0.1) return;

    double r1 = (double)rand() / RAND_MAX;
    double r2 = (double)rand() / RAND_MAX;

    Point p3 = {p1.x + dx / 3.0 + r1 * dy / 3.0, p1.y + dy / 3.0 - r1 * dx / 3.0};
    Point p4 = {p1.x + 2.0 * dx / 3.0 + r2 * dy / 3.0, p1.y + 2.0 * dy / 3.0 - r2 * dx / 3.0};

    drawFractal(p1, p3, depth + 1);
    drawFractal(p3, p4, depth + 1);
    drawFractal(p4, p2, depth + 1);

    printf("%.2f,%.2f ", p2.x, p2.y);
}