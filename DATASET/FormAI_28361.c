//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 500
#define COLS 500

// function to embed digital watermark in the image
void embedWatermark(int image[ROWS][COLS], int watermark)
{
    int w = sqrt((double)watermark);
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            int alpha = (watermark >> (i*w+j)) & 0x1;
            if(alpha == 1)
            {
                image[i][j] |= alpha;
            }
            else
            {
                image[i][j] &= ~1;
            }
        }
    }
}

// function to extract digital watermark from the image
int extractWatermark(int image[ROWS][COLS])
{
    int watermark = 0;
    int w = sqrt((double)watermark);
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            int alpha = image[i][j] & 0x1;
            watermark |= (alpha << (i*w+j));
        }
    }
    return watermark;
}

int main()
{
    int image[ROWS][COLS]; // assume a 500 x 500 image

    // initialize the image with random values between 0 and 255
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            image[i][j] = rand() % 256;
        }
    }

    int watermark = 0b1101100110010101; // assume a 4x4 digital watermark

    embedWatermark(image, watermark); // embed the watermark in the image

    int extractedWatermark = extractWatermark(image); // extract the watermark from the image

    // check if the extracted watermark matches the original watermark
    if (watermark == extractedWatermark)
    {
        printf("Watermark embedded and extracted successfully!");
    }
    else
    {
        printf("Error: extracted watermark does not match original watermark.");
    }

    return 0;
}