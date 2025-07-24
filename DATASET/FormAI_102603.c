//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

int img[HEIGHT][WIDTH]; // The image array

// Flip the image horizontally
void flipHorizontally()
{
    int temp;
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH/2; j++)
        {
            temp = img[i][j];
            img[i][j] = img[i][WIDTH - j - 1];
            img[i][WIDTH - j - 1] = temp;
        }
    }
}

// Adjust the brightness of the image
void adjustBrightness(int level)
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            img[i][j] += level;
            if(img[i][j] > 255) img[i][j] = 255;
            if(img[i][j] < 0) img[i][j] = 0;
        }
    }
}

// Adjust the contrast of the image
void adjustContrast(int level)
{
    float factor = (259 * (level + 255)) / (255 * (259 - level));
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            img[i][j] = factor * (img[i][j] - 128) + 128;
            if(img[i][j] > 255) img[i][j] = 255;
            if(img[i][j] < 0) img[i][j] = 0;
        }
    }
}

int main()
{
    // Generate a test image
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            img[i][j] = i * 2; // set the pixel value to an arbitrary value
        }
    }
    
    // Flip the image horizontally
    flipHorizontally();
    
    // Adjust the brightness of the image
    adjustBrightness(30);
    
    // Adjust the contrast of the image
    adjustContrast(50);
    
    // Print the final image
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}