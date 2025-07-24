//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int max_iter = 500;
    double x_min = -2.0, x_max = 2.0, y_min = -2.0, y_max = 2.0;
    double x, y, x_new, y_new, x_temp;
    int i, j, iter;

    int width = 80, height = 80;
    double x_step = (x_max - x_min) / width;
    double y_step = (y_max - y_min) / height;
    char pixel = '.';

    for (j = height - 1; j >= 0; j--) {
        y = y_min + j * y_step;
        for (i = 0; i < width; i++) {
            x = x_min + i * x_step;
            x_new = 0.0; y_new = 0.0; iter = 0;

            while (iter < max_iter && (x_new * x_new + y_new * y_new) < 4.0) {
                x_temp = x_new * x_new - y_new * y_new + x;
                y_new = 2.0 * x_new * y_new + y;
                x_new = x_temp;
                iter++;
            }

            if (iter == max_iter || (x_new * x_new + y_new * y_new) >= 4.0) {
                putchar(pixel);
            } else {
                pixel = 'a' + (int) round((iter * 25.0 / max_iter));
                putchar(pixel);
            }
        }
        putchar('\n');
    }

    return 0;
}