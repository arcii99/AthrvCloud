//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 50
#define ITERATIONS 50
#define SCALE 0.3

int main(void) {
    int iterations[WIDTH][HEIGHT];
    float x, y, x0, y0, xtemp;
    int i, j, iteration;
    char ascii[10] = {'.', ',', '-', '=', '+', '*', '#', '%', '@', ' '};

    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            x0 = (i - WIDTH/2) * SCALE;
            y0 = (j - HEIGHT/2) * SCALE;
            x = 0;
            y = 0;
            iteration = 0;
            while (x*x + y*y <= 4 && iteration < ITERATIONS) {
                xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;
                iteration++;
            }
            iterations[i][j] = iteration;
        }
    }

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", ascii[iterations[j][i]%10]);
        }
        printf("\n");
    }

    return 0;
}