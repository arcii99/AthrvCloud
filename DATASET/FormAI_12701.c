//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10 // width of the pixel art in pixels
#define HEIGHT 10 // height of the pixel art in pixels

int main()
{
    int pixels[WIDTH][HEIGHT]; // initialize empty array for pixel art
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Loop through array and fill with random values
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            pixels[i][j] = rand() % 2; // set pixel to either 0 or 1 randomly
        }
    }

    // Loop through array and print it out in a block-style pixel art
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            if(pixels[i][j] == 0)
            {
                printf("██"); // two Unicode characters to represent a filled pixel
            }
            else
            {
                printf("  "); // two spaces to represent an empty pixel
            }
        }
        printf("\n"); // move to new line for next row
    }

    return 0; // exit program
}