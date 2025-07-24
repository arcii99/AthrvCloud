//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for image dimensions
#define ROWS 256
#define COLS 256

// Define functions for image processing tasks
void flipImage(unsigned char image[][COLS]);
void changeBrightness(unsigned char image[][COLS], int value);
void changeContrast(unsigned char image[][COLS], float factor);

int main() {
    // Define and initialize array for image
    unsigned char image[ROWS][COLS];
    memset(image, 0, sizeof(image));

    // Open image file
    FILE *fp = fopen("example_image.raw", "rb");
    if(fp == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    // Read image data into array
    fread(image, 1, ROWS*COLS, fp);
    fclose(fp);

    // Call image processing functions
    flipImage(image);
    changeBrightness(image, 50);
    changeContrast(image, 1.5);

    // Write processed image data to new file
    FILE *out = fopen("output_image.raw", "wb");
    if(out == NULL) {
        printf("Error creating output file\n");
        exit(1);
    }

    fwrite(image, 1, ROWS*COLS, out);
    fclose(out);

    return 0;
}

// Flip image horizontally
void flipImage(unsigned char image[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][COLS-j-1];
            image[i][COLS-j-1] = temp;
        }
    }
}

// Adjust brightness of image by adding value to each pixel
void changeBrightness(unsigned char image[][COLS], int value) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int pixel = image[i][j];
            pixel += value;
            if(pixel > 255) pixel = 255;
            if(pixel < 0) pixel = 0;
            image[i][j] = pixel;
        }
    }
}

// Adjust contrast of image by multiplying each pixel by factor
void changeContrast(unsigned char image[][COLS], float factor) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int pixel = image[i][j];
            pixel = (int)((pixel-128)*factor+128);
            if(pixel > 255) pixel = 255;
            if(pixel < 0) pixel = 0;
            image[i][j] = pixel;
        }
    }
}