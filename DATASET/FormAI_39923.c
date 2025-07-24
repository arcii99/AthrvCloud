//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: funny
/* Hilarious Digital Watermarking Example */

#include <stdio.h>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define BIT_DEPTH 24

int main()
{
    unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][BIT_DEPTH/8];
    unsigned char watermark = 0xA3; // Our digital watermark
        
    // Read image from file
    FILE *fp;
    fp = fopen("cat.jpg", "rb");
    if(fp == NULL)
    {
        printf("Error opening image file!");
        return 1;
    }
    fread(image, sizeof(image), 1, fp);
    fclose(fp);
    
    // Embed watermark into the image
    for(int i=0; i<IMAGE_HEIGHT; i++)
    {
        for(int j=0; j<IMAGE_WIDTH; j++)
        {
            for(int k=0; k<BIT_DEPTH/8; k++)
            {
                if((i+j)%3 == 0 && k == 0) // Embed watermark only in blue channel for every third pixel
                {
                    image[i][j][k] = (image[i][j][k] & 0xFE) | ((watermark >> 7) & 0x01); // Embed the first bit
                    watermark = watermark << 1; // Shift remaining bits
                }
            }
        }
    }
    
    // Save watermarked image to file
    fp = fopen("cat_watermarked.jpg", "wb");
    if(fp == NULL)
    {
        printf("Error opening output file!");
        return 1;
    }
    fwrite(image, sizeof(image), 1, fp);
    fclose(fp);
    
    printf("Watermark embedded successfully!");
    
    return 0;
}