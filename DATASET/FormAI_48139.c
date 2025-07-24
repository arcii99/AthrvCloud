//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the canvas
#define WIDTH 20
#define HEIGHT 10

// Define the number of pixel colors
#define COLORS 4

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the canvas with random pixel colors
    int canvas[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            canvas[i][j] = rand() % COLORS;
        }
    }

    // Print the canvas as pixel art
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            switch (canvas[j][i])
            {
                case 0:
                    printf("\u25A1 "); // White square
                    break;
                case 1:
                    printf("\u25A0 "); // Black square
                    break;
                case 2:
                    printf("\u25CB "); // White circle
                    break;
                case 3:
                    printf("\u25CF "); // Black circle
                    break;
            }
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}