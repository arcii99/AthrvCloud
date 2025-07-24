//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8
#define WATERMARK_LENGTH 20

// A function to print binary representation of an integer
void printBinary(int num, int bits) {
    if(bits <= 0)
        return;
    int mask = 1 << (bits-1);
    while(mask > 0) {
        if(num & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
}

int main() {
    // Read input image as 2D matrix of grayscale intensity values
    int image[8][8] = {
        {231, 32, 233, 161, 24, 71, 140, 245},
        {247, 40, 248, 245, 124, 204, 36, 107},
        {234, 202, 245, 167, 9, 217, 239, 173},
        {193, 190, 100, 167, 43, 180, 8, 70},
        {11, 24, 210, 177, 81, 243, 8, 112},
        {97, 195, 203, 57, 41, 157, 48, 15},
        {103, 187, 183, 28, 254, 115, 50, 49},
        {127, 206, 78, 63, 61, 43, 209, 25}
    };

    // Read and prepare watermark string for embedding in LSB of each pixel
    char watermark[] = "Hello, World! 123";
    int len = strlen(watermark);

    // Create 1D array of bits from watermark string
    int watermarkBits[WATERMARK_LENGTH * BITS_PER_BYTE];
    for(int i = 0; i < len; i++) {
        char c = watermark[i];
        int k = i * BITS_PER_BYTE;
        for(int j = 0; j < BITS_PER_BYTE; j++) {
            watermarkBits[k + (BITS_PER_BYTE-1-j)] = (c >> j) & 1;
        }
    }

    // Embed watermark in LSB of each pixel value of the image
    int k = 0; // bit index in watermarkBits array
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            int pixelValue = image[i][j];
            // clear last bit (LSB) of pixel value
            pixelValue &= (~1);
            // set LSB to next bit of watermark
            pixelValue |= watermarkBits[k++];
            // put modified pixel value back in image matrix
            image[i][j] = pixelValue;
        }
    }

    // Extract watermark from LSB of each pixel value of the image
    char extractedWatermark[WATERMARK_LENGTH+1];
    k = 0; // bit index in extracted watermark bit array
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            int pixelValue = image[i][j];
            // extract LSB (last bit) of the pixel value
            int bit = pixelValue & 1;
            // store extracted bit in extracted watermark bit array
            extractedWatermark[k / BITS_PER_BYTE] |= bit << (k % BITS_PER_BYTE);
            k++;
        }
    }

    // Print original watermark, and extracted watermark for comparison
    printf("Original watermark: %s\n", watermark);
    printf("Extracted watermark: %s\n", extractedWatermark);

    return 0;
}