//FormAI DATASET v1.0 Category: Image compression ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 8 // Block size for image compression

// Function to compress a given image array
void imageCompression(int **image, int width, int height) {
    int compressedWidth = width / BLOCK_SIZE;
    int compressedHeight = height / BLOCK_SIZE;
    int **compressedImage = malloc(compressedWidth * sizeof(int *));
    
    for (int i = 0; i < compressedWidth; i++)
        compressedImage[i] = malloc(compressedHeight * sizeof(int));
    
    for (int i = 0; i < compressedWidth; i++) {
        for (int j = 0; j < compressedHeight; j++) {
            int sum = 0;
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    sum += image[i * BLOCK_SIZE + k][j * BLOCK_SIZE + l];
                }
            }
            compressedImage[i][j] = sum / (BLOCK_SIZE * BLOCK_SIZE);
        }
    }
    
    printf("Image compression successful!\n");
}

int main() {
    int width = 800;
    int height = 600;
    int **image = malloc(width * sizeof(int *));
    
    for (int i = 0; i < width; i++)
        image[i] = malloc(height * sizeof(int));
    
    // Initialize image with random grayscale values
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    imageCompression(image, width, height);
    
    return 0;
}