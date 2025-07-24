//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>

/* function to check if a complex number is in the mandelbrot set */
int mandelbrot_check(double real, double imag, int max_iter) {
    double z_real = 0, z_imag = 0;
    int i;

    for (i = 0; i < max_iter; i++) {
        /* calculate new real and imaginary components of z */
        double z_real_new = (z_real * z_real) - (z_imag * z_imag) + real;
        double z_imag_new = 2 * z_real * z_imag + imag;
        z_real = z_real_new;
        z_imag = z_imag_new;

        /* if z escapes the circle of radius 2, we know it's not in the mandelbrot set */
        if ((z_real * z_real + z_imag * z_imag) >= 4) {
            return 0;
        }
    }

    /* if we reach max_iter, we assume it's in the mandelbrot set */
    return 1;
}

/* function to generate a mandelbrot set fractal image */
void mandelbrot_fractal(int width, int height, double cx_min, double cx_max, double cy_min, double cy_max, int max_iter) {
    double x_step = (cx_max - cx_min) / (double)width;
    double y_step = (cy_max - cy_min) / (double)height;

    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            /* calculate complex number corresponding to this pixel */
            double cx = cx_min + (x * x_step);
            double cy = cy_min + (y * y_step);

            /* check if this complex number is in the mandelbrot set */
            int in_set = mandelbrot_check(cx, cy, max_iter);

            /* print a character based on whether this complex number is in the mandelbrot set */
            if (in_set) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main() {
    /* generate a mandelbrot set fractal image with the following parameters */
    mandelbrot_fractal(50, 25, -2, 2, -1, 1, 50);

    return 0;
}