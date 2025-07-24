//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random pixel character
char generatePixel()
{
    char pixelOptions[] = {' ', '-', '|', '_', '+', '*', '/', '\\', 'O', 'o', '.', ':'};
    int pixelIndex = rand() % 12;
    return pixelOptions[pixelIndex];
}

// function to generate the pixel art image
void generatePixelArt(int width, int height)
{
    // initialize random seed
    srand(time(NULL));
    
    // loop through each row
    for(int i = 0; i < height; i++)
    {
        // loop through each column
        for(int j = 0; j < width; j++)
        {
            // generate and print the pixel character
            char pixel = generatePixel();
            printf("%c", pixel);
        }
        
        // print a newline character to move to the next row
        printf("\n");
    }
}

// main function
int main()
{
    // set width and height of the pixel art image
    int width = 50;
    int height = 20;
    
    // generate and print the pixel art image
    generatePixelArt(width, height);
    
    return 0;
}