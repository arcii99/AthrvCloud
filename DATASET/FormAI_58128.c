//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>

void mandelbrot(int x1, int x2, int y1, int y2, int max_iter)
{
    int w = 120, h = 40;
    double zoom = 1;
    double x, y, zx, zy, zx2, zy2, tmp;
    int i, j, iter;
    while (1)
    {
        printf("\033[H");
        y = y1;
        for (j = 0; j < h; j++)
        {
            x = x1;
            for (i = 0; i < w; i++)
            {
                zx = 0, zy = 0, iter = 0;
                while (iter < max_iter && zx * zx + zy * zy < 4)
                {
                    zx2 = zx * zx, zy2 = zy * zy;
                    zy = 2 * zx * zy + y;
                    zx = zx2 - zy2 + x;
                    iter++;
                }
                if (iter == max_iter)
                    putchar(' ');
                else if (iter > max_iter / 2)
                    putchar('-');
                else if (iter > max_iter / 4)
                    putchar('+');
                else
                    putchar('*');
                x += zoom * (x2 - x1) / w;
            }
            putchar('\n');
            y += zoom * (y2 - y1) / h;
        }
        zoom *= 0.8;
        x1 += (x2 - x1) * 0.1;
        x2 -= (x2 - x1) * 0.1;
        y1 += (y2 - y1) * 0.1;
        y2 -= (y2 - y1) * 0.1;
    }
}

int main()
{
    mandelbrot(-2, 2, -1, 1, 50);
    return 0;
}