//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

/* Helper function to print the image */
void printImage(unsigned char image[WIDTH][HEIGHT]) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

/* Helper function to add a watermark image */
void addWatermark(unsigned char image[WIDTH][HEIGHT], unsigned char watermark[WIDTH][HEIGHT]) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (watermark[i][j] == 255) {   // If the watermark has a pixel, then add it to the image
                image[i][j] += 5;   // Add 5 to the pixel value of the image
            }
        }
    }
}

/* Main function */
int main() {
    unsigned char image[WIDTH][HEIGHT];
    unsigned char watermark[WIDTH][HEIGHT];
    int i, j;

    /* Initialize the image with random pixel values */
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image[i][j] = rand() % 256;    // Generate a random pixel value
        }
    }

    /* Initialize the watermark with random 0's and 1's */
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 2 == 0) {  // 50% chance of a pixel being 0 or 1
                watermark[i][j] = 0;
            } else {
                watermark[i][j] = 255;
            }
        }
    }

    printf("Original image:\n");
    printImage(image);  // Print the original image
    printf("\n");

    printf("Watermark image:\n");
    printImage(watermark);  // Print the watermark image
    printf("\n");

    addWatermark(image, watermark);  // Add the watermark to the image

    printf("Watermarked image:\n");
    printImage(image);  // Print the watermarked image
    printf("\n");

    return 0;
}