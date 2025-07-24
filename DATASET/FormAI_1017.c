//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>

// Function to flip the image vertically
void flipImage(int image[], int width, int height)
{
    int temp;
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height/2; j++)
        {
            temp = image[j*width + i];
            image[j*width + i] = image[(height-j-1)*width + i];
            image[(height-j-1)*width + i] = temp;
        }
    }
}

// Function to change the brightness of the image
void adjustBrightness(int image[], int width, int height, int adjustment)
{
    for(int i=0; i<width*height; i++)
    {
        int pixel = image[i];
        pixel += adjustment;
        if(pixel < 0) pixel = 0;
        if(pixel > 255) pixel = 255;
        image[i] = pixel;
    }
}

// Function to change the contrast of the image
void adjustContrast(int image[], int width, int height, float adjustment)
{
    adjustment = (100+adjustment)/100;
    adjustment *= adjustment;
    float average = 0;
    for(int i=0; i<width*height; i++)
    {
        average += image[i];
    }
    average /= width*height;
    for(int i=0; i<width*height; i++)
    {
        int pixel = image[i];
        pixel -= average;
        pixel *= adjustment;
        pixel += average;
        if(pixel < 0) pixel = 0;
        if(pixel > 255) pixel = 255;
        image[i] = pixel;
    }
}

int main()
{
    int image[5][5] = {{ 10, 20, 30, 40, 50 },
                       { 60, 70, 80, 90, 100 },
                       { 110, 120, 130, 140, 150 },
                       { 160, 170, 180, 190, 200 },
                       { 210, 220, 230, 240, 250 }};
                       
    // Flip the image vertically
    flipImage((int*)image, 5, 5);
    
    // Print the flipped image
    printf("Flipped image:\n");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    // Adjust the brightness of the image by -50
    adjustBrightness((int*)image, 5, 5, -50);
    
    // Print the adjusted image
    printf("Adjusted image (brightness -50):\n");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    // Adjust the contrast of the image by 50%
    adjustContrast((int*)image, 5, 5, 50);
    
    // Print the adjusted image
    printf("Adjusted image (contrast 50%%):\n");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}