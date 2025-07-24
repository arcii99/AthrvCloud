//FormAI DATASET v1.0 Category: Fractal Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 50
#define MAX_ITERATIONS 1000

char ch[WIDTH * HEIGHT];  // character buffer for storing the fractal

int main()
{
    int x, y, i;
    double zx, zy, cx, cy, tmp;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            zx = zy = 0;
            cx = (x - WIDTH/2.0) * 4.0 / WIDTH;  // map pixel coordinates to complex plane
            cy = (y - HEIGHT/2.0) * 4.0 / WIDTH;
            i = 0;
            while (zx*zx + zy*zy < 4.0 && i < MAX_ITERATIONS) {
                tmp = zx*zx - zy*zy + cx;  // complex multiplication and addition
                zy = 2*zx*zy + cy;
                zx = tmp;
                i++;
            }
            ch[y * WIDTH + x] = (i == MAX_ITERATIONS) ? '#' : '.';  // store pixel value in buffer
        }
    }

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(ch[y * WIDTH + x]);  // print the fractal
        }
        putchar('\n');
    }

    return 0;
}