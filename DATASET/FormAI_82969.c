//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50      // maximum width of the image
#define MAX_HEIGHT 50     // maximum height of the image
#define MAX_COLOR 255     // maximum color intensity

void generatePixelArt(int width, int height, int colors[])
{
    int pixels[height][width];
    
    // loop through the height and width of the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // randomly select a color from the given colors array
            int colorIndex = rand() % MAX_COLOR;
            pixels[i][j] = colors[colorIndex];
        }
    }
    
    // display the generated image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // set the seed for the random number generator
    srand(time(NULL));
    
    // define an array of colors
    int colors[] = {0, 64, 128, 192, 255};
    
    // generate a pixel art image with a random size between 10x10 and 50x50
    int width = rand() % (MAX_WIDTH - 10 + 1) + 10;
    int height = rand() % (MAX_HEIGHT - 10 + 1) + 10;
    generatePixelArt(width, height, colors);
    
    return 0;
}