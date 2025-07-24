//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 512
#define COLS 512
#define WATERMARK_SIZE 100

int main() {
    unsigned char imageMatrix[ROWS][COLS];
    unsigned char watermark[WATERMARK_SIZE];
    int i, j, k, x, y;

    // Reading the image and watermark from files
    FILE *imageFile, *watermarkFile;
    imageFile = fopen("image.raw", "rb");
    fread(imageMatrix, sizeof(unsigned char), ROWS*COLS, imageFile);
    fclose(imageFile);

    watermarkFile = fopen("watermark.txt", "r");
    fread(watermark, sizeof(unsigned char), WATERMARK_SIZE, watermarkFile);
    fclose(watermarkFile);

    // Adding the watermark to the image
    srand(time(0));
    x = rand() % ROWS;
    y = rand() % COLS;
    k = 0;

    for (i = x; i < ROWS && k < WATERMARK_SIZE; ++i) {
        for (j = y; j < COLS && k < WATERMARK_SIZE; ++j) {
            imageMatrix[i][j] |= watermark[k++];
        }
        y = 0;
    }

    // Writing the watermarked image to file
    FILE *watermarkedImageFile;
    watermarkedImageFile = fopen("watermarkedImage.raw", "wb");
    fwrite(imageMatrix, sizeof(unsigned char), ROWS*COLS, watermarkedImageFile);
    fclose(watermarkedImageFile);

    return 0;
}