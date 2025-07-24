//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int getGrayValue(char red, char green, char blue);
char getAsciiChar(int grayVal);

int main(int argc, char *argv[]) {

    // Check if an image file was passed as an argument
    if (argc < 2) {
        printf("Please input an image file.\nUsage: ./ascii_art image.jpg\n");
        exit(1);
    }

    // Open the image file
    FILE *imageFile = fopen(argv[1], "rb");
    if (imageFile == NULL) {
        printf("Failed to open image file.\n");
        exit(1);
    }

    // Read the image header to get the width and height
    char header[54];
    fread(header, sizeof(char), 54, imageFile);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the size of the image in bytes
    int imageSize = width * height * 3;

    // Allocate memory for the image data
    char *imageData = (char*)malloc(imageSize);
    if (imageData == NULL) {
        printf("Failed to allocate memory for image data.\n");
        exit(1);
    }

    // Read the image data
    fread(imageData, sizeof(char), imageSize, imageFile);

    // Close the image file
    fclose(imageFile);

    // Convert the image to ASCII art
    int row, col;
    char asciiArt[height][width+1];
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {

            // Get the RGB values of the current pixel
            char red = imageData[row*width*3 + col*3];
            char green = imageData[row*width*3 + col*3 + 1];
            char blue = imageData[row*width*3 + col*3 + 2];

            // Convert the RGB values to a single grayscale value
            int grayVal = getGrayValue(red, green, blue);

            // Map the grayscale value to an ASCII character
            char asciiChar = getAsciiChar(grayVal);

            // Store the ASCII character in the two-dimensional array
            asciiArt[row][col] = asciiChar;
        }

        // Add a null terminator to the end of each row
        asciiArt[row][width] = '\0';
    }

    // Print out the ASCII art
    for (row = 0; row < height; row++) {
        printf("%s\n", asciiArt[row]);
    }

    // Free memory used for the image data
    free(imageData);

    return 0;
}

// Function to convert RGB values to grayscale
int getGrayValue(char red, char green, char blue) {
    return 0.21*red + 0.72*green + 0.07*blue;
}

// Function to map a grayscale value to an ASCII character
char getAsciiChar(int grayVal) {
    if (grayVal >= 230) {
        return ' ';
    } else if (grayVal >= 200) {
        return '-';
    } else if (grayVal >= 180) {
        return '*';
    } else if (grayVal >= 160) {
        return '/';
    } else if (grayVal >= 130) {
        return '!';
    } else if (grayVal >= 100) {
        return '+';
    } else if (grayVal >= 70) {
        return '=';
    } else if (grayVal >= 50) {
        return '$';
    } else {
        return '@';
    }
}