//FormAI DATASET v1.0 Category: Image compression ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define image width and height
#define WIDTH 320
#define HEIGHT 240

// Define compression factor and output image dimensions
#define COMPRESSION_FACTOR 4
#define OUTPUT_WIDTH WIDTH/COMPRESSION_FACTOR
#define OUTPUT_HEIGHT HEIGHT/COMPRESSION_FACTOR

// Define input and output image arrays
unsigned char inputImage[WIDTH][HEIGHT];
unsigned char outputImage[OUTPUT_WIDTH][OUTPUT_HEIGHT];

// Function to compress image
void compressImage() {
    int x, y, i, j, sum;
    for (x = 0; x < WIDTH; x += COMPRESSION_FACTOR) {
        for (y = 0; y < HEIGHT; y += COMPRESSION_FACTOR) {
            sum = 0;
            for (i = 0; i < COMPRESSION_FACTOR; i++) {
                for (j = 0; j < COMPRESSION_FACTOR; j++) {
                    sum += inputImage[x + i][y + j];
                }
            }
            outputImage[x/COMPRESSION_FACTOR][y/COMPRESSION_FACTOR] = sum / (COMPRESSION_FACTOR * COMPRESSION_FACTOR);
        }
    }
}

int main() {
    // Generate random image
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            inputImage[x][y] = rand() % 256;
        }
    }

    // Compress image
    compressImage();

    // Print output image
    for (x = 0; x < OUTPUT_WIDTH; x++) {
        for (y = 0; y < OUTPUT_HEIGHT; y++) {
            printf("%d ", outputImage[x][y]);
        }
        printf("\n");
    }

    return 0;
}