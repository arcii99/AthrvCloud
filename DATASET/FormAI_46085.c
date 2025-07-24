//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Define constants */
#define WIDTH 640
#define HEIGHT 480
#define MAX_ITERATIONS 255
#define ZOOM_FACTOR 1.2

/* Define complex number struct */
typedef struct {
    double real;
    double imag;
} complex;

/* Define color struct */
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

/* Define function to map pixel coordinates to the complex plane */
complex map_to_complex_plane(int x, int y, double zoom, complex offset) {
    complex result;
    result.real = (x - WIDTH / 2) / (WIDTH / 4.0 * zoom) + offset.real;
    result.imag = (y - HEIGHT / 2) / (HEIGHT / 4.0 * zoom) + offset.imag;
    return result;
}

/* Define function to check if a point is in the Mandelbrot set */
int in_mandelbrot_set(complex c) {
    complex z;
    z.real = 0;
    z.imag = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        complex z_squared;
        z_squared.real = z.real * z.real - z.imag * z.imag;
        z_squared.imag = 2 * z.real * z.imag;
        z.real = z_squared.real + c.real;
        z.imag = z_squared.imag + c.imag;
        if (z.real * z.real + z.imag * z.imag > 4) {
            return i;
        }
    }
    return -1;
}

/* Define function to generate a random color */
color random_color() {
    srand(time(NULL));
    color result;
    result.r = rand() % 256;
    result.g = rand() % 256;
    result.b = rand() % 256;
    return result;
}

/* Define function to generate and save a Mandelbrot set image */
void generate_fractal(double zoom, complex offset, char *filename) {
    /* Declare variables */
    int i, j;
    FILE *file;
    color *pixels = (color *)malloc(WIDTH * HEIGHT * sizeof(color));
    if (pixels == NULL) {
        printf("Error allocating memory for pixels\n");
        exit(EXIT_FAILURE);
    }

    /* Generate image pixel by pixel */
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            complex c = map_to_complex_plane(i, j, zoom, offset);
            int iterations = in_mandelbrot_set(c);
            color pixel_color;
            if (iterations == -1) {
                pixel_color.r = 0;
                pixel_color.g = 0;
                pixel_color.b = 0;
            } else {
                pixel_color = random_color();
            }
            pixels[i * HEIGHT + j] = pixel_color;
        }
    }

    /* Write image data to file */
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        fwrite(&pixels[i], sizeof(color), 1, file);
    }
    fclose(file);

    /* Free allocated memory */
    free(pixels);
}

/* Main function */
int main() {
    complex offset;
    offset.real = 0;
    offset.imag = 0;
    double zoom = 1.0;
    int i;
    for (i = 0; i < 10; i++) {
        char filename[20];
        sprintf(filename, "fractal%d.ppm", i);
        generate_fractal(zoom, offset, filename);
        zoom *= ZOOM_FACTOR;
    }
    return 0;
}