//FormAI DATASET v1.0 Category: Fractal Generation ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 60
#define MAX_ITERATIONS 1000
#define ESCAPE_RADIUS 4

int main(void)
{
    //Initial Setup
    srand((unsigned) time(NULL));

    int max_iterations = MAX_ITERATIONS;
    double escape_radius = ESCAPE_RADIUS;

    //Create screen buffer
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1];

    //Initialize screen buffer with spaces
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            screen[i][j] = ' ';
        }
        screen[i][SCREEN_WIDTH] = '\0';
    }

    //Mandelbrot Set Rendering
    double x_start = -2.0;
    double x_end = 1.0;
    double y_start = -1.5;
    double y_end = 1.5;

    double x_step = (x_end - x_start) / SCREEN_WIDTH;
    double y_step = (y_end - y_start) / SCREEN_HEIGHT;

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            double cr = x_start + j * x_step;
            double ci = y_start + i * y_step;

            double zr = cr;
            double zi = ci;
            int n = 0;

            for (n = 0; n < max_iterations; n++)
            {
                double zr_squared = zr * zr;
                double zi_squared = zi * zi;

                if (zr_squared + zi_squared > escape_radius * escape_radius)
                {
                    break;
                }

                zi = 2 * zr * zi + ci;
                zr = zr_squared - zi_squared + cr;
            }

            if (n == max_iterations)
            {
                screen[i][j] = '@';
            }
            else if (n > max_iterations / 2)
            {
                screen[i][j] = '#';
            }
            else if (n > max_iterations / 4)
            {
                screen[i][j] = '+';
            }
            else if (n > max_iterations / 8)
            {
                screen[i][j] = '-';
            }
            else if (n > max_iterations / 16)
            {
                screen[i][j] = '.';
            }
            else
            {
                screen[i][j] = ' ';
            }
        }
    }

    //Print the screen buffer
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        printf("%s\n", screen[i]);
    }

    return 0;
}