//FormAI DATASET v1.0 Category: Fractal Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct {
    int x;
    int y;
} Point;

void drawPoints(Point *points, int size, int offsetx, int offsety) {
    int i;
    for (i = 0; i < size; i++) {
        int x = (int) (offsetx + points[i].x);
        int y = (int) (offsety + points[i].y);
        printf("%d %d\n", x, y);
    }
}

void fractal(Point *points, int size, int offsetx, int offsety) {
    if (size == 3) {
        drawPoints(points, size, offsetx, offsety);
    } else {
        Point temp[size * 4];
        int i, j, k;
        for (i = 0; i < size; i++) {
            j = (i + 1) % size;
            temp[i * 4].x = points[i].x;
            temp[i * 4].y = points[i].y;
            temp[i * 4 + 1].x = (points[i].x + points[j].x) / 2;
            temp[i * 4 + 1].y = (points[i].y + points[j].y) / 2;
            temp[i * 4 + 2].x = (points[i].x + 2 * points[j].x) / 3;
            temp[i * 4 + 2].y = (points[i].y + 2 * points[j].y) / 3;
            temp[i * 4 + 3].x = (2 * points[i].x + points[j].x) / 3;
            temp[i * 4 + 3].y = (2 * points[i].y + points[j].y) / 3;
        }
        fractal(temp, size * 4, offsetx, offsety);
        fractal(temp + size, size * 4, offsetx + WIDTH / pow(2, log2(size)), offsety);
        fractal(temp + size * 2, size * 4, offsetx + WIDTH / pow(2, log2(size)), offsety + HEIGHT / pow(2, log2(size)));
        fractal(temp + size * 3, size * 4, offsetx, offsety + HEIGHT / pow(2, log2(size)));
    }
}

int main() {
    srand(time(NULL));
    Point points[3] = {
        {200, 100},
        {100, 500},
        {400, 400},
    };
    printf("%d %d moveto\n", points[0].x, points[0].y);
    printf("%d %d lineto\n", points[1].x, points[1].y);
    printf("%d %d lineto\n", points[2].x, points[2].y);
    printf("%d %d lineto\n", points[0].x, points[0].y);
    fractal(points, 3, 0, 0);
    return 0;
}