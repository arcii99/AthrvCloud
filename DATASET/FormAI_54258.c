//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multivariable
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 100
#define ZOOM 350

int main() {
    srand(time(NULL));
    double cx_min = -2.0;
    double cx_max = 1.0;
    double cy_min = -1.5;
    double cy_max = 1.5;
    double real_range = cx_max - cx_min;
    double imag_range = cy_max - cy_min;
    double cx, cy, zx, zy, real_zx, imag_zy;
    int iter, color;

    bool is_mandelbrot[WIDTH][HEIGHT];

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {

            is_mandelbrot[x][y] = true;

            cx = (double)x * real_range / WIDTH + cx_min;
            cy = (double)y * imag_range / HEIGHT + cy_min;

            zx = cx;
            zy = cy;

            for(iter = 0; iter < MAX_ITER; iter++) {
                real_zx = zx * zx - zy * zy + cx;
                imag_zy = 2.0 * zx * zy + cy;

                zx = real_zx;
                zy = imag_zy;

                if(zx * zx + zy * zy > 4.0) {
                    is_mandelbrot[x][y] = false;
                    break;
                }
            }

            if(is_mandelbrot[x][y]) {
                color = 0x000000;
            } else {
                double fractional_iter = (double)iter + 1.0 - log(log(sqrt(zx * zx + zy * zy))) / log(2.0);
                color = (long)(((double)rand() / (double)RAND_MAX) * (double)0xFFFFFF);
            }

            printf("\033[48;2;%d;%d;%dm  \033[0m", color >> 16, (color >> 8) & 0xFF, color & 0xFF);
        }
        printf("\n");
    }

    return 0;
}