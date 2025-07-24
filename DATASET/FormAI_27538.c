//FormAI DATASET v1.0 Category: Image Editor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for image dimensions
#define WIDTH 640
#define HEIGHT 480

// Define constants for pixel values
#define MIN_VAL 0
#define MAX_VAL 255

// Define function to assign random pixel values to image
void randomize_pixels(int pixels[HEIGHT][WIDTH]) {
    srand(time(NULL)); // Set seed for random number generator
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int rand_val = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL; // Generate random pixel value
            pixels[i][j] = rand_val; // Assign pixel value to image
        }
    }
}

// Define function to invert colors of image
void invert_colors(int pixels[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = MAX_VAL - pixels[i][j]; // Invert pixel value
        }
    }
}

// Define function to apply grayscale filter to image
void grayscale(int pixels[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int avg_val = (pixels[i][j] + pixels[i+1][j] + pixels[i][j+1] + pixels[i+1][j+1]) / 4; // Calculate average pixel value for each 2x2 block
            pixels[i][j] = avg_val; // Assign average pixel value to image
            pixels[i+1][j] = avg_val;
            pixels[i][j+1] = avg_val;
            pixels[i+1][j+1] = avg_val;
        }
    }
}

int main() {
    int pixels[HEIGHT][WIDTH];

    // Randomize pixel values in image
    randomize_pixels(pixels);

    // Invert colors in image
    invert_colors(pixels);

    // Apply grayscale filter to image
    grayscale(pixels);

    // Print out image dimensions and pixel values
    printf("Image dimensions: %dx%d\n", WIDTH, HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}