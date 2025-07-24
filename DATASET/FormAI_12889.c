//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80 //change these values to change the final image
#define HEIGHT 40
#define ITERATIONS 100

void draw(double x, double y) {
    double r,g,b;
    double zx,zy,zx2,zy2;
    double cx = x;
    double cy = y;
    int i;

    int color;

    zx = 0;
    zy = 0;

    for (i = 0; i < ITERATIONS; i++) {
        zx2 = zx*zx - zy*zy;
        zy2 = 2*zx*zy;

        zx = zx2 + cx;
        zy = zy2 + cy;

        if (zx*zx + zy*zy > 4) {
            color = (i * 255) / ITERATIONS;
            r = color;
            g = color;
            b = color;
            printf("\x1b[38;2;%d;%d;%dm@", (int)r, (int)g, (int)b);
            return;
        }
    }
    printf(" ");
}

int main() {
    int i,j;
    double x,y;

    for (i = 0; i < HEIGHT; i++) {
        y = 1.5 - i * 3.0 / HEIGHT;
        for (j = 0; j < WIDTH; j++) {
            x = -2.5 + j * 3.4 / WIDTH;
            draw(x,y);
        }
        printf("\x1b[0m\n");
    }

    return 0;
}