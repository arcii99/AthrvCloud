//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void drawPixel(int x, int y, char color)
{
    printf("\033[%d;%dH%c", y + 1, x + 1, color);
}

void generatePixelArt()
{
    char pixels[WIDTH][HEIGHT];
    int i, j;
    srand(time(NULL));

    // generate pixel colors
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            pixels[i][j] = rand() % 2 == 0 ? 'O' : 'X';
        }
    }

    // draw pixel art
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            drawPixel(j, i, pixels[j][i]);
        }
    }
}

int main()
{
    generatePixelArt();

    return 0;
}