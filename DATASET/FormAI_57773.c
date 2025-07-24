//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 10 //Size of each pixel in the generated image
#define WIDTH 50 //Width of generated image in pixels
#define HEIGHT 50 //Height of generated image in pixels

int main()
{
    int pixels[WIDTH][HEIGHT]; //2D array to hold pixel values
    int i, j, k; //Loop variables

    srand(time(NULL)); //Seed random number generator

    //Generate random pixel values
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            pixels[i][j] = (rand() % 2); //Randomly set pixel value to 0 or 1
        }
    }

    //Print pixel art
    for(i = 0; i < WIDTH; i++)
    {
        for(k = 0; k < PIXEL_SIZE; k++) //Print each row of pixels PIXEL_SIZE times to increase size of image
        {
            for(j = 0; j < HEIGHT; j++)
            {
                if(pixels[i][j] == 0) //Print black pixel
                {
                    for(int l = 0; l < PIXEL_SIZE; l++)
                    {
                        printf(" ");
                    }
                }
                else //Print white pixel
                {
                    for(int l = 0; l < PIXEL_SIZE; l++)
                    {
                        printf("#");
                    }
                }
            }
            printf("\n"); //Move to next row of pixels
        }
    }

    return 0;
}