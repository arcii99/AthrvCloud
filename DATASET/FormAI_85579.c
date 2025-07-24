//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_PIXEL_VALUE 255

// This function calculates the brightness value of the pixel and returns a corresponding character
char brightnessToChar(int brightness) {
    if (brightness < 25) {
        return '@';
    } else if (brightness < 50) {
        return '#';
    } else if (brightness < 75) {
        return '8';
    } else if (brightness < 100) {
        return '&';
    } else if (brightness < 125) {
        return 'o';
    } else if (brightness < 150) {
        return ':';
    } else if (brightness < 175) {
        return '*';
    } else if (brightness < 200) {
        return '.';
    } else if (brightness < 225) {
        return ' ';
    } else {
        return ' ';
    }
}

int main(void) {
    FILE* imageFile = fopen("input.pgm", "r"); // Open the image file
    if (imageFile == NULL) {
        perror("Failed to read image file");
        return EXIT_FAILURE;
    }

    // Read the image header
    char magicNumber[3];
    int width, height, max_value;
    fscanf(imageFile, "%s %d %d %d", magicNumber, &width, &height, &max_value);

    // Check if the image is a grayscale PGM file
    if (strcmp(magicNumber, "P2") != 0 || max_value != MAX_PIXEL_VALUE) {
        fclose(imageFile);
        fprintf(stderr, "Invalid image format\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the pixel array
    int pixelArray[width][height];
    memset(pixelArray, 0, sizeof(pixelArray));

    // Read the pixel values into the array
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int pixelValue;
            fscanf(imageFile, "%d", &pixelValue);
            pixelArray[col][row] = pixelValue;
        }
    }

    fclose(imageFile); // Close the image file

    // Open the output file
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        return EXIT_FAILURE;
    }

    // Write the ASCII art to the output file
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int brightness = pixelArray[col][row] * WIDTH / MAX_PIXEL_VALUE; // Calculate the brightness of the pixel
            fprintf(outputFile, "%c", brightnessToChar(brightness));
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile); // Close the output file

    printf("Conversion completed successfully!\n");
    return EXIT_SUCCESS;
}