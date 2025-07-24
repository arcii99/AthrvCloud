//FormAI DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ITER 100

int mandelbrot(double x, double y) {
    int iter = 0;
    double zx = 0, zy = 0, zx_new, zy_new;

    while (zx * zx + zy * zy < 4 && iter < MAX_ITER) {
        zx_new = zx * zx - zy * zy + x;
        zy_new = 2 * zx * zy + y;
        zx = zx_new;
        zy = zy_new;
        iter++;
    }

    return iter;
}

int main() {
    int i, j, iter;
    double x, y, zoom = 1.0, zoom_step = 0.01;

    while (1) {
        for (j = 0; j < HEIGHT; j++) {
            for (i = 0; i < WIDTH; i++) {
                x = (i - WIDTH / 2.0) / (zoom * WIDTH / 4.0);
                y = (j - HEIGHT / 2.0) / (zoom * HEIGHT / 4.0);
                iter = mandelbrot(x, y);

                if (iter < MAX_ITER / 2) {
                    putchar(' ');
                } else if (iter < MAX_ITER * 3 / 4) {
                    putchar('.');
                } else if (iter < MAX_ITER) {
                    putchar('*');
                } else {
                    putchar('#');
                }
            }
            putchar('\n');
        }

        printf("\nZoom Level: %lf\n", zoom);
        printf("Controls:\n");
        printf("  [W]  Move Up\n");
        printf("  [A]  Move Left\n");
        printf("  [S]  Move Down\n");
        printf("  [D]  Move Right\n");
        printf("  [Q]  Zoom In\n");
        printf("  [E]  Zoom Out\n");
        printf("  [X]  Exit\n");

        switch (getchar()) {
            case 'w':
            case 'W':
                printf("Moving Up\n");
                break;
            case 'a':
            case 'A':
                printf("Moving Left\n");
                break;
            case 's':
            case 'S':
                printf("Moving Down\n");
                break;
            case 'd':
            case 'D':
                printf("Moving Right\n");
                break;
            case 'q':
            case 'Q':
                printf("Zooming In\n");
                zoom -= zoom_step;
                break;
            case 'e':
            case 'E':
                printf("Zooming Out\n");
                zoom += zoom_step;
                break;
            case 'x':
            case 'X':
                printf("Exiting\n");
                return 0;
            default:
                break;
        }

        getchar();
        system("clear");
    }

    return 0;
}