//FormAI DATASET v1.0 Category: Image compression ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define image width and height
#define WIDTH 640
#define HEIGHT 480

// Define DCT block size
#define BLOCK_SIZE 8

// Define pi constant
#define PI 3.14159265359

// Function to calculate DCT
double DCT(int u, int v, double block[BLOCK_SIZE][BLOCK_SIZE]) {
    double sum = 0.0;

    for (int x = 0; x < BLOCK_SIZE; x++) {
        for (int y = 0; y < BLOCK_SIZE; y++) {
            sum += block[x][y] * cos((2 * x + 1) * u * PI / 16) * cos((2 * y + 1) * v * PI / 16);
        }
    }

    double alpha_u = 1.0, alpha_v = 1.0;
    if (u == 0) alpha_u = 1 / sqrt(2.0);
    if (v == 0) alpha_v = 1 / sqrt(2.0);

    return 0.25 * alpha_u * alpha_v * sum;
}

// Function to compress image using DCT
void compressImage(double image[HEIGHT][WIDTH]) {
    // Allocate memory for compressed image
    double compressed[HEIGHT][WIDTH];

    // Loop through image blocks
    for (int i = 0; i < HEIGHT; i += BLOCK_SIZE) {
        for (int j = 0; j < WIDTH; j += BLOCK_SIZE) {
            // Copy block into temporary array
            double block[BLOCK_SIZE][BLOCK_SIZE];
            for (int x = 0; x < BLOCK_SIZE; x++) {
                for (int y = 0; y < BLOCK_SIZE; y++) {
                    block[x][y] = image[i + x][j + y];
                }
            }

            // Calculate DCT coefficients for block
            double coefficients[BLOCK_SIZE][BLOCK_SIZE];
            for (int u = 0; u < BLOCK_SIZE; u++) {
                for (int v = 0; v < BLOCK_SIZE; v++) {
                    coefficients[u][v] = DCT(u, v, block);
                }
            }

            // Copy DCT coefficients back into compressed image
            for (int x = 0; x < BLOCK_SIZE; x++) {
                for (int y = 0; y < BLOCK_SIZE; y++) {
                    compressed[i + x][j + y] = coefficients[x][y];
                }
            }
        }
    }

    // Print original and compressed image sizes
    printf("Original image size: %.2f MB\n", (double) WIDTH * HEIGHT * sizeof(double) / 1024 / 1024);
    printf("Compressed image size: %.2f MB\n", (double) WIDTH * HEIGHT * sizeof(double) / 1024 / 1024);

    // Free memory
    free(compressed);
}

int main() {
    // Allocate memory for input image
    double image[HEIGHT][WIDTH];

    // Read image data from file
    FILE *fp = fopen("input_image.bin", "rb");
    fread(image, sizeof(double), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Compress image
    compressImage(image);

    // Return success
    return 0;
}