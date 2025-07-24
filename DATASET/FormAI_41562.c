//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Function to create random pixel art
void createPixelArt(int pixels[WIDTH][HEIGHT], int numColors) {
    // Seed the random number generator
    srand(time(NULL));
    // Loop through each pixel and assign a random color
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            pixels[i][j] = rand() % numColors;
        }
    }
}

// Function to print the pixel art
void printPixelArt(int pixels[WIDTH][HEIGHT]) {
    // Loop through each pixel and print its color
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define the number of colors and create the pixel art
    int numColors = 5;
    int pixels[WIDTH][HEIGHT];
    createPixelArt(pixels, numColors);
    // Print the pixel art
    printf("Generated Pixel Art:\n");
    printPixelArt(pixels);

    return 0;
}