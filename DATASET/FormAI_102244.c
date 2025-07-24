//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 1000

int main(int argc, char *argv[]) {
    int x, y, n;
    double zx, zy, cx, cy, tempx;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            zx = 0.0;
            zy = 0.0;
            cx = ((double) x - WIDTH/2) / (double) (WIDTH/4);
            cy = ((double) y - HEIGHT/2) / (double) (HEIGHT/4);
            n = 0;
            while (zx*zx + zy*zy < 4.0 && n < MAX_ITERATIONS) {
                tempx = zx*zx - zy*zy + cx;
                zy = 2*zx*zy + cy;
                zx = tempx;
                n++;
            }
            if (n == MAX_ITERATIONS) {
                putchar('.');
            }
            else {
                putchar('#');
            }
        }
        putchar('\n');
    }
    return 0;
}