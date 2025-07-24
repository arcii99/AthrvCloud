//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

// Embed watermark in the given image using LSB technique
void embed_watermark(unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], unsigned char watermark[])
{
    int i, j, k, n, m;
    n = strlen(watermark);
    m = 0;

    for(i=0; i<MAX_IMAGE_SIZE; i++)
    {
        for(j=0; j<MAX_IMAGE_SIZE; j++)
        {
            for(k=0; k<3; k++)
            {
                if(m < n)
                {
                    // Embed the bit of watermark into LSB of image pixel 
                    image[i][j] = (image[i][j] & ~1) | ((watermark[m] >> k) & 1);
                    m++;
                }
                else
                    return;
            }
        }
    }
}

// Extract watermark from the given image using LSB technique
void extract_watermark(unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], unsigned char watermark[])
{
    int i, j, k, n, m;
    n = strlen(watermark);
    m = 0;

    for(i=0; i<MAX_IMAGE_SIZE; i++)
    {
        for(j=0; j<MAX_IMAGE_SIZE; j++)
        {
            for(k=0; k<3; k++)
            {
                if(m < n)
                {
                    // Extract LSB of image pixel to get watermark bit
                    watermark[m] |= (image[i][j] & 1) << k;
                    m++;
                }
                else
                    return;
            }
        }
    }
}

int main()
{
    unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    unsigned char watermark[] = "DIGITAL_WATERMARKING";
    unsigned char extracted_watermark[strlen(watermark)];
    memset(extracted_watermark, 0, strlen(watermark));

    // Read image from file
    FILE *fp;
    fp = fopen("image.bmp", "rb");
    fread(image, 1, sizeof(image), fp);
    fclose(fp);

    // Embed watermark in image
    embed_watermark(image, watermark);

    // Write the watermarked image to file
    fp = fopen("watermarked_image.bmp", "wb");
    fwrite(image, 1, sizeof(image), fp);
    fclose(fp);

    // Extract watermark from watermarked image
    extract_watermark(image, extracted_watermark);

    printf("Extracted Watermark: %s\n", extracted_watermark);

    return 0;
}