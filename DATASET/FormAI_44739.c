//FormAI DATASET v1.0 Category: Fractal Generation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void draw_fractal(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        printf("draw line from (%d,%d) to (%d,%d)\n", x1, y1, x2, y2);
    } else {
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;
        draw_fractal(x1, y1, xm, ym, depth - 1);
        draw_fractal(xm, ym, x2, y2, depth - 1);
        draw_fractal(x1, y1, x2, y2, depth - 1);
    }
}

int main() {
    int x1 = 0, y1 = 0, x2 = 100, y2 = 100, depth = 5;
    draw_fractal(x1, y1, x2, y2, depth);
    return 0;
}