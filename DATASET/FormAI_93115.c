//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point p1;
    point p2;
} line;

void draw_line(line l, int depth, int max_depth) {
    if (depth >= max_depth) {
        printf("drawLine(%f, %f, %f, %f);\n", l.p1.x, l.p1.y, l.p2.x, l.p2.y);
    } else {
        point mid = { (l.p1.x + l.p2.x) / 2, (l.p1.y + l.p2.y) / 2 };
        double dx = l.p2.x - l.p1.x;
        double dy = l.p2.y - l.p1.y;
        double angle = atan2(dy, dx);
        double length = sqrt(dx * dx + dy * dy);

        line left = { l.p1, mid };
        line right = { mid, l.p2 };

        left.p2.x = mid.x + length / 2 * cos(angle + M_PI / 4);
        left.p2.y = mid.y + length / 2 * sin(angle + M_PI / 4);
        right.p1.x = mid.x + length / 2 * cos(angle - M_PI / 4);
        right.p1.y = mid.y + length / 2 * sin(angle - M_PI / 4);

        draw_line(left, depth + 1, max_depth);
        draw_line(right, depth + 1, max_depth);
    }
}

int main() {
    line l = { { 0, 0 }, { 100, 0 } };
    draw_line(l, 0, 6);
    return 0;
}