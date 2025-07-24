//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

int main()
{
    double complex z, c;
    int x, y;
    int i, j, k;

    char pixels[HEIGHT][WIDTH];

    for(y=0; y<HEIGHT; y++) {
        for(x=0; x<WIDTH; x++) {
            z = c = ((2.3 * x / WIDTH - 1.8) + (1.7 * y / HEIGHT - 0.85) * I);

            for(i=0; i<50; i++) {
                z = z * z + c;
                if (cabs(z) > 2)
                    break;
            }

            if (i == 50) {
                pixels[y][x] = '#';
            } else {
                pixels[y][x] = ' ';
            }
        }
    }

    for(y=0; y<HEIGHT; y++) {
        for(x=0; x<WIDTH; x++) {
            putchar(pixels[y][x]);
        }
        putchar('\n');
    }

    return 0;
}