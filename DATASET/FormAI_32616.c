//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define WIDTH 100 // Width of the canvas
#define HEIGHT 50 // Height of the canvas

void iterate(float cx, float cy, float *px, float *py)
{
    float x = *px;
    float y = *py;

    *px = x * x - y * y + cx;
    *py = 2 * x * y + cy;
}

int main()
{
    float x, y, start_x, start_y;
    float cx, cy, dx, dy;

    // Initialize the canvas arrays
    char canvas[WIDTH][HEIGHT];
    for(int i = 0; i < WIDTH; i++)
        for(int j = 0; j < HEIGHT; j++)
            canvas[i][j] = ' ';

    // Loop over every pixel on the canvas
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            cx = ((float)i - WIDTH/2) / (WIDTH/4); // Rescale x to fit the complex plane
            cy = ((float)j - HEIGHT/2) / (HEIGHT/4); // Rescale y to fit the complex plane

            x = 0;
            y = 0;

            for(int k = 0; k < MAX_ITERATIONS; k++)
            {
                iterate(cx, cy, &x, &y);

                // If the point has escaped to infinity, color it
                if(sqrt(x*x + y*y) > 2)
                {
                    // Map the number of iterations to a color
                    int color = (k * 7) % 16;
                    canvas[i][j] = '0' + color;
                    break;
                }
            }
        }
    }

    // Print the canvas
    for(int j = 0; j < HEIGHT; j++)
    {
        for(int i = 0; i < WIDTH; i++)
        {
            printf("\033[0;3%dm%c\033[0m", canvas[i][j], canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}