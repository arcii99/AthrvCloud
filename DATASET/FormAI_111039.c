//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art
void imageToAscii(char* path, int width, int height, char* characters) {
    // Open the image file
    FILE* f = fopen(path, "rb");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Allocate memory for the image data
    unsigned char* imageData = (unsigned char*) malloc(width * height * 3);
    if (imageData == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // Read the image data
    fread(imageData, 1, width * height * 3, f);
    fclose(f);

    // Convert the image data to ASCII characters
    char* asciiData = (char*) malloc(width * height + height + 1);
    if (asciiData == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Convert RGB color to grayscale
            int r = imageData[index];
            int g = imageData[index + 1];
            int b = imageData[index + 2];
            int avg = (r + g + b) / 3;

            // Find the ASCII character that best represents the grayscale value
            int charIndex = (avg * strlen(characters)) / 255;
            asciiData[i * (width + 1) + j] = characters[charIndex];
            index += 3;
        }
        asciiData[i * (width + 1) + width] = '\n';
    }
    asciiData[(height * (width + 1))] = '\0';

    // Print the ASCII art to the console
    printf("%s", asciiData);

    // Free memory
    free(imageData);
    free(asciiData);
}

// Main function
int main() {
    // Set the path to the image file
    char* path = "image.png";

    // Set the width and height of the image
    int width = 80;
    int height = 40;

    // Set the ASCII characters to use
    char* characters = "@B%8WM#*oahkbdpqwmZO0QLCJYXzcvnxs$_-+~<>:,. ";
    
    // Call the function to convert the image to ASCII art
    imageToAscii(path, width, height, characters);
    return 0;
}