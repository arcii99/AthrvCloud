//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h> // Required for rand() function

int main()
{
    int width, height;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    
    // Create 2D array to hold pixel data
    int pixels[height][width];
    
    // Fill in array with random pixel values
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int randomValue = rand() % 2; // Only generate 0 or 1
            pixels[i][j] = randomValue;
        }
    }
    
    // Print out pixel art
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(pixels[i][j] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n"); // Move to next line after each row
    }
    
    return 0;
}