//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image and the ASCII art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_WIDTH 80
#define ASCII_HEIGHT 80

// Function to convert a pixel to ASCII character
char getASCIIChar(int pixelValue) {
    // Define ASCII characters ordered from darkest to lightest, to match pixel values
    char asciiChars[] = "@#8&o:;^-,. ";
    int numChars = strlen(asciiChars);

    // Calculate the mapping from pixel value to ASCII character index
    int charIndex = (pixelValue * (numChars - 1)) / 255;
    return asciiChars[charIndex];
}

int main(int argc, char** argv) {
    // Initialize image and ASCII art arrays
    int image[MAX_WIDTH][MAX_HEIGHT];
    char asciiArt[ASCII_WIDTH][ASCII_HEIGHT];

    // Read input image file
    FILE* inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Read image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, inputFile);
    fread(&height, sizeof(int), 1, inputFile);

    // Read image pixel values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixelValue;
            fread(&pixelValue, sizeof(int), 1, inputFile);
            // Store pixel value in image array
            image[x][y] = pixelValue;
        }
    }

    // Close input file
    fclose(inputFile);

    // Scale image down to ASCII art size
    double scaleX = (double)width / ASCII_WIDTH;
    double scaleY = (double)height / ASCII_HEIGHT;

    // Loop through ASCII art array
    for (int y = 0; y < ASCII_HEIGHT; y++) {
        for (int x = 0; x < ASCII_WIDTH; x++) {
            // Map ASCII art position to corresponding region in image
            double imageX = x * scaleX;
            double imageY = y * scaleY;
            // Get nearest integer pixel coordinates
            int pixelX = (int)(imageX + 0.5);
            int pixelY = (int)(imageY + 0.5);
            // Get pixel value at rounded coordinates
            int pixelValue = image[pixelX][pixelY];
            // Convert pixel to ASCII character and store in ASCII art array
            asciiArt[x][y] = getASCIIChar(pixelValue);
        }
    }

    // Write ASCII art to output file
    FILE* outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        printf("Error: Could not open output file\n");
        return 1;
    }
    for (int y = 0; y < ASCII_HEIGHT; y++) {
        for (int x = 0; x < ASCII_WIDTH; x++) {
            fputc(asciiArt[x][y], outputFile);
        }
        fputc('\n', outputFile);
    }
    fclose(outputFile);

    printf("ASCII art conversion complete!\n");
    return 0;
}