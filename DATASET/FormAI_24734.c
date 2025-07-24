//FormAI DATASET v1.0 Category: Image compression ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define constants for image size
#define ROWS 20
#define COLS 20

// Define function to compress an image
int compressImage(unsigned char image[ROWS][COLS], unsigned char compressed[ROWS/2][COLS/2]) {
    for (int i = 0; i < ROWS/2; i++) {
        for (int j = 0; j < COLS/2; j++) {
            // Average the values of each 2x2 square in the original image and store in compressed image
            compressed[i][j] = (image[2*i][2*j] + image[2*i+1][2*j] + image[2*i][2*j+1] + image[2*i+1][2*j+1])/4;
        }
    }
    return 0;
}

int main() {
    // Create test image
    unsigned char image[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            image[i][j] = rand() % 256; // Random values between 0 and 255
        }
    }

    // Display original image
    printf("Original Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Create compressed image
    unsigned char compressed[ROWS/2][COLS/2];
    compressImage(image, compressed);

    // Display compressed image
    printf("\nCompressed Image:\n");
    for (int i = 0; i < ROWS/2; i++) {
        for (int j = 0; j < COLS/2; j++) {
            printf("%d ", compressed[i][j]);
        }
        printf("\n");
    }

    return 0;
}