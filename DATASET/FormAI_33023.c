//FormAI DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_ITER 500

typedef struct complex {
    double real;
    double imag;
} COMPLEX;

COMPLEX add(COMPLEX a, COMPLEX b) {
    COMPLEX c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

COMPLEX multiply(COMPLEX a, COMPLEX b) {
    COMPLEX c;
    c.real = (a.real * b.real) - (a.imag * b.imag);
    c.imag = (a.real * b.imag) + (a.imag * b.real);
    return c;
}

double square(COMPLEX z) {
    return (z.real * z.real) + (z.imag * z.imag);
}

int main() {
    int x, y, iter, pixel;
    COMPLEX c, z, temp;
    double range = 2.0;
    double zoom = 1.0;
    double x_off = -0.5;
    double y_off = 0.0;
    double dx = range * zoom / (double)WIDTH;
    double dy = range * zoom / (double)HEIGHT;
    double min_radius = 0.25;
    double max_radius = 2.0;
    double radius_step = 0.5;
    int num_circles = (int)((max_radius - min_radius) / radius_step) + 1;
    double radius[num_circles];
    for (int i = 0; i < num_circles; i++) {
        radius[i] = min_radius + (i * radius_step);
    }
    int circle_id;
    int color[num_circles];
    srand(time(NULL));
    for (int i = 0; i < num_circles; i++) {
        color[i] = rand() % (256 * 256 * 256);
    }

    unsigned char image[HEIGHT][WIDTH][3];
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            c.real = ((double)x / (double)WIDTH) * range * zoom + x_off - range * zoom / 2.0;
            c.imag = -((double)y / (double)HEIGHT) * range * zoom + y_off + range * zoom / 2.0;
            pixel = 0;
            for (int i = 0; i < num_circles; i++) {
                z.real = 0.0;
                z.imag = 0.0;
                iter = 0;
                circle_id = i * (int)(MAX_ITER / num_circles);
                while ((iter < MAX_ITER) && (square(z) < radius[i]*radius[i])) {
                    z = add(multiply(z, z), c);
                    iter++;
                }
                if (iter == MAX_ITER) {
                    pixel = color[circle_id];
                    break;
                }
            }
            image[y][x][0] = (pixel >> 16) & 0xFF;
            image[y][x][1] = (pixel >> 8) & 0xFF;
            image[y][x][2] = pixel & 0xFF;
        }
    }

    FILE *fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(image), 1, fp);
    fclose(fp);

    return 0;
}