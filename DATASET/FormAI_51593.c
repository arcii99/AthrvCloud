//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method to map the RGB values of the image to a grayscale value
char grayScale(int red, int green, int blue) {
    return (char)(0.2126 * red + 0.7152 * green + 0.0722 * blue);
}

int main() {
    char *ascii = strdup(" .,:;i1tfLCG08@");
    int asciiLen = strlen(ascii);

    // Open the image file
    FILE *fp = fopen("image.jpg", "rb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the image header (the first 54 bytes)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Extract the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the image size in bytes
    int imageSize = width * height * 3;

    // Allocate memory for the image data
    unsigned char *imageData = malloc(sizeof(unsigned char) * imageSize);

    // Read the image data
    fread(imageData, sizeof(unsigned char), imageSize, fp);

    // Close the file handle
    fclose(fp);

    // Loop through every pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Map the RGB values of the pixel to a grayscale value
            char grayValue = grayScale(imageData[(i * width + j) * 3], imageData[(i * width + j) * 3 + 1], imageData[(i * width + j) * 3 + 2]);

            // Determine the ASCII character to use based on the grayscale value
            int asciiIdx = grayValue * (asciiLen - 1) / 255;

            // Print the ASCII character
            printf("%c", ascii[asciiIdx]);
        }
        // Move to the next line
        printf("\n");
    }

    // Free the memory allocated for the image data
    free(imageData);

    return 0;
}