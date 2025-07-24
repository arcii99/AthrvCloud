//FormAI DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

void drawFractal(Point s, Point e, int depth) {
    if (depth <= 0) {
        printf("%lf,%lf\n", e.x, e.y);
        return;
    }
    Point left, right, middle;
    double dx, dy, angle;
    dx = e.x - s.x;
    dy = e.y - s.y;
    middle.x = s.x + dx / 2;
    middle.y = s.y + dy / 2;

    angle = M_PI / 3.0;
    left.x = middle.x + sin(angle) * dy / 3.0;
    left.y = middle.y - sin(angle) * dx / 3.0;
    drawFractal(s, middle, depth - 1);
    drawFractal(middle, e, depth - 1);
    drawFractal(left, middle, depth - 1);
}

int main() {
    int depth = 5;
    Point start, end;
    start.x = 0.0;
    start.y = 0.0;
    end.x = 1.0;
    end.y = 0.0;
    drawFractal(start, end, depth);
    return 0;
}