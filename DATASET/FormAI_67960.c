//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_ITERATIONS 1000
#define WIDTH 500
#define HEIGHT 500

int main()
{
    int x, y, i;
    float real, imag, zx, zy;
    float cx_min = -2, cx_max = 2, cy_min = -2, cy_max = 2;
    float cx, cy;
    float zoom = 1.5, move_x = 0, move_y = 0;
    float pixel_width = (cx_max - cx_min) / WIDTH;
    float pixel_height = (cy_max - cy_min) / HEIGHT;

    char img[WIDTH][HEIGHT];

    printf("Please wait while your fractal is being generated...\n");

    for (y = 0; y < HEIGHT; y++) 
    {
        cy = cy_min + (y * pixel_height) + move_y;
        for (x = 0; x < WIDTH; x++) 
        {
            cx = cx_min + (x * pixel_width) + move_x;
            real = 0;
            imag = 0;
            
            for (i = 0; i < MAX_ITERATIONS; i++) 
            {
                zx = real * real - imag * imag + cx;
                zy = 2 * real * imag + cy;
                real = zx;
                imag = zy;
                
                if (sqrt(real * real + imag * imag) >= 4) 
                {
                    img[x][y] = 178;
                    break;
                }
                
                if (i == MAX_ITERATIONS - 1)
                {
                    img[x][y] = 32;
                }
            }
        }
    }

    printf("Fractal generation complete!\n\n");

    for (y = 0; y < HEIGHT; y++) 
    {
        for (x = 0; x < WIDTH; x++) 
        {
            printf("%c", img[x][y]);
        }
        printf("\n");
    }

    return 0;
}