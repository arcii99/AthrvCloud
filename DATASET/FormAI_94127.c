//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int width = 2000;
    int height = 2000;
    int max_iter = 1000;

    double zoom = 0.8;
    double x_shift = -1.8;
    double y_shift = -1.8;

    int i, j;
    double x, y, x_temp, z_real, z_imaginary, c_real, c_imaginary;
    
    char matrix[width][height];

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            x = ((double)i / width) * (zoom * 6.4) - (zoom * 3.2) + x_shift;
            y = ((double)j / height) * (zoom * 6.4) - (zoom * 3.2) + y_shift;

            z_real = 0;
            z_imaginary = 0;
            c_real = x;
            c_imaginary = y;

            int iter = 0;
            while ((pow(z_real, 2) + pow(z_imaginary, 2) < 4) && (iter < max_iter)) {
                x_temp = z_real;
                z_real = pow(z_real, 2) - pow(z_imaginary, 2) + c_real;
                z_imaginary = 2 * x_temp * z_imaginary + c_imaginary;
                iter++;
            }

            if (iter == max_iter) {
                matrix[i][j] = ' ';
            } else {
                matrix[i][j] = 'X';
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (matrix[j][i] == 'X') {
                printf("\033[38;2;%d;%d;%dmX", i % 256, j % 256, (i + j) % 256);
            } else {
                printf("\033[38;2;0;0;0m ");
            }
        }
        printf("\n");
    }

    return 0;
}