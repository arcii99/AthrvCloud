//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 16
#define HEIGHT 16

int main()
{
    // set seed for random numbers
    srand(time(NULL));
    
    // create an array to store pixel colors
    int pixelArray[WIDTH][HEIGHT];
    
    // fill array with random colors
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            pixelArray[i][j] = rand() % 256; // generates a number between 0 and 255
        }
    }
    
    // print out the pixel array in pixel art format
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            if(pixelArray[i][j] <= 50) // dark pixel
            {
                printf("██");
            }
            else if(pixelArray[i][j] <= 100) // medium pixel
            {
                printf("▓▓");
            }
            else if(pixelArray[i][j] <= 150) // light pixel
            {
                printf("░░");
            }
            else // white pixel
            {
                printf("  ");
            }
        }
        printf("\n"); // move to next row
    }
    
    return 0;
}