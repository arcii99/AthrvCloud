//FormAI DATASET v1.0 Category: Fractal Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int width = 800;
    int height = 800;
    int max_iterations = 1000;
    double zoom = 1.5;
    double move_x = -0.5;
    double move_y = 0;
    
    double x, y, x_new;
    double zx, zy, zx_new, zy_new;
    double pixel_width = 4.0 / width;
    double pixel_height = 4.0 / height;
    int i, j, k;
    
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            zx = (i * pixel_width - 2.0) / zoom + move_x;
            zy = (j * pixel_height - 2.0) / zoom + move_y;

            k = 0;

            while (zx * zx + zy * zy < 4 && k < max_iterations) {
                zx_new = zx * zx - zy * zy + x;
                zy_new = 2 * zx * zy + y;
                zx = zx_new;
                zy = zy_new;
                k++;
            }

            if (k == max_iterations) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}