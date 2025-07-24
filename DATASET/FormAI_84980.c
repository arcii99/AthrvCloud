//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void printPixel(char c)
{
    putchar(c);
    putchar(' ');
}

void generatePixelArt(char pixelArt[WIDTH][HEIGHT])
{
    int i, j;

    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<HEIGHT; j++)
        {
            if(i % 2 == 0 && j % 2 == 0)
                pixelArt[i][j] = 'X';
            else if(i % 3 == 0 && j % 3 == 0)
                pixelArt[i][j] = 'O';
            else
                pixelArt[i][j] = '-';
        }
    }
}

int main()
{
    char pixelArt[WIDTH][HEIGHT];

    generatePixelArt(pixelArt);

    int i, j;

    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<HEIGHT; j++)
        {
            printPixel(pixelArt[i][j]);
        }
        putchar('\n');
    }

    return 0;
}