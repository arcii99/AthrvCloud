//FormAI DATASET v1.0 Category: Image compression ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* This program performs a simple image compression using run length encoding (RLE) algorithm*/

// Define the maximum size of the input image
#define WIDTH 16
#define HEIGHT 16
#define MAX_PIXEL_VALUE 255

// A utility function to print the image in ASCII format
void print_image(unsigned char img[][WIDTH]) {
    printf("Image:\n");
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

// A function to compress the input image using RLE algorithm
void compress_image(unsigned char img[][WIDTH]) {
    // Initialize the compressed image array with maximum possible size
    unsigned char comp[MAX_PIXEL_VALUE * WIDTH * HEIGHT][2];

    int comp_idx = 0; // Index for the compressed image array

    for (int i=0; i<HEIGHT; i++) {
        int count = 1;
        for (int j=1; j<WIDTH; j++) {
            // If the current pixel is the same as the previous pixel, increment the count
            if (img[i][j] == img[i][j-1] && count < MAX_PIXEL_VALUE) {
                count++;
            }
            // Otherwise, add the (count, pixel) pair to the compressed image array
            else {
                comp[comp_idx][0] = count;
                comp[comp_idx][1] = img[i][j-1];
                comp_idx++;
                count = 1;
            }
        }
        // Add the last (count, pixel) pair to the compressed image array
        comp[comp_idx][0] = count;
        comp[comp_idx][1] = img[i][WIDTH-1];
        comp_idx++;
    }

    // Print the compressed image in ASCII format
    printf("Compressed image:\n");
    for (int i=0; i<comp_idx; i++) {
        printf("(%d, %d) ", comp[i][0], comp[i][1]);
    }
    printf("\n");
}

int main() {
    // Create a random input image
    unsigned char img[HEIGHT][WIDTH];
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            img[i][j] = rand() % MAX_PIXEL_VALUE;
        }
    }

    // Print the input image
    print_image(img);

    // Compress the input image using RLE algorithm and print the compressed image
    compress_image(img);

    return 0;
}