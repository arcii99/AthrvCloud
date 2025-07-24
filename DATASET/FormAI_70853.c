//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void printPixelArt(char pixels[HEIGHT][WIDTH])
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}

void generatePixelArt(char pixels[HEIGHT][WIDTH])
{
    srand(time(NULL));
    char colors[] = {'R', 'G', 'B', 'Y'};
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            int colorIndex = rand() % 4;
            pixels[i][j] = colors[colorIndex];
        }
    }
}

int main()
{
    char pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);
    return 0;
}