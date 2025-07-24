//FormAI DATASET v1.0 Category: Fractal Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int width = 1000;
    int height = 1000;
    float* pixels = (float*)malloc(width * height * sizeof(float));
    
    float cx = -0.7;
    float cy = 0.0;
    float scale = 2.5;
    
    float x0, y0, x, y, xtemp;
    int i, j, k, iter_max = 50;
    float pixel_width = scale / (float)width;
    float pixel_height = scale / (float)height;

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            x0 = (i * pixel_width) - (scale / 2.0);
            y0 = (j * pixel_height) - (scale / 2.0);
            x = 0.0;
            y = 0.0;
            k = 0;
            while (((x * x) + (y * y) < (4.0)) && (k < iter_max)) {
                xtemp = (x * x) - (y * y) + cx;
                y = (2.0 * x * y) + cy;
                x = xtemp;
                k++;
            }
            float color = ((float)k / (float)iter_max);
            pixels[(j * width) + i] = color;
        }
    }

    printf("P2\n%d %d\n255\n", width, height);
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            int val = (int)(pixels[(j * width) + i] * 255);
            printf("%d ", val);
        }
    }

    free(pixels);
    return 0;
}