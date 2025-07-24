//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 1000
#define MAX_COLOR 255

typedef struct complex {
    double x;
    double y;
} Complex;

void create_fractal(unsigned char *pixels);
Complex add_c(Complex z, Complex c);
Complex square_c(Complex z);

int main() {
    unsigned char pixels[WIDTH * HEIGHT];
    
    create_fractal(pixels);

    FILE *f = fopen("fractal.pgm", "wb");
    fprintf(f, "P5\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);
    fwrite(pixels, WIDTH * HEIGHT, 1, f);
    fclose(f);
    
    return 0;
}

void create_fractal(unsigned char *pixels) {
    Complex c, z, temp_z;
    int i, j, k, iteration_count;
    double x_scale = 3.0 / WIDTH;
    double y_scale = 3.0 / HEIGHT;
    
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            c.x = (j - WIDTH / 2) * x_scale;
            c.y = (i - HEIGHT / 2) * y_scale;
            
            z.x = 0;
            z.y = 0;
            
            iteration_count = 0;
            
            while (iteration_count < MAX_ITERATIONS && (z.x * z.x + z.y * z.y) < 4) {
                temp_z = add_c(square_c(z), c);
                if (temp_z.x == z.x && temp_z.y == z.y) {
                    iteration_count = MAX_ITERATIONS;
                    break;
                }
                z = temp_z;
                iteration_count++;
            }
            
            if (iteration_count == MAX_ITERATIONS) {
                pixels[i * WIDTH + j] = 0;
            }
            else {
                pixels[i * WIDTH + j] = (unsigned char)((double)MAX_COLOR * (double)iteration_count / (double)MAX_ITERATIONS);
            }
        }
    }
}

Complex add_c(Complex z, Complex c) {
    Complex result;
    result.x = z.x + c.x;
    result.y = z.y + c.y;
    return result;
}

Complex square_c(Complex z) {
    Complex result;
    result.x = z.x * z.x - z.y * z.y;
    result.y = 2 * z.x * z.y;
    return result;
}