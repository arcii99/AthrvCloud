//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum dimensions of the art image
#define MAX_HEIGHT 25
#define MAX_WIDTH 80

// Define the ASCII characters to use for different grayscale values
const char ASCII_CHARS[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Define the number of ASCII characters to use
const int NUM_ASCII_CHARS = sizeof(ASCII_CHARS) / sizeof(ASCII_CHARS[0]);

// Define a function to convert a grayscale value to an ASCII character
char grayscale_to_ascii(int grayscale_value) {
    // Calculate the index of the ASCII character to use
    int index = (grayscale_value * (NUM_ASCII_CHARS - 1)) / 255;
    // Return the ASCII character
    return ASCII_CHARS[index];
}

int main(int argc, char *argv[]) {
    // Check that the correct number of command line arguments were provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Attempt to open the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (!image_file) {
        fprintf(stderr, "Error: Failed to open image file\n");
        exit(EXIT_FAILURE);
    }
    // Read the image dimensions from the file header
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, image_file) != 54) {
        fprintf(stderr, "Error: Failed to read image header\n");
        fclose(image_file);
        exit(EXIT_FAILURE);
    }
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    // Check that the image dimensions are within the maximum allowed
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image dimensions are too large\n");
        fclose(image_file);
        exit(EXIT_FAILURE);
    }
    // Calculate the total number of pixels in the image
    int total_pixels = width * height;
    // Allocate memory for the pixel values
    unsigned char *pixels = malloc(total_pixels);
    if (!pixels) {
        fprintf(stderr, "Error: Failed to allocate memory for pixel values\n");
        fclose(image_file);
        exit(EXIT_FAILURE);
    }
    // Read the pixel values from the image file
    if (fread(pixels, sizeof(unsigned char), total_pixels, image_file) != total_pixels) {
        fprintf(stderr, "Error: Failed to read pixel values\n");
        fclose(image_file);
        free(pixels);
        exit(EXIT_FAILURE);
    }
    // Close the image file
    fclose(image_file);
    // Print the ASCII art
    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the grayscale value of the current pixel
            int grayscale_value = *(pixels + y * width + x);
            // Convert the grayscale value to an ASCII character and print it
            printf("%c", grayscale_to_ascii(grayscale_value));
        }
        printf("\n");
    }
    printf("\n");
    // Free the allocated memory
    free(pixels);
    // Exit the program
    exit(EXIT_SUCCESS);
}