//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4
#define MARK '3'

int main()
{
    int i, j;
    int image[ROWS][COLS] = { {1,2,3,4},
                              {5,6,7,8},
                              {9,10,11,12},
                              {13,14,15,16} };

    // Print the original image
    printf("Original Image:\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Add the watermark
    for(i = 0; i < ROWS; i++)
    {
        image[i][i] = MARK;
    }

    // Print the watermarked image
    printf("\nWatermarked Image:\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}