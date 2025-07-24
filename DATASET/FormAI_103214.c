//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));  // Seed the random number generator
    int width, height;   // Width and height of the pixel art
    printf("Enter width and height of the pixel art: ");
    scanf("%d %d", &width, &height);

    int pixels[width][height];
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            pixels[i][j] = rand() % 2;  // Generate a random pixel value (either 0 or 1)
        }
    }
    
    printf("\nPixel art generated:\n");
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(pixels[i][j] == 1)
            {
                printf("#");  // Print a # symbol for a pixel with value 1
            }
            else
            {
                printf(" ");  // Print a space for a pixel with value 0
            }
        }
        printf("\n");  // Move to the next row
    }

    return 0;
}