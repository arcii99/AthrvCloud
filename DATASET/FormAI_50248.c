//FormAI DATASET v1.0 Category: Image compression ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Struct to hold information for each compressed pixel
typedef struct {
    int value; // The unique value of the pixel
    int count; // The number of times the pixel appears sequentially
} CompressedPixel;

int main(void) {
    // Set up array of pixel values for example purposes
    int pixels[] = { 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 1, 1, 1 };

    int num_pixels = sizeof(pixels) / sizeof(pixels[0]);

    // Allocate memory for compressed pixel array
    CompressedPixel* compressed_pixels = malloc(num_pixels * sizeof(CompressedPixel));

    // Initialize first compressed pixel
    compressed_pixels[0].value = pixels[0];
    compressed_pixels[0].count = 1;

    int compressed_index = 0; // Index for compressed pixel array
    for (int i = 1; i < num_pixels; i++) {
        // If current pixel is the same as the previous pixel, increment count
        if (pixels[i] == pixels[i-1]) {
            compressed_pixels[compressed_index].count++;
        }
        // Otherwise, add a new compressed pixel to the array
        else {
            compressed_index++;
            compressed_pixels[compressed_index].value = pixels[i];
            compressed_pixels[compressed_index].count = 1;
        }
    }

    // Print out the compressed pixel array
    printf("Compressed pixels: ");
    for (int i = 0; i <= compressed_index; i++) {
        printf("(%d, %d) ", compressed_pixels[i].value, compressed_pixels[i].count);
    }
    printf("\n");

    free(compressed_pixels); // Free memory allocated for compressed pixel array

    return 0;
}