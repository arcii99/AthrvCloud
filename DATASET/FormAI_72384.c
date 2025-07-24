//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define MAX_ITERATIONS 500
#define WIDTH 1000
#define HEIGHT 1000

void write_image(double *data, char *filename);

int main() {
    int i, j, n;
    double x, y;
    double complex z, c;
    double *data = calloc(WIDTH * HEIGHT, sizeof(double));

    // Generate fractal
    for (j=0; j<HEIGHT; j++) {
        for (i=0; i<WIDTH; i++) {
            x = (double) i / WIDTH * 3.5 - 2.5;
            y = (double) j / HEIGHT * 2 - 1;

            z = x + y * I;
            c = z;

            for (n=0; n<MAX_ITERATIONS; n++) {
                z = z*z + c;

                if (creal(z)*creal(z) + cimag(z)*cimag(z) > 4) {
                    break;
                }
            }

            data[j * WIDTH + i] = (double) n / MAX_ITERATIONS;
        }
    }

    // Write image to file
    write_image(data, "fractal.bmp");

    free(data);
    return 0;
}

void write_image(double *data, char *filename) {
    FILE *file;
    int i, j;
    unsigned char color[3];

    file = fopen(filename, "wb");

    // BMP header
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 24, 0
    };
    int file_size = 54 + WIDTH * HEIGHT * 3;
    header[2] = (unsigned char) (file_size);
    header[3] = (unsigned char) (file_size >> 8);
    header[4] = (unsigned char) (file_size >> 16);
    header[5] = (unsigned char) (file_size >> 24);
    fwrite(header, sizeof(unsigned char), 54, file);

    // Data
    for (j=0; j<HEIGHT; j++) {
        for (i=0; i<WIDTH; i++) {
            color[0] = (unsigned char)((1 - data[j * WIDTH + i]) * 255);
            color[1] = color[0];
            color[2] = color[0];
            fwrite(color, sizeof(unsigned char), 3, file);
        }
    }

    fclose(file);
}