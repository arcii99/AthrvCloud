//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 256
#define WIDTH 256

int main() {
    // Read image pixel values into a 2D array
    unsigned char img[HEIGHT][WIDTH];
    FILE *inputFile = fopen("image.raw", "rb");
    fread(img, sizeof(unsigned char), HEIGHT*WIDTH, inputFile);
    fclose(inputFile);

    // Initialize variables for compression
    int count = 0;
    unsigned char value = 0;
    unsigned char compressed[HEIGHT*WIDTH/8];
    int compIndex = 0;

    // Loop through each pixel of the image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Check if the pixel value is greater than or equal to 128
            if (img[i][j] >= 128) {
                // Set the corresponding bit to 1 in the compressed array
                value += pow(2, 7 - (count % 8));
            }
            count++;

            // Check if 8 bits have been read
            if (count % 8 == 0) {
                compressed[compIndex++] = value;
                value = 0;
            }
        }
    }

    // Write the compressed array to a file
    FILE *outputFile = fopen("compressed.bin", "wb");
    fwrite(compressed, sizeof(unsigned char), HEIGHT*WIDTH/8, outputFile);
    fclose(outputFile);

    // Sample decompression code
    unsigned char decompressed[HEIGHT*WIDTH];
    inputFile = fopen("compressed.bin", "rb");
    fread(decompressed, sizeof(unsigned char), HEIGHT*WIDTH/8, inputFile);
    fclose(inputFile);

    compIndex = 0;
    count = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            unsigned char bit = (decompressed[compIndex] & (1 << (7 - (count % 8)))) >> (7 - (count % 8));
            img[i][j] = bit * 255;
            count++;

            if (count % 8 == 0) {
                compIndex++;
            }
        }
    }

    // Write the decompressed image to a file
    outputFile = fopen("decompressed.raw", "wb");
    fwrite(img, sizeof(unsigned char), HEIGHT*WIDTH, outputFile);
    fclose(outputFile);

    return 0;
}