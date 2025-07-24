//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATION 512

int main()
{
    double scale = 1.5;
    double xmin = -2.0 * scale;
    double xmax = 1.0 * scale;
    double ymin = -1.5 * scale;
    double ymax = 1.5 * scale;
    
    double x, y;
    int color, iteration;
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        y = ymin + i * (ymax - ymin) / HEIGHT;
        for (j = 0; j < WIDTH; j++) {
            x = xmin + j * (xmax - xmin) / WIDTH;
            
            double cx = x;
            double cy = y;
            double zx = 0.0, zy = 0.0;
            iteration = 0;

            while (zx * zx + zy * zy < 4.0 && iteration < MAX_ITERATION) {
                double zx_new = zx * zx - zy * zy;
                double zy_new = 2 * zx * zy;
                zx = zx_new + cx;
                zy = zy_new + cy;
                iteration++;
            }

            if (iteration == MAX_ITERATION) {
                color = 0;
            } else {
                double log_zn = log(zx * zx + zy * zy) / 2.0;
                double nu = log(log_zn / log(2.0)) / log(2.0);
                color = (int)(iteration + 1 - nu);
            }
            
            printf(" %d %d %d\n", j, i, color);
        }
    }

    return 0;
}