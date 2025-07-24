//FormAI DATASET v1.0 Category: Fractal Generation ; Style: real-life
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} complex;

complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

complex multiply(complex a, complex b) {
    complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

void draw_fractal(int width, int height, int max_iter) {
    complex c, z, temp;
    int x, y, i;
    double real_min = -2.0, real_max = 1.0, imag_min = -1.5, imag_max = 1.5;
    double real_range = real_max - real_min;
    double imag_range = imag_max - imag_min;
    double pixel_width = real_range / (double)width;
    double pixel_height = imag_range / (double)height;
    printf("P3\n%d %d\n255\n", width, height);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            c.real = real_min + ((double)x * pixel_width);
            c.imag = imag_min + ((double)y * pixel_height);
            z.real = 0.0;
            z.imag = 0.0;
            for (i = 0; i < max_iter; i++) {
                temp = z;
                z = add(multiply(z, z), c);
                if ((z.real * z.real + z.imag * z.imag) > 4.0) {
                    break;
                }
            }
            printf("%d %d %d ", (i*8)%256, (i*32)%256, (i*64)%256);
        }
        printf("\n");
    }
}

int main() {
    draw_fractal(640, 480, 256);
    return 0;
}