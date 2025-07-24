//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 16
#define HEIGHT 16

char pixelArt[HEIGHT][WIDTH];
char colorOptions[] = {'#', '*', '@', '$', '%', '&', '?'};

void generatePixelArt()
{
    int i, j;
    for(i=0; i < HEIGHT; i++)
    {
        for(j=0; j < WIDTH; j++)
        {
            pixelArt[i][j] = colorOptions[rand() % 7];
        }
    }
}

void printPixelArt()
{
    int i,j;
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));
    generatePixelArt();
    printPixelArt();
    return 0;
}