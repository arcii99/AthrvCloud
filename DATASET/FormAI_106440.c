//FormAI DATASET v1.0 Category: Fractal Generation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SCREEN_WIDTH 65
#define SCREEN_HEIGHT 35

int main()
{
    int pixels[SCREEN_HEIGHT][SCREEN_WIDTH];
    int x, y, i, j;
    double cx, cy, zx, zy, tx, ty;

    // Set pixel matrix to 0
    for(y = 0; y < SCREEN_HEIGHT; y++)
        for(x = 0; x < SCREEN_WIDTH; x++)
            pixels[y][x] = 0;

    // Random seed
    srand(time(NULL));

    // Generate random complex number
    cx = ((double)rand()/RAND_MAX)*4.0 - 2.0;
    cy = ((double)rand()/RAND_MAX)*4.0 - 2.0;

    // Set up initial values
    zx = 0.0;
    zy = 0.0;
    tx = 0.0;
    ty = 0.0;

    // Loop through iterations
    for(i = 0; i < 500; i++)
    {
        // Calculate new values
        zx = zx*zx - zy*zy + cx;
        zy = 2.0*zx*zy + cy;
        tx += zx;
        ty += zy;

        // Calculate pixel coordinates
        x = (int)(((tx/2.0)/SCREEN_WIDTH)+0.5*SCREEN_WIDTH);
        y = (int)(((ty/2.0)/SCREEN_HEIGHT)+0.5*SCREEN_HEIGHT);

        // Check if pixel is in bounds
        if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        {
            // Increase pixel value
            pixels[y][x]++;
        }
    }

    // Print out fractal
    for(y = 0; y < SCREEN_HEIGHT; y++)
    {
        for(x = 0; x < SCREEN_WIDTH; x++)
        {
            // Determine character to output
            if(pixels[y][x] > 150)
                printf(".");
            else if(pixels[y][x] > 100)
                printf("*");
            else if(pixels[y][x] > 50)
                printf(":");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}