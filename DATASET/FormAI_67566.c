//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

point midpoint(point p1, point p2) {
    point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}

void drawSierpinski(point a, point b, point c, int depth) {
    if (depth == 0) {
        printf("Draw triangle (%lf,%lf)-(%lf,%lf)-(%lf,%lf)\n", a.x, a.y, b.x, b.y, c.x, c.y);
    } else {
        point ab = midpoint(a, b);
        point bc = midpoint(b, c);
        point ac = midpoint(a, c);
        drawSierpinski(a, ab, ac, depth - 1);
        drawSierpinski(ab, b, bc, depth - 1);
        drawSierpinski(ac, bc, c, depth - 1);
    }
}

int main() {
    point a = { 0, 0 };
    point b = { 10, 0 };
    point c = { 5, 8.7 };
    drawSierpinski(a, b, c, 5);
    return 0;
}