//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define WIDTH 800
#define HEIGHT 800
#define MAXDEPTH 200
#define TOLERANCE 1e-8
#define THREADS 8

struct complex_num {
    double real, imag;
};

// function to square a complex number
struct complex_num square(struct complex_num a) {
    struct complex_num result;
    result.real = a.real * a.real - a.imag * a.imag;
    result.imag = 2 * a.real * a.imag;
    return result;
}

// function to add two complex numbers
struct complex_num add(struct complex_num a, struct complex_num b) {
    struct complex_num result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// function to compute the magnitude of a complex number
double magnitude(struct complex_num a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

// function to compute the Mandelbrot escape time for a given pixel
int mandelbrot_escape_time(int x, int y) {
    struct complex_num c, z, zsq;
    int i;
    double mag;

    c.real = (double)x / WIDTH * 2 - 1.5;
    c.imag = (double)y / HEIGHT * 2 - 1;

    z.real = z.imag = 0;

    for (i = 0; i < MAXDEPTH; i++) {
        zsq = square(z);
        z = add(zsq, c);
        mag = magnitude(z);
        if (mag > 2.0) {
            return i;
        }
    }
    return -1;
}

// function to write the color value of a given pixel to a ppm file
void write_pixel(FILE *fp, int r, int g, int b) {
    fprintf(fp, "%d %d %d ", r, g, b);
}

// function to generate the entire Mandelbrot set
void generate_mandelbrot() {
    FILE *fp;
    int x, y, escape_time, i;
    double hue, saturation, value, red, green, blue;

    fp = fopen("mandelbrot.ppm", "w");
    fprintf(fp, "P3 %d %d 255\n", WIDTH, HEIGHT);

    #pragma omp parallel for shared(fp) private(x, y, escape_time, hue, saturation, value, red, green, blue) num_threads(THREADS)
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            escape_time = mandelbrot_escape_time(x, y);
            if (escape_time == -1) {
                write_pixel(fp, 0, 0, 0);
            } else {
                hue = (double)escape_time / MAXDEPTH * 360.0;
                saturation = 1.0;
                value = 1.0;
                for (i = 0; i < 6; i += 2) {
                    if (hue >= i * 60.0 && hue <= (i + 1) * 60.0) {
                        red = value;
                        green = (hue - i * 60.0) / 60.0 * value;
                        blue = 0;
                        break;
                    } else if (hue >= (i + 1) * 60.0 && hue <= (i + 2) * 60.0) {
                        red = ((i + 2) * 60.0 - hue) / 60.0 * value;
                        green = value;
                        blue = 0;
                        break;
                    } else if (hue >= (i + 2) * 60.0 && hue <= (i + 3) * 60.0) {
                        red = 0;
                        green = value;
                        blue = (hue - (i + 2) * 60.0) / 60.0 * value;
                        break;
                    } else if (hue >= (i + 3) * 60.0 && hue <= (i + 4) * 60.0) {
                        red = 0;
                        green = ((i + 4) * 60.0 - hue) / 60.0 * value;
                        blue = value;
                        break;
                    } else if (hue >= (i + 4) * 60.0 && hue <= (i + 5) * 60.0) {
                        red = (hue - (i + 4) * 60.0) / 60.0 * value;
                        green = 0;
                        blue = value;
                        break;
                    } else {
                        red = value;
                        green = 0;
                        blue = ((i + 6) * 60.0 - hue) / 60.0 * value;
                        break;
                    }
                }
                write_pixel(fp, (int)(red * 255), (int)(green * 255), (int)(blue * 255));
            }
        }
    }
    fclose(fp);
}

int main() {
    generate_mandelbrot();
    return 0;
}