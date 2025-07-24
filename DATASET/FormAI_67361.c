//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

// A struct to represent a pixel
typedef struct pixel {
    unsigned char r; // Red
    unsigned char g; // Green
    unsigned char b; // Blue
} Pixel;

// Set a pixel at (x, y) with the given color values
void setPixel(Pixel image[WIDTH][HEIGHT], int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    image[y][x].r = r;
    image[y][x].g = g;
    image[y][x].b = b;
}

// Print the pixel art image
void printImage(Pixel image[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("(%d,%d,%d) ", image[y][x].r, image[y][x].g, image[y][x].b);
        }
        printf("\n");
    }
}

int main() {
    Pixel image[WIDTH][HEIGHT]; // Initialize an empty pixel art image
    
    // Generate the pixel art image
    setPixel(image, 3, 2, 255, 0, 0); // Set a red pixel at (3,2)
    setPixel(image, 5, 7, 0, 255, 0); // Set a green pixel at (5,7)
    setPixel(image, 8, 5, 0, 0, 255); // Set a blue pixel at (8,5)
    
    // Print the pixel art image
    printImage(image);
    
    return 0;
}