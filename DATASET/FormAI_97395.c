//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50
#define GRAYSCALE_DEPTH 256

// Function to convert pixel to ASCII character based on grayscale intensity
char pixelToAscii(int pixel) {
    const char mapping[] = " .:-=+*#%@";
    int range = GRAYSCALE_DEPTH / (sizeof(mapping) - 1);
    return mapping[pixel / range];
}

// Function to load an image from file into a 2D array of grayscale intensities
void loadGrayscaleImage(const char *filename, int image[HEIGHT][WIDTH]) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file); // discard header

    unsigned char pixel[3];
    for (int row = HEIGHT - 1; row >= 0; row--) {
        for (int col = 0; col < WIDTH; col++) {
            fread(pixel, sizeof(unsigned char), 3, file);
            int intensity = (pixel[0] + pixel[1] + pixel[2]) / 3;
            image[row][col] = intensity;
        }
        // discard row padding
        int padding = (4 - (WIDTH * 3) % 4) % 4;
        unsigned char junk[padding];
        fread(junk, sizeof(unsigned char), padding, file);
    }

    fclose(file);
}

// Function to print the image as ASCII art
void printAsciiImage(int image[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            int pixel = image[row][col];
            char ascii = pixelToAscii(pixel);
            putchar(ascii);
        }
        putchar('\n');
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    loadGrayscaleImage("image.bmp", image);
    printAsciiImage(image);
    return 0;
}