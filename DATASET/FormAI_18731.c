//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 30

void generatePixelArt(char pixelArt[ROWS][COLS], char palette[]);
void printPixelArt(char pixelArt[ROWS][COLS]);

int main()
{
    char pixelArt[ROWS][COLS];
    char palette[] = {'#', '@', '$', '&', '+', '-', '*', '/', '=', '%', '!'};
    srand(time(NULL));

    // generate the pixel art
    generatePixelArt(pixelArt, palette);

    // print the pixel art
    printPixelArt(pixelArt);

    return 0;
}

void generatePixelArt(char pixelArt[ROWS][COLS], char palette[])
{
    int i, j, numColors;
    char currentColor;

    // randomly assign colors to each pixel in the pixel art
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            numColors = sizeof(palette) / sizeof(char); // get the number of colors in the palette
            currentColor = palette[rand() % numColors]; // get a random color from the palette
            pixelArt[i][j] = currentColor;
        }
    }
}

void printPixelArt(char pixelArt[ROWS][COLS])
{
    int i, j;

    // print the pixel art
    printf("Here is your surreal pixel art masterpiece:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }
}