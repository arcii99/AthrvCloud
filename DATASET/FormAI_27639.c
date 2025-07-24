//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pixelArt(int width, int height, int colors[], int numColors)
{
    srand(time(NULL)); // Initialize random number generator
    
    printf("P3\n%d %d\n255\n", width, height); // P3 is magic number for PPM format
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int colorIndex = rand() % numColors; // Pick a random color index from the available colors
            int red = colors[colorIndex] >> 16; // Extract red component (first 8 bits)
            int green = (colors[colorIndex] >> 8) & 0xFF; // Extract green component (second 8 bits)
            int blue = colors[colorIndex] & 0xFF; // Extract blue component (last 8 bits)
            printf("%d %d %d ", red, green, blue); // Print the RGB values of the pixel
        }
        printf("\n"); // Move to next row
    }
}

int main()
{
    int colors[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF}; // Available colors in RGB format
    int numColors = sizeof(colors) / sizeof(int); // Calculate number of available colors
    
    pixelArt(50, 50, colors, numColors); // Generate 50x50 pixel art using the available colors
    
    return 0;
}