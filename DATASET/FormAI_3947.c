//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

void clearScreen()
{
    system("cls");
}

void printPixel(char pixel)
{
    printf("%c", pixel);
}

void generatePixelArt(char pixelArt[HEIGHT][WIDTH], char pixelOptions[], int numOptions)
{
    srand(time(NULL));
    
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            pixelArt[i][j] = pixelOptions[rand() % numOptions];
        }
    }
}

void printPixelArt(char pixelArt[HEIGHT][WIDTH])
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printPixel(pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char pixelArt[HEIGHT][WIDTH];
    char pixelOptions[] = {'*', '.', '#', '@', '+'};
    int numOptions = sizeof(pixelOptions) / sizeof(char);
    
    generatePixelArt(pixelArt, pixelOptions, numOptions);
    printPixelArt(pixelArt);
    
    return 0;
}