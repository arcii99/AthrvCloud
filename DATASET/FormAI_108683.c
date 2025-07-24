//FormAI DATASET v1.0 Category: Image compression ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXEL 255
#define MIN_PIXEL 0

int main()
{
    int image[10][10] = { {100, 200, 150, 175, 225, 180, 190, 210, 190, 240},
                          {225, 200, 175, 190, 210, 240, 150, 180, 190, 210},
                          {150, 190, 200, 205, 215, 225, 200, 190, 180, 170},
                          {200, 210, 190, 175, 195, 185, 175, 160, 172, 190},
                          {180, 160, 190, 210, 205, 220, 200, 180, 170, 155},
                          {190, 180, 175, 200, 190, 175, 155, 160, 170, 190},
                          {170, 190, 205, 195, 210, 200, 198, 187, 176, 170},
                          {175, 165, 160, 170, 180, 190, 200, 210, 220, 230},
                          {160, 170, 180, 190, 200, 210, 220, 230, 240, 250},
                          {120, 125, 130, 135, 140, 145, 150, 155, 160, 165} 
                        };
    int compressed_image[10][10];
    int i, j;
    float mean, std_dev, range;

    // Calculating Mean and Standard Deviation for Each Row
    for (i = 0; i < 10; i++)
    {
        mean = 0;
        std_dev = 0;
        for (j = 0; j < 10; j++)
        {
            mean += image[i][j];
        }
        mean /= 10;

        for (j = 0; j < 10; j++)
        {
            std_dev += (image[i][j] - mean) * (image[i][j] - mean);
        }

        std_dev = sqrt(std_dev / 10);

        // Applying Compressed Image Transformation For Each Row
        for (j = 0; j < 10; j++)
        {
            range = (MAX_PIXEL - MIN_PIXEL) / std_dev;
            compressed_image[i][j] = (image[i][j] - mean) / range;
        }
    }

    printf("Original Image:\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }

    printf("\nCompressed Image:\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d\t", compressed_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}