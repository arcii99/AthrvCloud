//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

// Function to embed watermark in the image
void embed_watermark(int *image, int *watermark, int width, int height) {
    // Embed watermark in image by swapping LSBs of the image pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_index = (i * width) + j;
            int pixel = *(image + pixel_index);
            int watermark_value = *(watermark + pixel_index % 8);
            *(image + pixel_index) = ((pixel & 254) | watermark_value);
        }
    }
}

// Function to extract watermark from the image
void extract_watermark(int *image, int *watermark, int width, int height) {
    // Extract watermark from image by fetching LSBs of the image pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_index = (i * width) + j;
            int pixel = *(image + pixel_index);
            *(watermark + pixel_index % 8) = pixel & 1;
        }
    }
}

int main() {
    int image[20][20], watermark[8];
    int width = 20, height = 20;

    // Initialize image and watermark
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Generate random pixel values for image
            image[i][j] = rand() % 256;
        }
    }
    for (int i = 0; i < 8; i++) {
        // Generate random bits for watermark
        watermark[i] = rand() % 2;
    }

    // Embed watermark in image
    embed_watermark(&image[0][0], &watermark[0], width, height);

    // Extract watermark from image
    int extracted_watermark[8];
    extract_watermark(&image[0][0], &extracted_watermark[0], width, height);

    // Print original watermark and extracted watermark
    printf("Original Watermark: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", watermark[i]);
    }
    printf("\nExtracted Watermark: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", extracted_watermark[i]);
    }
    
    return 0;
}