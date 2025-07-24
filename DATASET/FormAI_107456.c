//FormAI DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define ITERATIONS 500

void set_pixel(unsigned char *image, int x, int y, unsigned char v) {
    image[(y * WIDTH + x) * 3] = v;
    image[(y * WIDTH + x) * 3 + 1] = v;
    image[(y * WIDTH + x) * 3 + 2] = v;
}

int fractal_iteration(double x, double y) {
    int i;
    double zx = 0, zy = 0, mod_z;
    for (i = 0; i < ITERATIONS; i++) {
        double tx = zx, ty = zy;
        zx = tx * tx - ty * ty + x;
        zy = 2 * tx * ty + y;
        mod_z = sqrt(zx * zx + zy * zy);
        if (mod_z > 2) {
            return i;
        }
    }
    return ITERATIONS;
}

int main() {
    unsigned char image[WIDTH * HEIGHT * 3];
    const double zoom = 1.5, shift_x = -WIDTH / 2.0, shift_y = -HEIGHT / 2.0;
    const double fractal_x = -0.5, fractal_y = 0;
    int i, j;

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            double x = (i + shift_x) / (WIDTH / 2.0) / zoom + fractal_x;
            double y = (j + shift_y) / (HEIGHT / 2.0) / zoom + fractal_y;
            int n = fractal_iteration(x, y);
            unsigned char v = 255 - n * 255 / ITERATIONS;
            set_pixel(image, i, j, v);
        }
    }
    FILE *f = fopen("fractal.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT * 3, f);
    fclose(f);
    return 0;
}