//FormAI DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const int WIDTH = 512;
const int HEIGHT = 512;
const int MAX_ITER = 100;

bool is_in_set(double x, double y)
{
    double cx = x;
    double cy = y;
    double zx = 0;
    double zy = 0;
    double tmp;
    int i = 0;

    while (i < MAX_ITER)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;

        if (sqrt(zx * zx + zy * zy) > 2)
        {
            return false;
        }

        i++;
    }

    return true;
}

int main()
{
    FILE *fp;
    fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);

    for (int y = -HEIGHT / 2; y < HEIGHT / 2; y++)
    {
        for (int x = -WIDTH / 2; x < WIDTH / 2; x++)
        {
            double xf = (double)x / (WIDTH / 4);
            double yf = (double)y / (HEIGHT / 4);

            if (is_in_set(xf, yf))
            {
                fputc(0, fp);
                fputc(0, fp);
                fputc(0, fp);
            }
            else
            {
                fputc(255, fp);
                fputc(255, fp);
                fputc(255, fp);
            }
        }
    }

    fclose(fp);
}