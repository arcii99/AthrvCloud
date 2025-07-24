//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

void printPixelArt(int pixelArt[ROWS][COLUMNS])
{
    printf(" ");
    for(int i = 0; i < COLUMNS; i++)
    {
        printf("--");
    }
    printf("\n");

    for(int i = 0; i < ROWS; i++)
    {
        printf("|");
        for(int j = 0; j < COLUMNS; j++)
        {
            if(pixelArt[i][j] == 0)
            {
                printf("  ");
            }
            else if(pixelArt[i][j] == 1)
            {
                printf("* ");
            }
        }
        printf("|\n");
    }

    printf(" ");
    for(int i = 0; i < COLUMNS; i++)
    {
        printf("--");
    }
    printf("\n");
}

int main()
{
    int pixelArt[ROWS][COLUMNS];

    srand(time(NULL));

    // Fill pixel art matrix with random 1's and 0's
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            pixelArt[i][j] = rand() % 2;
        }
    }

    printPixelArt(pixelArt);

    return 0;
}