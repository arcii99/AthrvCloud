//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

unsigned char pixels[WIDTH][HEIGHT][3];

void get_color(int iter, double complex z, unsigned char *r, unsigned char *g, unsigned char *b) {
    if (iter >= MAX_ITER) {
        *r = *g = *b = 0;
        return;
    }

    float h = (float) iter / MAX_ITER;
    float s = 1.0;
    float v = 1.0;
    float c = v * s;
    float x = c * (1 - fabs(fmod(h * 6, 2) - 1));
    float m = v - c;
    float r_, g_, b_;

    if (h < 1.0/6.0) {
        r_ = c;
        g_ = x;
        b_ = 0;
    } else if (h < 2.0/6.0) {
        r_ = x;
        g_ = c;
        b_ = 0;
    } else if (h < 3.0/6.0) {
        r_ = 0;
        g_ = c;
        b_ = x;
    } else if (h < 4.0/6.0) {
        r_ = 0;
        g_ = x;
        b_ = c;
    } else if (h < 5.0/6.0) {
        r_ = x;
        g_ = 0;
        b_ = c;
    } else {
        r_ = c;
        g_ = 0;
        b_ = x;
    }

    *r = (r_ + m) * 255;
    *g = (g_ + m) * 255;
    *b = (b_ + m) * 255;
}

void create_fractal(double complex center, double range) {
    double step = 2 * range / WIDTH;
    double complex z, c;
    unsigned char r, g, b;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            z = center + (i - WIDTH/2 + (j - HEIGHT/2) * I) * step;
            c = z;

            int iter = 0;
            while (iter < MAX_ITER) {
                z = z*z + c;
                if (cabs(z) > 2) break;
                iter++;
            }

            get_color(iter, z, &r, &g, &b);
            pixels[i][j][0] = r;
            pixels[i][j][1] = g;
            pixels[i][j][2] = b;
        }
    }
}

int main() {
    double complex center = -0.7 + 0.2 * I;
    double range = 1.5;

    create_fractal(center, range);

    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(pixels, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    printf("Done!\n");

    return 0;
}