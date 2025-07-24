//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50

int main()
{
    int i, j;
    double x, y;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            x = (double)j / (double)WIDTH * 3.5 - 2.5;
            y = (double)i / (double)HEIGHT * 2 - 1;

            int iter = 0;
            double cx = x, cy = y;
            while (iter < 50) {
                double rx = cx * cx - cy * cy + x;
                double ry = 2 * cx * cy + y;
                cx = rx;
                cy = ry;

                if (cx * cx + cy * cy > 4) {
                    break;
                }

                iter++;
            }

            if (iter == 50) {
                printf("#");
            } else if (iter > 30) {
                printf("*");
            } else if (iter > 20) {
                printf(".");
            } else if (iter > 10) {
                printf(" ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}