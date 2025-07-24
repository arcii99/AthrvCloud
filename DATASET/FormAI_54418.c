//FormAI DATASET v1.0 Category: Image compression ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IMG_WIDTH 500
#define IMG_HEIGHT 500

// Function to compress image and return the compressed data
unsigned char* compress_image(unsigned char* img_data, unsigned int img_size, unsigned int* compressed_size) {
    // Allocate memory for compressed data
    unsigned char* compressed_data = (unsigned char*) malloc(img_size/2 * sizeof(unsigned char));
    *compressed_size = 0;

    // Loop through image data, compressing it into the compressed_data array
    unsigned char current_byte = 0;
    int num_bits_written = 0;
    for (int i=0; i<img_size; i++) {
        if (img_data[i] == current_byte && num_bits_written < 7) {
            num_bits_written++;
        } else {
            compressed_data[*compressed_size] = current_byte;
            *compressed_size += 1;
            current_byte = img_data[i];
            num_bits_written = 1;
        }

        if (*compressed_size >= img_size/2) {
            // Compressed data array is full, return what we have
            return compressed_data;
        }
    }

    // Add final byte to compressed data array
    compressed_data[*compressed_size] = current_byte;
    *compressed_size += 1;

    return compressed_data;
}

int main(void) {
    // Generate random image data
    unsigned char img_data[IMG_WIDTH * IMG_HEIGHT];
    srand(time(NULL));
    for (int i=0; i<IMG_WIDTH * IMG_HEIGHT; i++) {
        img_data[i] = rand() % 256;
    }

    // Compress image and get compressed data
    unsigned int compressed_size = 0;
    unsigned char* compressed_data = compress_image(img_data, IMG_WIDTH * IMG_HEIGHT, &compressed_size);

    // Print out original and compressed image data sizes
    printf("Original Image Size: %d Bytes\n", IMG_WIDTH * IMG_HEIGHT);
    printf("Compressed Image Size: %d Bytes\n", compressed_size);

    // Free memory
    free(compressed_data);

    return 0;
}