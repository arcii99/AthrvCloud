//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a paranoid C Pixel Art Generator
// It generates unique pixel art every time through randomization
// The paranoia comes from its use of constant reseeding of the random number generator,
// as well as heavy use of pointer manipulation and memory allocation

int main() {
    srand(time(NULL));  // Seed the random number generator

    int width = 10;  // Width of the pixel art
    int height = 10; // Height of the pixel art

    char **pixels = (char **) malloc(sizeof(char *) * height); // Allocate memory for the pixel array

    for (int i = 0; i < height; i++) {
        pixels[i] = (char *) malloc(sizeof(char) * width);  // Allocate memory for the row
    }

    // Populate the pixel array with random characters
    // This is where the paranoia comes in, as the random number generator is reset every time
    // and the pointers to the row and columns are manipulated heavily
    for (int row = 0; row < height; row++) {
        srand(row * time(NULL));  // Reseed the random number generator

        for (int col = 0; col < width; col++) {
            char pixel = (rand() % 26) + 'A';  // Get a random uppercase letter
            *(pixels[row] + col) = pixel;      // Set the pixel value using pointer arithmetic
        }
    }

    // Print the Pixel Art
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%c ", *(pixels[row] + col));  // Print the pixel value using pointer arithmetic
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}