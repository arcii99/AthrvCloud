//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 300
#define HEIGHT 300
#define MAX_ITERATIONS 1000

typedef struct {
    double x, y;
} Complex;

// Function to perform complex arithmetic

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.x = a.x * b.x - a.y * b.y;
    result.y = a.x * b.y + a.y * b.x;
    return result;
}

Complex square(Complex a) {
    Complex result;
    result.x = a.x * a.x - a.y * a.y;
    result.y = 2 * a.x * a.y;
    return result;
}

// Function to generate fractal image

void generateFractal(char *filename, Complex c) {
    int i, j, k, color;
    double x, y, distance;
    Complex z, temp;
    FILE *fp;

    fp = fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    // Iterate over all pixels
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            // Calculate initial z value
            x = (double)i / WIDTH * 3 - 2;
            y = (double)j / HEIGHT * 3 - 1.5;
            z.x = x;
            z.y = y;

            // Iterate to determine color
            color = 0;
            for(k = 0; k < MAX_ITERATIONS; k++) {
                if(z.x * z.x + z.y * z.y > 4) {
                    break;
                }

                temp = multiply(z, z);
                temp.x += c.x;
                temp.y += c.y;

                z = temp;
                color++;
            }

            // Calculate distance from point to fractal boundary
            distance = (log(log(sqrt(z.x * z.x + z.y * z.y)))) / log(2);

            // Map color and distance to RGB values
            if(k < MAX_ITERATIONS) {
                color = 255 - (color * 255 / MAX_ITERATIONS);
                fprintf(fp, "%d 0 %d ", color, color); // Shades of purple
            } else {
                distance = fmin(distance / 60, 1); // Normalize distance
                color = (int)(distance * 255);
                fprintf(fp, "%d %d %d ", color, color, 255); // Shades of blue
            }
        }
    }

    fclose(fp);
}

int main() {
    Complex c;
    c.x = -0.5;
    c.y = 0.6;

    generateFractal("fractal.ppm", c);

    return 0;
}