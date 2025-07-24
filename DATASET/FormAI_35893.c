//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 24

void fractal(double x1, double y1, double x2, double y2, int depth, int pattern);

int main()
{
    fractal(-2.0, -1.0, 1.0, 1.0, 6, 1);
    return 0;
}

void fractal(double x1, double y1, double x2, double y2, int depth, int pattern)
{
    int x, y, i, j, c;
    double cx, cy, zx, zy, zx2, zy2, tmp;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            cx = x1 + (x2-x1) * x / (WIDTH - 1);
            cy = y1 + (y2-y1) * y / (HEIGHT - 1);

            zx = 0.0;
            zy = 0.0;
            zx2 = 0.0;
            zy2 = 0.0;
            for (i = 0; i < depth; i++)
            {
                tmp = zx2 - zy2 + cx;
                zy = 2 * zx * zy + cy;
                zx = tmp;
                zx2 = zx * zx;
                zy2 = zy * zy;
                if (zx2 + zy2 > 4.0) break;
            }
            c = pattern * i % 16;
            if (i == depth) c = 16;
            printf("\033[3%dm%c\033[0m", c, "@$#*+;:. "[c/2]);
        }
        printf("\n");
    }
}