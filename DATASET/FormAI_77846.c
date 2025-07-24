//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Define image size here
#define BITS_PER_PIXEL 1 // Define bits per pixel here

void generatePixelArt(int image[SIZE][SIZE], int bitsPerPixel);
void printPixelArt(int image[SIZE][SIZE], int bitsPerPixel);

int main()
{
    int pixelArt[SIZE][SIZE];
    int bitsPerPixel = BITS_PER_PIXEL;

    srand(time(NULL)); // Seed the random number generator

    generatePixelArt(pixelArt, bitsPerPixel);
    printPixelArt(pixelArt, bitsPerPixel);

    return 0;
}

void generatePixelArt(int image[SIZE][SIZE], int bitsPerPixel)
{
    int i, j, pixelValue;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            pixelValue = rand() % (1 << bitsPerPixel); // Generate a random pixel value
            image[i][j] = pixelValue;
        }
    }
}

void printPixelArt(int image[SIZE][SIZE], int bitsPerPixel)
{
    int i, j, pixelValue;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            pixelValue = image[i][j];
            printf("%*d", bitsPerPixel, pixelValue); // Print the pixel value
        }
        printf("\n");
    }
}