//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Line {
    Point start;
    Point end;
} Line;

typedef struct Triangle {
    Line base;
    Point apex;
} Triangle;

int pointDistance(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int getPerimeter(Line line1, Line line2, Line line3) {
    int perimeter = 0;
    perimeter += pointDistance(line1.start, line1.end);
    perimeter += pointDistance(line2.start, line2.end);
    perimeter += pointDistance(line3.start, line3.end);
    return perimeter;
}

Line createLine(int x1, int y1, int x2, int y2) {
    Point start, end;
    start.x = x1;
    start.y = y1;
    end.x = x2;
    end.y = y2;
    Line line = {start, end};
    return line;
}

Triangle createTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    Point apex = {x1, y1};
    Line base1 = createLine(x2, y2, x3, y3);
    Line base2 = createLine(x1, y1, x3, y3);
    Line base3 = createLine(x1, y1, x2, y2);

    int perimeter = getPerimeter(base1, base2, base3);
    printf("Triangle perimeter: %d\n", perimeter);

    Triangle triangle = {base1, apex};
    return triangle;
}

int main() {
    Triangle triangle = createTriangle(2, 2, 8, 2, 5, 6);
    return 0;
}