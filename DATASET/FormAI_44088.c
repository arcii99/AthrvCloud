//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function for generating random colors
void generateColor(char *color)
{
    char hex[] = "0123456789ABCDEF";
    for(int i=0; i<6; i++)
    {
        color[i] = hex[rand()%16];
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Declare the grid
    char grid[ROWS][COLS];

    // Generate a random grid of colors
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            char color[7];
            generateColor(color);
            grid[i][j] = color[0];
        }
    }

    // Print the grid
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("\033[48;2;%d;%d;%dm  ", grid[i][j], grid[i][j+1], grid[i][j+2]);
            j += 2;
        }
      printf("\033[0m\n");
    }

    return 0;
}