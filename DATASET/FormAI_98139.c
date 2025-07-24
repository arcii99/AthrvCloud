//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This program generates a 20x20 grid of randomly colored pixels in the style of 8-bit graphics.

int main()
{
    srand(time(NULL)); //Seed the random number generator.

    int grid[20][20]; //Create the 20x20 grid.

    //Populate the grid with random values from 0 to 3 (representing different colors).
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grid[i][j] = rand() % 4;
        }
    }

    //Print the grid using ASCII art characters to represent the different colors.
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            switch (grid[i][j])
            {
            case 0:
                printf("██");
                break;
            case 1:
                printf("░░");
                break;
            case 2:
                printf("▒▒");
                break;
            case 3:
                printf("▓▓");
                break;
            }
        }
        printf("\n");
    }

    return 0;
}