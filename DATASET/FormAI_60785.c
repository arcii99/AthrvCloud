//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 100

int main()
{
    int x, y, i, iteration;
    double zx, zy, cX, cY, tmp;
    double pixelSize = 4.0 / WIDTH;
    double minReal = -2.0, maxReal = 2.0;
    double minImag = -1.2, maxImag = minImag + (maxReal - minReal) * HEIGHT / WIDTH;
    char color[WIDTH][HEIGHT];
    srand(time(0));
    
    // Generate random color palette
    for (i = 0; i < 256; i++) {
        color[i][0] = rand() % 255;
        color[i][1] = rand() % 255;
        color[i][2] = rand() % 255;
    }
    
    // Generate fractal
    for (y = 0; y < HEIGHT; y++) {
        cY = minImag + y * pixelSize;
        for (x = 0; x < WIDTH; x++) {
            cX = minReal + x * pixelSize;
            zx = zy = 0;
            iteration = 0;
            while ((zx * zx + zy * zy) < 4 && iteration < MAX_ITERATIONS) {
                tmp = zx * zx - zy * zy + cX;
                zy = 2 * zx * zy + cY;
                zx = tmp;
                iteration++;
            }
            color[iteration % 256][0] ? printf("%c", color[iteration % 256][0]) : printf(" ");
            color[iteration % 256][1] ? printf("%c", color[iteration % 256][1]) : printf(" ");
            color[iteration % 256][2] ? printf("%c", color[iteration % 256][2]) : printf(" ");
        }
        printf("\n");
    }

    return 0;
}